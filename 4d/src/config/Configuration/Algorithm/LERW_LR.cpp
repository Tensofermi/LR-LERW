#include "../Configuration.hpp"

// Generate a random direction on a unit sphere
void Configuration::randSphere(std::vector<double>& dx)
{
    const int dx_size = dx.size();
    const double epsilon = 1e-16;

    // if (dx_size == 1)
    // {
    //     dx[0] = (rn.getRandomDouble() > 0.5) ? 1.0 : -1.0;
    //     return;
    // }
    // if (dx_size == 2)
    // {
    //     // 2D: sample angle theta uniformly from [0, 2pi)
    //     double theta = 2.0 * M_PI * rn.getRandomDouble();
    //     dx[0] = cos(theta);
    //     dx[1] = sin(theta);
    //     return;
    // }
    // if (dx_size == 3)
    // {
    //     // 3D: sample phi in [0, 2pi), costheta in [-1, 1]
    //     double phi = 2.0 * M_PI * rn.getRandomDouble();
    //     double costheta = 2.0 * rn.getRandomDouble() - 1.0;
    //     double sintheta = sqrt(1.0 - costheta * costheta);
    //     dx[0] = sintheta * cos(phi);
    //     dx[1] = sintheta * sin(phi);
    //     dx[2] = costheta;
    //     return;
    // }

    // General case: Gaussian sampling and normalization
    double lengthSquared;
    do {
        lengthSquared = 0.0;
        for (int i_N = 0; i_N < dx_size; ++i_N) {
            dx[i_N] = rn.getGaussian();
            lengthSquared += dx[i_N] * dx[i_N];
        }
    } while (lengthSquared < epsilon);

    const double length = std::sqrt(lengthSquared);
    for (int i_N = 0; i_N < dx_size; ++i_N) {
        dx[i_N] /= length;
    }
}



void Configuration::LERW_LR()
{
    const size_t coord_dim = string_head.size();
    Dim = static_cast<int>(coord_dim);
    std::vector<double> dx(coord_dim, 0.0);
    double r;
    double r0 = 1.0; 
    auto maxNorm = [](const std::array<int, 4>& coord) {
        int max_dist = 0;
        for (int x : coord) {
            max_dist = std::max(max_dist, std::abs(x));
        }
        return max_dist;
    };

    //_______________________________________________________________________________
    const std::vector<int> thresholds = {8, 16, 32, 64, 128, 256, 512,
                                     1024, 2048, 4096, 8192, 16384, 32768};

    const std::vector<int> len_indices = {
        para.i_Len_8, para.i_Len_16, para.i_Len_32, para.i_Len_64, para.i_Len_128,
        para.i_Len_256, para.i_Len_512, para.i_Len_1024, para.i_Len_2048,
        para.i_Len_4096, para.i_Len_8192, para.i_Len_16384, para.i_Len_32768};

    std::vector<bool> flags(thresholds.size(), false);        
    //_______________________________________________________________________________


    length_string = 0;
    complete_length_string = 0; // Reset the complete length of the random walk
    string.clear();
    visited.clear();

    string_head = {0, 0, 0, 0}; // Initialize the starting point of the random walk
    string.push_back(string_head); // Start at the origin (0, 0)    
    visited.insert(string_head);

    // std::cout << "Start LERW" << std::endl;
    
    while (true)
    {
        //_________________________________________________________________________
        // Step 1: propose a new position based on the current string head (LR case)
        //_________________________________________________________________________
        
        // randomly choose distance
        r = rn.getRandomDouble();
        r = (r == 0.0) ? 1.0 : r; // Ensure r is not zero
        r = pow(r, -1.0 / Sigma);

        // randomly choose direction
        randSphere(dx);

        // apply for lattice
        for (size_t i = 0; i < dx.size(); ++i)
        {
            dx[i] = (int)floor(r0 * r * dx[i] + 0.5); // Move in x direction
        }

        // propose this new position
        for (size_t i = 0; i < string_head.size(); ++i) {
            string_head[i] += dx[i];
        }
        
        // obtain the max length
        const int max_dist_ = maxNorm(string_head);

        if(max_dist_ >= L_max) {            
            for (size_t i = 0; i < thresholds.size(); ++i) {
                if (!flags[i]) {
                flags[i] = true;
                obs.Ob[len_indices[i]] = length_string;

                if (L_max == thresholds[i]) {
                    return;
                    }
                }
            }
        }        

        //_________________________________________________________________________
        // Step 2: Check if the new position has been visited before
        //_________________________________________________________________________
        if (visited.find(string_head) != visited.end())
        {
             // If the position has been visited, remove the last position from the string
            while (string_head != string[length_string])
            {
                string.pop_back();
                visited.erase(string[length_string]);
                length_string--;
            }
            // Reset the string head to the last position
            if (string_head != string[length_string]) 
            {
                std::cout << "Error: string_head != string[length_string]" << std::endl;
                break;
            }
        }
        else
        {
            // If the position is new, mark it as visited
            string.push_back(string_head); // Store the new position in the string
            length_string++;
            visited.insert(string_head);
        }

        complete_length_string++; // Increment the total length of the random walk

        //_________________________________________________________________________
        // Step 3: Check if the length of the random walk has reached the maximum length
        //_________________________________________________________________________
        const int max_dist = maxNorm(string_head);

        for (size_t i = 0; i < thresholds.size(); ++i) {
            if (!flags[i] && max_dist >= thresholds[i]) {
            flags[i] = true;
            obs.Ob[len_indices[i]] = length_string;

            if (L_max == thresholds[i]) {
                return;
                }
           }
        }

    }
    
    // std::cout << "End LERW" << std::endl;
}

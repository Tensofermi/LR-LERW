#include "../Configuration.hpp"
#include "BitArray.hpp"

void Configuration::LERW_LR()
{
    double u, v, w, dx, dy;
    double factor;
    double r0 = 0.5 * sqrt(2.0);  // to reach the NN case as sigma -> infinity

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
    visited_bit.resetAll(); // Reset the BitArray to track visited positions

    string_head = {0, 0}; // Initialize the starting point of the random walk
    string.push_back(string_head); // Start at the origin (0, 0)    
    visited_bit.set(coordToIndex(string_head[0], string_head[1], L_max + 1)); // Mark the starting point as visited in the BitArray
    
    // std::cout << "Start LERW" << std::endl;
    
    while (true)
    {   
        //_________________________________________________________________________
        // Step 1: propose a new position based on the current string head (NN case)
        //_________________________________________________________________________
        // int dir_index = rn.getRandomNum(4); // Randomly choose a direction: 0, 1, 2, or 3
    
        // if (dir_index == 0) // Move right
        // {
        //     string_head[0] += 1; // Move right in x direction
        // }
        // else if (dir_index == 2) // Move left
        // {
        //     string_head[0] -= 1; // Move left in x direction
        // }
        // else if (dir_index == 1) // Move up
        // {
        //     string_head[1] += 1; // Move up in y direction
        // }
        // else if (dir_index == 3) // Move down
        // {
        //     string_head[1] -= 1; // Move down in y direction
        // }

        //_________________________________________________________________________
        // Step 1: propose a new position based on the current string head (LR case)
        //_________________________________________________________________________
        while (true)
        {
            u = rn.getRandomDouble();
            v = rn.getRandomDouble(); 
            u = (u == 0.0) ? 1.0 : u; // Ensure u, v are not zero
            v = (v == 0.0) ? 1.0 : v;
            w = u * u + v * v;
            if(w < 1.0) break;      
        }

        factor = 1.0 / pow(w, 0.5 + 1.0 / Sigma);

        dx = (int)floor(r0 * u * factor + 0.5); // Move in x direction
        dy = (int)floor(r0 * v * factor + 0.5); // Move in y direction

        if(rn.getRandomDouble() < 0.5) dx = -dx; // Randomly flip x direction
        if(rn.getRandomDouble() < 0.5) dy = -dy; // Randomly flip y direction

        string_head[0] += dx;
        string_head[1] += dy;

        // std::cout<<" Proposed step: ("<<dx<<","<<dy<<") to ("<<string_head[0]<<","<<string_head[1]<<")"<<std::endl;

        // check if out of region
        double max_dist_ = std::max(std::abs((double)string_head[0]), std::abs((double)string_head[1]));
        
        // std::cout<<"L_max = "<<L_max<<",  max_dist_ = "<<max_dist_<<std::endl;

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
        if (visited_bit.test(coordToIndex(string_head[0], string_head[1], L_max + 1)))
        {
            // If the position has been visited, remove the last position from the string
            while (string_head != string[length_string])
            {
                string.pop_back();
                visited_bit.reset(coordToIndex(string[length_string][0], string[length_string][1], L_max + 1)); // Mark the position as unvisited
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
            visited_bit.set(coordToIndex(string_head[0], string_head[1], L_max + 1));
        }

        complete_length_string++; // Increment the total length of the random walk

        //_________________________________________________________________________
        // Step 3: Check if the length of the random walk has reached the maximum length
        //_________________________________________________________________________
        double max_dist = std::max(std::abs(string_head[0]), std::abs(string_head[1]));

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

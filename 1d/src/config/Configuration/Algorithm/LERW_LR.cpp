#include "../Configuration.hpp"
#include "BitArray.hpp"

void Configuration::LERW_LR()
{
    double u, dx;
    double r0 = 0.5;  // to reach the NN case as sigma -> infinity

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

    string_head = 0; // Initialize the starting point of the random walk
    string.push_back(string_head); // Start at the origin (0, 0)    
    
    visited_bit.set(coordToIndex(string_head, L_max + 1)); // Mark the starting point as visited in the BitArray
    
    // std::cout << "Start LERW" << std::endl;
    
    while (true)
    {   
        //_________________________________________________________________________
        // Step 1: propose a new position based on the current string head (NN case)
        //_________________________________________________________________________
        // int dir_index = rn.getRandomNum(2); // Randomly choose a direction: 0, 1
    
        // //       
        // // 1 ----+---- 0 [x]
        // //
    
        // if (dir_index == 0) // Move right
        // {
        //     string_head += 1; // Move right in x direction
        // }
        // else if (dir_index == 1) // Move up
        // {
        //     string_head -= 1; // Move up in y direction
        // }

        //_________________________________________________________________________
        // Step 1: propose a new position based on the current string head (LR case)
        //_________________________________________________________________________

        u = rn.getRandomDouble();
        u = (u == 0.0) ? 1.0 : u; // Ensure u is not zero
        // std::cout<<"u = "<<u<<"  ";
        u = pow(u, -1.0 / Sigma);
        dx = (int)floor(r0 * u + 0.5); // Move in x direction

        if(rn.getRandomDouble() < 0.5) dx = -dx; // Randomly flip x direction

        
        string_head += dx;
        
        // std::cout<< string_head << "   "<< dx << std::endl;

        // check if out of region
        double max_dist_ = std::abs((double)string_head);

        
        if(max_dist_ >= L_max) {            
            // std::cout<<max_dist_<<std::endl;
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
        if (visited_bit.test(coordToIndex(string_head, L_max + 1)))
        {
            // If the position has been visited, remove the last position from the string
            while (string_head != string[length_string])
            {
                string.pop_back();
                visited_bit.reset(coordToIndex(string[length_string], L_max + 1)); // Mark the position as unvisited
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
            visited_bit.set(coordToIndex(string_head, L_max + 1));
        }

        complete_length_string++; // Increment the total length of the random walk

        //_________________________________________________________________________
        // Step 3: Check if the length of the random walk has reached the maximum length
        //_________________________________________________________________________
        int max_dist = std::abs(string_head);

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

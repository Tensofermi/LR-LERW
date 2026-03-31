#include "../Configuration.hpp"

void Configuration::RandomWalk()
{
    bool flag_8 = false;
    bool flag_16 = false;
    bool flag_32 = false;
    bool flag_64 = false;
    bool flag_128 = false;  
    bool flag_256 = false;
    bool flag_512 = false;
    bool flag_1024 = false;
    bool flag_2048 = false;
    bool flag_4096 = false;
    bool flag_8192 = false;
    bool flag_16384 = false;
    bool flag_32768 = false;

    length_string = 0;
    string.clear();

    string_head = {0, 0}; // Initialize the starting point of the random walk
    string.push_back(string_head); // Start at the origin (0, 0)    

    while (true)
    {
        int dir_index = rn.getRandomNum(4); // Randomly choose a direction: 0, 1, 2, or 3
    
        //      [y]
        //       1
        //       |
        //       |
        // 2 ----+---- 0 [x]
        //       |
        //       |
        //       3
        //     [-y]
    
        if (dir_index == 0) // Move right
        {
            string_head[0] += 1; // Move right in x direction
        }
        else if (dir_index == 2) // Move left
        {
            string_head[0] -= 1; // Move left in x direction
        }
        else if (dir_index == 1) // Move up
        {
            string_head[1] += 1; // Move up in y direction
        }
        else if (dir_index == 3) // Move down
        {
            string_head[1] -= 1; // Move down in y direction
        }

        string.push_back(string_head); // Store the new position in the string
        length_string++;

// Check if the length of the random walk has reached the maximum length
        // 8
        if((abs(string_head[0]) >= 8 || abs(string_head[1]) >= 8 ) && flag_8 == false)
        {
            flag_8 = true;
            obs.Ob[para.i_Len_8] = length_string;
            obs.Ob[para.i_Lop_8] = 0.0; // Store the total length of the random walk
        }
        // 16
        if((abs(string_head[0]) >= 16 || abs(string_head[1]) >= 16 ) && flag_16 == false)
        {
            flag_16 = true;
            obs.Ob[para.i_Len_16] = length_string;
            obs.Ob[para.i_Lop_16] = 0.0;
        }
        // 32
        if((abs(string_head[0]) >= 32 || abs(string_head[1]) >= 32 ) && flag_32 == false)
        {
            flag_32 = true;
            obs.Ob[para.i_Len_32] = length_string;
            obs.Ob[para.i_Lop_32] = 0.0;
        }
        // 64
        if((abs(string_head[0]) >= 64 || abs(string_head[1]) >= 64 ) && flag_64 == false)
        {
            flag_64 = true;
            obs.Ob[para.i_Len_64] = length_string;
            obs.Ob[para.i_Lop_64] = 0.0;
        }
        // 128
        if((abs(string_head[0]) >= 128 || abs(string_head[1]) >= 128 ) && flag_128 == false)
        {
            flag_128 = true;
            obs.Ob[para.i_Len_128] = length_string;
            obs.Ob[para.i_Lop_128] = 0.0;
        }
        // 256
        if((abs(string_head[0]) >= 256 || abs(string_head[1]) >= 256 ) && flag_256 == false)
        {
            flag_256 = true;
            obs.Ob[para.i_Len_256] = length_string; 
            obs.Ob[para.i_Lop_256] = 0.0;
        }
        // 512
        if((abs(string_head[0]) >= 512 || abs(string_head[1]) >= 512 ) && flag_512 == false)
        {
            flag_512 = true;
            obs.Ob[para.i_Len_512] = length_string;
            obs.Ob[para.i_Lop_512] = 0.0;
        }
        // 1024
        if((abs(string_head[0]) >= 1024 || abs(string_head[1]) >= 1024 ) && flag_1024 == false)
        {
            flag_1024 = true;
            obs.Ob[para.i_Len_1024] = length_string;
            obs.Ob[para.i_Lop_1024] = 0.0;
            if(L_max == 1024)
            {
                break;
            }
        }
        // 2048
        if((abs(string_head[0]) >= 2048 || abs(string_head[1]) >= 2048 ) && flag_2048 == false)
        {
            flag_2048 = true;
            obs.Ob[para.i_Len_2048] = length_string;
            obs.Ob[para.i_Lop_2048] = 0.0;
            if(L_max == 2048)
            {
                break;
            }
        }
        // 4096
        if((abs(string_head[0]) >= 4096 || abs(string_head[1]) >= 4096 ) && flag_4096 == false)
        {
            flag_4096 = true;
            obs.Ob[para.i_Len_4096] = length_string;
            obs.Ob[para.i_Lop_4096] = 0.0;
            if(L_max == 4096)
            {
                break;
            }
        }
        // 8192
        if((abs(string_head[0]) >= 8192 || abs(string_head[1]) >= 8192 ) && flag_8192 == false)
        {
            flag_8192 = true;
            obs.Ob[para.i_Len_8192] = length_string;
            obs.Ob[para.i_Lop_8192] = 0.0;
            if(L_max == 8192)
            {
                break;
            }
        }        
        // 16384
        if((abs(string_head[0]) >= 16384 || abs(string_head[1]) >= 16384 ) && flag_16384 == false)
        {
            flag_16384 = true;
            obs.Ob[para.i_Len_16384] = length_string;
            obs.Ob[para.i_Lop_16384] = 0.0;
            if(L_max == 16384)
            {
                break;
            }
        }
        // 32768
        if((abs(string_head[0]) >= 32768 || abs(string_head[1]) >= 32768 ) && flag_32768 == false)
        {
            flag_32768 = true;
            obs.Ob[para.i_Len_32768] = length_string;
            obs.Ob[para.i_Lop_32768] = 0.0;
            if(L_max == 32768)
            {
                break;
            }
        }

        // std::cout << "Step " << length_string << ": (" 
        //           << string[length_string][0] << ", " 
        //           << string[length_string][1] << ")\n";

    }
    

}
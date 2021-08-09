//
// Created by hongji yan on 4/3/21.
//
#include "project1.h"

std:: vector<int> Gap_Array3(int s)
{
    std:: vector<unsigned int> gap_s = {  1, 2, 3, 4, 6, 8, 9, 12, 16, 18, 24, 27, 32, 36, 48, 54, 64, 72, 81, 96, 108,
                                          128, 144, 162, 192, 216, 243, 256, 288, 324, 384, 432, 486, 512, 576, 648, 729,
                                          768, 864, 972, 1024, 1152, 1296, 1458, 1536, 1728, 1944, 2048, 2187, 2304, 2592,
                                          2916, 3072, 3456, 3888};
    std:: vector<int> my_gaps;

    for(int i = 0; i < gap_s.size();  i++)
    {
        if (gap_s[i] < s){
            my_gaps.push_back(gap_s[i]);
        }
        else{
            break;
        }
    }

    return my_gaps;
}



void shell_sort3(std::vector<int>& nums){

    int size = nums.size();

    std:: vector<int> my_gaps = Gap_Array3(size);

    int gap_index;

    for(gap_index = my_gaps.size() -1; gap_index >= 0 ; gap_index--) {

        int i = my_gaps[gap_index];

        while (i < size) {

            int j = i;

            while (j >= my_gaps[gap_index] && nums[j] < nums[j - my_gaps[gap_index]]) {

                int temp = nums[j - my_gaps[gap_index]];
                nums[j - my_gaps[gap_index]] = nums[j];
                nums[j] = temp;
                j-= my_gaps[gap_index];

            }
            i++;
        }
    }
}
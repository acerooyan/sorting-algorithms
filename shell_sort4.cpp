//
// Created by hongji yan on 4/3/21.
//
#include "project1.h"

std:: vector<int> Gap_Array4(int s)
{
    std:: vector<long> gap_s = { 1, 5, 19, 41, 109, 209, 505, 929, 2161, 3905, 8929, 16001, 36289, 64769, 146305,
                                 260609, 587521, 1045505, 2354689, 4188161, 9427969, 16764929, 37730305, 67084289,
                                 150958081, 268386305, 603906049, 1073643521, 2415771649, 4294770689, 9663381505, 17179475969};
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



void shell_sort4(std::vector<int>& nums){

    int size = nums.size();

    std:: vector<int> my_gaps = Gap_Array4(size);

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
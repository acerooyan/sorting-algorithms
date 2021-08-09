//
// Created by hongji yan on 4/3/21.
//
#include <iostream>
#include "project1.h"

std:: vector<int> Gap_Array(int s)
{
    std:: vector<unsigned int> gap_s = { 1, 3, 5, 9, 17, 33, 65, 129, 257, 513, 1025, 2049, 4097, 8193, 16385, 32769,
                                         65537, 131073, 262145, 524289, 1048577, 2097153, 4194305, 8388609, 16777217,
                                         33554433, 67108865, 134217729, 268435457, 536870913, 1073741825, 2147483649};
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



void shell_sort2(std::vector<int>& nums){

    int size = nums.size();

    std:: vector<int> my_gaps = Gap_Array(size);

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
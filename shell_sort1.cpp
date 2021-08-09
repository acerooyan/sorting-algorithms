//
// Created by hongji yan on 4/3/21.
//
#include "project1.h"




void shell_sort1(std::vector<int>& nums){

    int size = nums.size();

    int gap;

    for(gap = size /2 ; gap > 0; gap /= 2) {

        int i = gap;
        while (i < size) {

            int j = i;

            while (j >= gap && nums[j] < nums[j - gap]) {

                int temp = nums[j - gap];
                nums[j - gap] = nums[j];
                nums[j] = temp;
                j-= gap;

            }
            i++;
        }
    }
}
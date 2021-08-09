
#include "project1.h"
#include <stdlib.h>
#include "iostream"

void insertion_sort(std::vector<int>& nums){
    int size = nums.size();
    int i = 1;
    while ( i < size )
    {

        int j = i;

        while (j > 0 && nums[j] < nums[j-1])
        {

            int temp = nums[j-1];
            nums[j-1] = nums[j];
            nums[j] = temp;
            j--;

        }
        i++;
    }
}



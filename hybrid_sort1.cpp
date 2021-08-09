//
// Created by hongji yan on 4/3/21.
//
#include "project1.h"
#include "math.h"

std::vector<int> merge_nums1(std::vector<int> l, std::vector<int> r)
{
    int left_size = l.size();
    int right_size = r.size();

    int i = 0; //index counter for left
    int j = 0; // index counter for right

    std::vector<int> sorted_list;

    while (i != left_size && j != right_size)
    {
        if (l[i] <= r[j])
        {
            sorted_list.push_back(l[i]);
            i++;
        }
        else{
            sorted_list.push_back(r[j]);
            j++;
        }
    }

    while (i != left_size){
        sorted_list.push_back(l[i]);
        i++;
    }

    while (j != right_size){
        sorted_list.push_back(r[j]);
        j++;
    }



    return sorted_list;

}


void hybrid_sort1_helper(std::vector<int>& nums, int H){

    if (nums.size() > H)
    {

        std:: vector<int> left = std::vector<int>(nums.begin(), nums.begin() + nums.size()/2);
        std:: vector<int> right = std::vector<int>(nums.begin() + nums.size()/2, nums.end());


        hybrid_sort1_helper(left,H);
        hybrid_sort1_helper(right,H);
        nums = merge_nums1(left, right);



    }
    else{
        insertion_sort(nums);

    }

}

void hybrid_sort1(std::vector<int>& nums){

    int H = sqrt(nums.size());

    hybrid_sort1_helper(nums, H);

}

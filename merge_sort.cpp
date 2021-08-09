//
// Created by hongji yan on 4/3/21.
//
#include "../hw2Pharase1/Mysort.h"


std::vector<double> merge_nums(std::vector<double> l, std::vector<double> r)
{
    int left_size = l.size();
    int right_size = r.size();

    int i = 0; //index counter for left
    int j = 0; // index counter for right

    std::vector<double> sorted_list;

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



void merge_sorts(std::vector<double>& nums){

    if (nums.size() > 1)
    {

        std:: vector<double> left = std::vector<double>(nums.begin(), nums.begin() + nums.size()/2);
        std:: vector<double> right = std::vector<double>(nums.begin() + nums.size()/2, nums.end());


        merge_sorts(left);
        merge_sorts(right);
        nums = merge_nums(left, right);



    }
    return;
}
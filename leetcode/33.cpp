/*
33. Search in Rotated Sorted Array
https://leetcode.com/problems/search-in-rotated-sorted-array/

Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

You are given a target value to search. If found in the array return its index, otherwise return -1.

You may assume no duplicate exists in the array.

Subscribe to see which companies asked this question

class Solution {
public:
    int search(vector<int>& nums, int target) {

    }
};

*/
/*
#include <stdio.h>
#include <stdlib.h>
#include <vector>

using namespace std;

int search(vector<int>& nums, int target)
{
    for(int i = 0; i < nums.size(); i ++){
        if(nums[i] == target){
            return i;
        }
    }
    return -1;
}

int main(void)
{
    vector<int> nums;
    int n, a;
    scanf("%d", &n);
    for(;n > 0; n --){
        scanf("%d", &a);
        nums.push_back(a);
    }
    return 0;
}
*/

/**
Given an array containing n distinct numbers taken from 0, 1, 2, ..., n, find the one that is missing from the array.

For example,
Given nums = [0, 1, 3] return 2.

Note:
Your algorithm should run in linear runtime complexity. Could you implement it using only constant extra space complexity?
*/


class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n; i++)
        {
            int a = nums[i];
            while(a<n&&nums[a] != a){
                nums[i] = nums[a];
                nums[a] = a;
                a = nums[i];
            }
        }
        for(int i = 0; i < n; i++)
        {
            if(nums[i] != i)
                return i;
        }
        return n;
    }
};

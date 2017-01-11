/**
Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution.

Example:
Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].
*/
/*
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int a,b;
        vector<int> res;
        for(int i = 0; i < nums.size(); i++)
        {
            int a = nums[i];
            for(int j =i; j < nums.size(); j++)
            {
                int b = nums[j];
                if(i!=j&&(a+b==target))
                {
                    res.push_back(i);
                    res.push_back(j);
                    return res;
                }
            }
        }
        return res;
    }
};
*/

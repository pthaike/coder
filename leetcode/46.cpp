/**
Given a collection of distinct numbers, return all possible permutations.

For example,
[1,2,3] have the following permutations:
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]

*/
class Solution {
public:

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ret;
        permutehelp(nums, 0, ret);
        return ret;
    }

    void permutehelp(vector<int>& nums, int start, vector<vector<int>>& result) {
        if(start >= nums.size())
        {
            result.push_back(nums);
            return;
        }
        for(int i = start; i < nums.size(); i ++)
        {
            swap(nums[start], nums[i]);
            permutehelp(nums, start+1, result);
            swap(nums[start], nums[i]);
        }
    }
};

/**
Given a collection of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

Each number in C may only be used once in the combination.

Note:
All numbers (including target) will be positive integers.
The solution set must not contain duplicate combinations.
For example, given candidate set [10, 1, 2, 7, 6, 1, 5] and target 8,
A solution set is:
[
  [1, 7],
  [1, 2, 5],
  [2, 6],
  [1, 1, 6]
]
*/

class Solution {
public:
    vector<vector<int>> ret;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> v;
        combinationSum2help(candidates, target, 0, v);
        return ret;
    }
    void combinationSum2help(vector<int>& candidates, int target, int cur, vector<int> num)
    {
        if(target <= 0)
        {
            if(target == 0)
                ret.push_back(num);
            return;
        }
        for(int i = cur; i < candidates.size(); i++)
        {
            if(candidates[i] == candidates[i-1]&&i-1>=cur)
                continue;
            vector<int> v = num;
            v.push_back(candidates[i]);
            combinationSum2help(candidates, target - candidates[i], i+1, v);
        }
    }
};

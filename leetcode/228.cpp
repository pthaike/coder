/**
https://leetcode.com/problems/summary-ranges/discuss/

Given a sorted integer array without duplicates, return the summary of its ranges.

For example, given [0,1,2,4,5,7], return ["0->2","4->5","7"].
*/


class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ret;
        string str = "";
        int tmp = -1;
        for(int i = 0; i < nums.size(); i++)
        {
            if(tmp == -1)
            {
                str = to_string(nums[i]);
                tmp = i;
                printf("%d %d\n", i, nums[i]);
            }
            if(i == nums.size()-1 || nums[i+1]  > 1 + nums[i])
            {
                if(i != tmp)
                {
                    str = str +  "->" + to_string(nums[i]);
                }
                tmp = -1;
                ret.push_back(str);
            }
        }
        return ret;
    }
};
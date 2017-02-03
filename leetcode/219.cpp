/**
Given an array of integers and an integer k, find out whether there are two distinct indices i and j in the array such that nums[i] = nums[j] and the absolute difference between i and j is at most k.
*/

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        map<int, int> m;
        map<int, int>::iterator it;
        for(int i = 0; i < nums.size(); i ++)
        {
            it = m.find(nums[i]);
            if(it==m.end())
            {
                m.insert(pair<int,int>(nums[i], i));
            }
            else
            {
                if(i - it->second <= k)
                    return true;
                it->second = i;
            }
        }
        return false;
    }
};

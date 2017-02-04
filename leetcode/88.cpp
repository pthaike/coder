/**
Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.

*/


class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> ret;
        int i = 0, j = 0;
        for(; i < m && j < n; )
        {
            if(nums1[i] <= nums2[j])
                ret.push_back(nums1[i++]);
            else
                ret.push_back(nums2[j++]);
        }
        if(i < m)
        {
            for(; i < m; i ++)
                ret.push_back(nums1[i]);
        }
        if(j < n)
        {
            for(; j < n; j++)
                ret.push_back(nums2[j]);
        }
        nums1 = ret;
    }
};

/**
Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.

You may assume that the array is non-empty and the majority element always exist in the array.
*/
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        //int n = nums.size();
        //return findk(nums, (n+1)/2 , 0, n-1);
        return find(nums);
    }

    int find(vector<int>& nums){
        map<int,int> m;
        int ret;
        int n = nums.size();
        for(int i = 0; i < n; i++)
        {
            m[nums[i]] ++;
            if(m[nums[i]] >= (n+1)/2)
            {
                ret = nums[i];
                break;
            }
        }
        return ret;
    }

    int findk(vector<int>& nums, int k, int start, int end)
    {
        int low = start, high = end-1;
        int mid = start + (end-start)/2;
        swap(nums[mid],nums[end]);
        while(low <= high)
        {
            while(nums[low] <= nums[end] && low <= high)
                low ++;
            while(nums[high] > nums[end] && low <= high)
                high --;
            if(low < high)
                swap(nums[low++], nums[high--]);
        }
        swap(nums[low],nums[end]);
        mid = low - start + 1;
        if(mid == k)
            return nums[low];
        else if(mid > k)
            return findk(nums, k, start, low - 1);
        else
            return findk(nums, k-mid, low + 1, end);
    }
};

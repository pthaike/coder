/**
Follow up for "Find Minimum in Rotated Sorted Array":
What if duplicates are allowed?

Would this affect the run-time complexity? How and why?
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

[3,1,3]
Find the minimum element.

The array may contain duplicates.
*/

class Solution {
public:
    int findMin(vector<int>& nums) {
        return findMinHelp(nums, 0, nums.size()-1);
    }

    int findMinHelp(vector<int>& nums, int left, int right)
    {
        if(nums[left] < nums[right] || left >= right)
            return nums[left];
        int mid =( left + right ) / 2;
        if (nums[mid] == nums[left] && nums[mid] == nums[right])
        {
            int l = findMinHelp(nums, left, mid);
            int r = findMinHelp(nums, mid+1, right);
            return l < r ? l : r;
        }
        else if(nums[mid] >= nums[left])
            return findMinHelp(nums, mid+1, right);
        else
            return findMinHelp(nums, left, mid);
    }
};

/**
Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You may assume no duplicates in the array.

Here are few examples.
[1,3,5,6], 5 ¡ú 2
[1,3,5,6], 2 ¡ú 1
[1,3,5,6], 7 ¡ú 4
[1,3,5,6], 0 ¡ú 0
[1,3,5,6], 0 ¡ú 0
*/

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int high, low, mid=0;
        high = nums.size()-1;
        low = 0;
        while(low <= high)
        {
            mid = (high + low) / 2;
            if(target < nums[mid])
            {
                high = mid -1;
            }
            else if (target > nums[mid])
            {
                low = mid + 1;
                mid = low;
            }
            else
                break;
        }
        return mid;
    }
};

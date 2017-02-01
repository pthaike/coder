/**
Given an array of n integers where n > 1, nums, return an array output such that output[i] is equal to the product of all the elements of nums except nums[i].

Solve it without division and in O(n).

For example, given [1,2,3,4], return [24,12,8,6].

Follow up:
Could you solve it with constant space complexity? (Note: The output array does not count as extra space for the purpose of space complexity analysis.)
*/

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int num = 0;
        int pi = 1;
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i]==0)
                num++;
        }
        if(num > 1)
        {
            for(int i = 0; i < nums.size(); i++)
                nums[i]=0;
        }
        else if (num == 1)
        {
            int k;
            for(int i = 0; i < nums.size(); i++)
            {
                if(nums[i] == 0)
                    k = i;
                else
                    pi *= nums[i];
                nums[i] = 0;
            }
            nums[k] = pi;
        }
        else
        {
            int a = 1;
            int i = 0;
            for(i= 0; i < nums.size()-1; i++)
            {
                a *= nums[i];
            }
            int c = nums[i];
            nums[i] = a;
            for(i = i-1; i >=0; i --)
            {
                int b = nums[i];
                nums[i] = a/b*c;
                a = a/b*c;
                c = b;
            }
        }

        return nums;
    }
};

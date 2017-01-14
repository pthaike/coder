/**
Given an unsorted array return whether an increasing subsequence of length 3 exists or not in the array.

Formally the function should:
Return true if there exists i, j, k
such that arr[i] < arr[j] < arr[k] given 0 ¡Ü i < j < k ¡Ü n-1 else return false.
Your algorithm should run in O(n) time complexity and O(1) space complexity.

Examples:
Given [1, 2, 3, 4, 5],
return true.

Given [5, 4, 3, 2, 1],
return false.

*/
/*
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int dp[10000] = {0};
        dp[0] = 1;
        for(int i = 1; i < nums.size(); i ++)
        {
            int max = 1;
            for(int j = i-1; j >=0; j--)
            {
                if(nums[i] > nums[j])
                {
                    //printf("%d %d\n", nums[i], nums[j]);
                    max = max > dp[j] + 1 ? max : dp[j] + 1;
                    if(max >= 3)
                        return true;
                }
            }
            dp[i] = max;
        }
        return false;
    }
};
*/

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n1 = INT_MAX, n2 = INT_MAX;
        for(int i = 0; i < nums.size(); i ++)
        {
            int a = nums[i];
            if(a <= n1)
                n1 = a;
            else if(a <= n2)
                n2 = a;
            else
                return true;
        }
        return false;
    }
};

#include<stdio.h>
#include<limits.h>
using namespace std;

int main(void)
{
    printf("%d\n", INT_MAX);
    return 0;
}

/**
Given a range [m, n] where 0 <= m <= n <= 2147483647, return the bitwise AND of all numbers in this range, inclusive.

For example, given the range [5, 7], you should return 4.
*/

class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int res = m;
        for(int i = m+1; i <= n && i >= 0 ; i++)
        {
            res = res & i;
            if(res==0)
                return 0;
        }
        return res;
    }
};

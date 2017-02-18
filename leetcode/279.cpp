/**

*/

class Solution {
public:
    int ret = 100000000;
    int numSquares(int n) {
         int m = sqrt(n);
        numSquaresHelp(n, m, 0);
        return ret;
    }

    void numSquaresHelp(int n, int m, int l)
    {
        if(n < 0 || l >= ret)
            return;
        if(n == 0)
        {
            ret = ret < l ? ret : l;
            return;
        }
        for(int i = m; i > 0; i--)
        {
            numSquaresHelp(n - i*i, m, l+1);
        }
    }

};

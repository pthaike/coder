/**
Assume you are an awesome parent and want to give your children some cookies. But, you should give each child at most one cookie. Each child i has a greed factor gi, which is the minimum size of a cookie that the child will be content with; and each cookie j has a size sj. If sj >= gi, we can assign the cookie j to the child i, and the child i will be content. Your goal is to maximize the number of your content children and output the maximum number.
*/

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int i = s.size()-1, j = g.size()-1;
        int num = 0;
        while(i >= 0 && j >= 0)
        {
            while(j >= 0)
            {
                if(g[j] <= s[i])
                {
                    num ++;
                    j --;
                    i--;
                    break;
                }
                j--;
            }
        }
        return num;
    }
};

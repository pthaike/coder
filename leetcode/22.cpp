/**
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:

[
  "((()))",
  "(()())",
  "(())()",
  "()(())",
  "()()()"
]
*/

class Solution {
public:
    vector<string> ret;
    vector<string> generateParenthesis(int n) {
        string s;
        generateParenthesisHelp(n, 2*n, 0, s);
        return ret;
    }
    void generateParenthesisHelp(int n, int cur, int k, string s)
    {
        if(cur  <= 0)
        {
            string s1 = s;
            ret.push_back(s1);
            return;
        }
        if(k > 0)
            generateParenthesisHelp(n, cur-1, k-1, s+')');
        if(k < cur)
            generateParenthesisHelp(n, cur-1, k+1, s+'(');
    }
};

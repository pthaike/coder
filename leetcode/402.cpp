/**
Given a non-negative integer num represented as a string, remove k digits from the number so that the new number is the smallest possible.

Note:
The length of num is less than 10002 and will be ¡Ý k.
The given num does not contain any leading zero.
Example 1:

Input: num = "1432219", k = 3
Output: "1219"
Explanation: Remove the three digits 4, 3, and 2 to form the new number 1219 which is the smallest.
Example 2:

Input: num = "10200", k = 1
Output: "200"
Explanation: Remove the leading 1 and the number is 200. Note that the output must not contain leading zeroes.
Example 3:

Input: num = "10", k = 2
Output: "0"
Explanation: Remove all the digits from the number and it is left with nothing which is 0.
*/


class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> s;
        stack<char> s2;
        if(num.size() == k || num.size() == 0)
            return "0";
        for(int i = 0; i < num.size(); )
        {
            char a = num[i];
            if(!s.empty() && s.top()>a && k>0)
            {
                s.pop();
                k--;
            }
            else
            {
                s.push(a);
                i++;
            }
        }
        while(k--)
            s.pop();
        while(!s.empty())
        {
            s2.push(s.top());
            s.pop();
        }
        while(!s2.empty())
        {
            if(s2.top()!='0')
                break;
            s2.pop();
        }

        if(s2.empty())
            return "0";
        string res(s2.size(),'0');
        int i = 0;
        while(!s2.empty())
        {
            res[i++] = s2.top();
            s2.pop();
        }
        return res;
    }
};

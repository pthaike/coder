/**
A message containing letters from A-Z is being encoded to numbers using the following mapping:

'A' -> 1
'B' -> 2
...
'Z' -> 26
Given an encoded message containing digits, determine the total number of ways to decode it.

For example,
Given encoded message "12", it could be decoded as "AB" (1 2) or "L" (12).

The number of ways decoding "12" is 2.
*/

class Solution {
public:
    int numDecodings(string s) {
        if(s.size()==0||s[0]=='0')
            return 0;
        int a=1, b = 1, cur = 1;
        for(int i = 2; i <= s.size(); i++)
        {
            int c1 = s[i-1]-'0';
            int c2 = s[i-2]-'0';
            int c = c2*10+c1;
            if(c1==0&&c2==0 || c1 == 0 && c2 > 2)
                return 0;
            if(c2 == 0)
                cur = b;
            else if(c1 == 0)
                cur = a;
            else if(c <= 26)
                cur = a + b;
            else
                cur = b;
            a = b;
            b = cur;
        }
        return cur;
    }
};

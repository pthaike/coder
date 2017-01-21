/**
Given a string, find the length of the longest substring without repeating characters.

Examples:

Given "abcabcbb", the answer is "abc", which the length is 3.

Given "bbbbb", the answer is "b", with the length of 1.

Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
*/


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size()==0)
            return 0;
        int start = 0;
        int end = 0;
        int max=1;
        for(int i = 1; i < s.size(); i++)
        {
            for(int j = start; j <= end; j++)
            {
                if(s[i] == s[j])
                {
                    int gap = end - start + 1;
                    max = max > gap ? max : gap;
                    start = j+1;
                    break;
                }
            }
            end ++;
        }
        int gap = end - start + 1;
        max = max > gap ? max : gap;
        return max;
    }
};

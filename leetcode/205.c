/***
Given two strings s and t, determine if they are isomorphic.

Two strings are isomorphic if the characters in s can be replaced to get t.

All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character but a character may map to itself.

For example,
Given "egg", "add", return true.

Given "foo", "bar", return false.

Given "paper", "title", return true.

Note:
You may assume both s and t have the same length.
*/


class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int a1[256]={0}, a2[256]={0};
        for(int i = 0; i < s.size(); i++)
        {
            if(a1[s[i]]!=a2[t[i]]) return false;
            a1[s[i]] = i+1;
            a2[t[i]] = i+1;
        }
        return true;
    }
};

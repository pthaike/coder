/**
Given a list of words (without duplicates), please write a program that returns all concatenated words in the given list of words.

A concatenated word is defined as a string that is comprised entirely of at least two shorter words in the given array.

Example:
Input: ["cat","cats","catsdogcats","dog","dogcatsdog","hippopotamuses","rat","ratcatdogcat"]

Output: ["catsdogcats","dogcatsdog","ratcatdogcat"]

Explanation: "catsdogcats" can be concatenated by "cats", "dog" and "cats";
 "dogcatsdog" can be concatenated by "dog", "cats" and "dog";
"ratcatdogcat" can be concatenated by "rat", "cat", "dog" and "cat".
Note:
The number of elements of the given array will not exceed 10,000
The length sum of elements in the given array will not exceed 600,000.
All the input string will only include lower case letters.
The returned elements order does not matter.

*/

#include<stdio.h>
#include<algorithm>
#include<vector>
#include<string>
#include<iostream>

using namespace std;


bool cmp(const string &s1, const string &s2)
{
    return s1.size() < s2.size();
}


class Solution {
public:
    vector<string> res;
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        sort(words.begin(), words.end(), cmp);
        unordered_set<string> se;
        for(int i = 0; i < words.size(); i++)
        {
            if(helper(se, words[i]))
            {
                res.push_back(words[i]);
            }
            se.insert(words[i]);
        }
        return res;
    }

    bool helper(unordered_set<string> se, string s)
    {
        if(se.size()==0)
            return false;
        bool dp[10000]={0};
        dp[0] = true;
        for(int i = 1; i <= s.size(); i++)
        {
            for(int j = 0; j < i; j++)
            {
                if(!dp[j])
                    continue;
                if(se.count(s.substr(j, i-j)))
                {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[s.size()];
    }
};






int main(void)
{
    vector<string> words;
    words.push_back("cat");
    words.push_back("dog");
    words.push_back("catdog");
    Solution s;
    s.findAllConcatenatedWordsInADict(words);
    return 0;
}

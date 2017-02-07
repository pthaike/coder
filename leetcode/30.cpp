/**
You are given a string, s, and a list of words, words, that are all of the same length. Find all starting indices of substring(s) in s that is a concatenation of each word in words exactly once and without any intervening characters.

For example, given:
s: "barfoothefoobarman"
words: ["foo", "bar"]

You should return the indices: [0,9].
(order does not matter).
*/


class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ret;
        if(s == "" || words.empty())
            return ret;
        unordered_map<string, int> um;
        for(int i = 0; i < words.size(); i++)
            um[words[i]] ++;
        int ix = 0, pix, count;
        int len = words[0].size();
        int num = words.size();
        for(int i = 0; i < s.size()-num*len+1; i ++)
        {
            unordered_map<string,int> tmp;
            int j;
            for(j = i; j <= i + num*len; )
            {
                string sb = s.substr(j,len);
                if(um.find(sb) != um.end())
                {
                    tmp[sb] ++;
                    if(tmp[sb] > um[sb])
                        break;
                    j += len;
                }
                else
                    break;
            }
            if(j == i + num*len)
                ret.push_back(i);
        }
        return ret;
    }
};

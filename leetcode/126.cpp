/*
#include <stdio.h>
#include <vector>
#include <map>
#include <queue>
#include <unordered_set>
using namespace std;

class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, unordered_set<string> &wordList) {
        vector<vector<string>> res;
        map<string, vector<string>> m;
        vector<string> start;
        vector<string> end;
        queue<vector<string>> q;
        unordered_set<string>::iterator set_it;
        if(check(beginWord, endWord)){
            vector<string> tmp;
            tmp.push_back(beginWord);
            tmp.push_back(endWord);
            res.push_back(tmp);
            return res;
        }
        for(set_it = wordList.begin(); set_it != wordList.end(); set_it++){
            vector<string> tmp;
            string s1 = *set_it;
            for(unordered_set<string>::iterator set_it2 = wordList.begin(); set_it2 != wordList.end(); set_it2++){
                string s2 = *set_it2;
                if(check(s1,s2)){
                    tmp.push_back(s2);
                }
            }
            if(check(beginWord, s1)){
                start.push_back(s1);
            }
            if(check(endWord, s1)){
                end.push_back(s1);
                //tmp.push_back(endWord);
            }
            if(!tmp.empty()){
                m[s1] = tmp;
            }
        }
        for(int i = 0; i < start.size(); i++){
            vector<string> tmp;
            tmp.push_back(beginWord);
            tmp.push_back(start[i]);
            q.push(tmp);
        }
        int len = -1;
        while(!q.empty()){
            map<string, vector<string>>::iterator it;
            vector<string> v;
            vector<string> tmp = q.front();
            q.pop();
            if(len < 0 && tmp.size() > len || tmp.size() > wordList.size()+2){
                break;
            }
            string s = tmp.back();
            for(int i = 0; i < end.size(); i++){
                if(s == end[i]){
                    len = tmp.size();
                    tmp.push_back(endWord);
                    res.push_back(tmp);
                    continue;
                }
            }
            it = m.find(s);
            if(it != m.end()){
                v = m[s];
            }
            for(int i = 0; i < v.size(); i++){
                vector<string> t;
                std::copy(tmp.begin(), tmp.end(), t.begin());
                t.push_back(v[i]);
                q.push(t);
            }
        }
        return res;
    }

    bool check(string s1, string s2){
        int diff = 0;
        for(int k = 0; k < s1.size(); k++){
            if(s1[k] != s2[k]){
                diff += 1;
                if(diff > 1){
                    break;
                }
            }
        }
        if(diff == 1){
            return true;
        }
        return false;
    }
};

int main(void){
    return 0;

}
*/

/**
You have a number of envelopes with widths and heights given as a pair of integers (w, h). One envelope can fit into another if and only if both the width and height of one envelope is greater than the width and height of the other envelope.

What is the maximum number of envelopes can you Russian doll? (put one inside other)

Example:
Given envelopes = [[5,4],[6,4],[6,7],[2,3]], the maximum number of envelopes you can Russian doll is 3 ([2,3] => [5,4] => [6,7]).
*/

#include<stdio.h>
#include<utility>
#include<vector>
#include<algorithm>
#include<iostream>

using namespace std;
bool cmp(const pair<int, int> &p1, const pair<int, int> &p2)
{
    if(p1.first == p2.first)
        return p1.second > p2.second;
    else
        return p1.first > p2.first;
}

bool cmp2(const pair<int, int> &p1, const pair<int, int> &p2)
{
    if(p1.first == p2.first)
        return p1.second < p2.second;
    else
        return p1.first < p2.first;
}

class Solution {
public:
    int flag[100000]={0};
    int maxEnvelopes(vector<pair<int, int> >& envelopes) {
        pair<int, int> env(100000,100000);
        sort(envelopes.begin(), envelopes.end(), cmp);
        return maxEnvelopesHelp(envelopes, env, 0);
    }
    int maxEnvelopesHelp(vector<pair<int, int> >& envelopes, pair<int, int> env, int num)
    {
        if(envelopes.size()<=0)
            return 0;
        int max = num;
        for(int i = 0; i < envelopes.size(); i++)
        {
            if(flag[i]==0 && envelopes[i].first < env.first && envelopes[i].second < env.second)
            {
                flag[i] = 1;
                int a = maxEnvelopesHelp(envelopes, envelopes[i], num+1);
                max = max > a ? max : a;
                int b = maxEnvelopesHelp(envelopes, env, num);
                max = max > b ? max : b;
                flag[i] = 0;
            }
        }
        return max;
    }


    int maxEnvelopes1(vector<pair<int, int> >& envelopes) {
        if(envelopes.size() == 0)
            return 0;
        sort(envelopes.begin(), envelopes.end(), cmp2);
        int dp[100000];
        dp[0] = 1;
        int i, res = 1;
        for(i = 1; i < envelopes.size(); i++)
        {
            dp[i] = 1;
            int max = 1;
            for(int j = 0; j < i; j++)
            {
                if(envelopes[j].first < envelopes[i].first && envelopes[j].second < envelopes[i].second)
                {
                    max = max > dp[j]+1 ? max : dp[j]+1;
                }
            }
            dp[i] = max;
            res = res > max ? res : max;
        }
        return res;
    }



};
int main(void)
{
    Solution solution;
    vector< pair<int, int> > v;
    v.push_back(pair<int,int>(10,8));
    v.push_back(pair<int,int>(1,12));
    v.push_back(pair<int,int>(6,15));
    v.push_back(pair<int,int>(2,18));

    printf("%d", solution.maxEnvelopes1(v));
}


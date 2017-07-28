struct cmp
{
    bool operator()(const pair<int,int>& a, const pair<int, int>& b)
    {
        return a.second > b.second;
    }
};

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ret;
        map<int, int> m;
        map<int,int>::iterator it;
        priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> q;
        for(int i = 0; i < nums.size(); i ++)
        {
            if(m.find(nums[i]) == m.end())
            {
                m[nums[i]] = 1;
            }
            else
            {
                m[nums[i]] ++;
            }
        }
        for(it = m.begin(); it != m.end() && k > 0; it++, k--)
        {
            q.push(pair<int, int>(it->first, it->second));
        }
        while(it != m.end())
        {
            pair<int, int> p = q.top();
            if(it->second > p.second)
            {
                q.pop();
                q.push(pair<int, int>(it->first, it->second));
            }
            it++;
        }
        while(!q.empty())
        {
            pair<int, int> p = q.top();
            ret.push_back(p.first);
            q.pop();
        }
        return ret;
    }
};

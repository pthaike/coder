# some general util in algorithm

# define
```
#include <set>
#include <map>
#include <list>
#include <queue>
#include <stack>
#include <cmath>
#include <string>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

#define PB              push_back
#define SIZE(x)         (int)x.size()
#define clr(x,y)        memset(x,y,sizeof(x))
#define MP(x,y)         make_pair(x,y)
#define RS(n)           scanf ("%s", n)
#define ALL(t)          (t).begin(),(t).end()
#define FOR(i,n,m)      for (int i = n; i <= m; i ++)
#define ROF(i,n,m)      for (int i = n; i >= m; i --)
#define IT              iterator
#define FF              first
#define SS              second

typedef long long               ll;
typedef unsigned int            uint;
typedef unsigned long long      ull;
typedef vector<int>             vint;
typedef vector<string>          vstring;
typedef pair<int, int>          PII;

void RI (int& x){
	x = 0;
	char c = getchar ();
	while (c == ' '||c == '\n')	c = getchar ();
	bool flag = 1;
	if (c == '-'){
		flag = 0;
		c = getchar ();
	}
	while (c >= '0' && c <= '9'){
		x = x * 10 + c - '0';
		c = getchar ();
	}
	if (!flag)	x = -x;
}
void RII (int& x, int& y){RI (x), RI (y);}
void RIII (int& x, int& y, int& z){RI (x), RI (y), RI (z);}

/**************************************END define***************************************/

const ll mod = 1e9+7;
const ll LINF = 1e18;
const int INF = 1e9;
const double EPS = 1e-8;
```


# pair
```
#include<utility>
pair<int, int> itv[MAX];
pair<int, int> a(1,3);
itv[i].first = t[i];
itv[i].second = s[i];
```

#sort
```
#include<algorithm>
sort(itv, itv+n, cmp);

bool cmp(const pair<int, int> &p1, const pair<int, int> &p2)
{
    if(p1.first == p2.first)
        return p1.second < p2.second;
    else
        return p1.first < p2.first;
}
```

# memset
```
#include <memory.h>
memset(dp, -1, sizeof(dp)) //can init 0 or -1 but not 1 
```

# max
```
algorithm
```


# queue
```
1.back() 返回一个引用，指向最后一个元素
2.empty() 如果队列空则返回真
3.front() 返回第一个元素
4.pop() 删除第一个元素
5.push() 在末尾加入一个元素
6.size() 返回队列中元素的个数

--Java
offer()
pop()
```

## priority_queue
```
#include <queue>
top()
push()
pop()
定义方式
std::priority_queue<T> pq;

struct cmp
{
    bool operator()(int &a, int &b) const
    {
        //因为优先出列判定为!cmp，所以反向定义实现最小值优先
        return a > b;
    }
};
std::priority_queue<T, std::vector<T>, cmp> pq;

priority_queue<pii, vector<pii>, greater<pii>> q;

greater<int>()

long long cost(int k)
{
    long long sum = 0;
    int w = 1;
    priority_queue<int> pq;
    int i;
    for(i = 0; i < k; i++)
        pq.push(p[i]);
    while(!pq.empty())
    {
        int a = pq.top();
        pq.pop();
        sum = sum + w * a;
        w ++;
        if(i < n)
            pq.push(p[i++]);
    }
    //printf("%d %d\n",k,sum);
    return sum;
}
```

# stack
```
pop()
push()
top()

```

# vector
```
push_back()
pop_back()

```

# map
```
m.count(k)

bool containsNearbyDuplicate(vector<int>& nums, int k) {
        map<int, int> m;
        map<int, int>::iterator it;
        for(int i = 0; i < nums.size(); i ++)
        {
            it = m.find(nums[i]);
            if(it==m.end())
            {
                m.insert(pair<int,int>(nums[i], i));
            }
            else
            {
                if(i - it->second <= k)
                    return true;
                it->second = i;
            }
        }
        return false;
    }
```

# set
```
insert(a)
erase(a)

bool containsNearbyDuplicate(vector<int>& nums, int k)
{
   unordered_set<int> s;
   if (k <= 0) return false;
   if (k >= nums.size()) k = nums.size() - 1;
   for (int i = 0; i < nums.size(); i++)
   {
       if (i > k) s.erase(nums[i - k - 1]);
       if (s.find(nums[i]) != s.end()) return true;
       s.insert(nums[i]);
   }
   
   return false;
```

# Split
```
vector<string> split(string str, char delimiter) {
      vector<string> internal;
      stringstream ss(str);
      string tok;
      while(getline(ss, tok, delimiter)) {
        internal.push_back(tok);
      }
      return internal;
}
```


# character
```
#include <string>
toupper('t')
tolower()
isalnum() //数字或字母
isdigit() //数字
to_string
```

# string
```
s1.count(s2) //s1包含s2次数
s1.substr(pos,len) // from pos to pos+len

memset(dp, 0, sizeof(dp));

std::stoi(ls[0]); // string to int

strcmp(s1,s2) //0:s1==s2, 正数:s1>s2, 负数:s1 < s2
```

# math
```
sqrt(4)
```

#INT_MAX, INT_MIN
```
#include<limits.h>
```

# 01背包
```
int dp[501][100001] = {0};
vector< pair<int, int> > v;
int ne, val;
scanf("%d%d", &n, &m);
v.push_back(pair<int,int>(0, 0));
for(int i = 0; i < n; i++)
{
    scanf("%d%d", &ne, &val);
    v.push_back(pair<int,int>(ne, val));
}
for(int i = 1; i <= n; i++)
{
    for(int j = 0; j <= m; j++)
    {
        if(j < v[i].first)
            dp[i][j] = dp[i-1][j];
        else
            dp[i][j] = max(dp[i-1][j], dp[i-1][j-v[i].first] + v[i].second);
    }
}
printf("%d\n", dp[n][m]);


////memory
int dp[100001] = {0};
for(int i = 1; i <= n; i++)
{
    for(int j =  m; j >= v[i].first; j--)
        dp[j] = max(dp[j], dp[j-v[i].first] + v[i].second);
}
printf("%d\n", dp[m]);



打印
i←N  
  
j←V  
  
while(i>0 && j>0)  
  
    do if(F[i][j]=F[i-1][j-C[i]]+W[i])  
  
        then Print W[i]  
  
             j←j-C[i]  
  
    i←i-1  
```

# find k-th num
```
int findk(vector<int>& nums, int k, int start, int end)
{
    int low = start, high = end-1;
    int mid = start + (end-start)/2;
    swap(nums[mid],nums[end]);
    while(low <= high)
    {
        while(nums[low] <= nums[end] && low <= high)
            low ++;
        while(nums[high] > nums[end] && low <= high)
            high --;
        if(low < high)
            swap(nums[low++], nums[high--]);
    }
    swap(nums[low],nums[end]);
    mid = low - start + 1;
    if(mid == k)
        return nums[low];
    else if(mid > k)
        return findk(nums, k, start, low - 1);
    else
        return findk(nums, k-mid, low + 1, end);
}
```


# Top K Frequent Elements
```
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
```


# qsort
```
void quicksort(int* a, int left, int right)
{
    if(left >= right) return;
    int pivot = a[left];
    int l = left+1, r = right;
    while(l <= r)
    {
        while(l <= r && a[l] <= pivot) l++;
        while(l <= r && a[r] > pivot) r--;
        if(l <= r)
        {
            int tmp = a[l];
            a[l] = a[r];
            a[r] = tmp;
            l++, r--;
        }
    }
    a[left] = a[r];
    a[r] = pivot;
    quicksort(a, left, r-1);
    quicksort(a, l, right);
}
```

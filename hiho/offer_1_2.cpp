/**
描述
小Ho编写了一个处理数据包的程序。程序的输入是一个包含N个数据包的序列。每个数据包根据其重要程度不同，具有不同的"延迟惩罚值"。序列中的第i个数据包的"延迟惩罚值"是Pi。如果N个数据包按照<Pi1, Pi2, ... PiN>的顺序被处理，那么总延迟惩罚

SP=1*Pi1+2*Pi2+3*Pi3+...+N*PiN（其中i1, i2, ... iN是1, 2, 3, ... N的一个排列)。

小Ho的程序会依次处理每一个数据包，这时N个数据包的总延迟惩罚值SP为

1*P1+2*P2+3*P3+...+i*Pi+...+N*PN。

小Hi希望可以降低总延迟惩罚值。他的做法是在小Ho的程序中增加一个大小为K的缓冲区。N个数据包在被处理前会依次进入缓冲区。当缓冲区满的时候会将当前缓冲区内"延迟惩罚值"最大的数据包移出缓冲区并进行处理。直到没有新的数据包进入缓冲区时，缓冲区内剩余的数据包会按照"延迟惩罚值"从大到小的顺序被依次移出并进行处理。

例如，当数据包的"延迟惩罚值"依次是<5, 3, 1, 2, 4>，缓冲区大小K=2时，数据包被处理的顺序是：<5, 3, 2, 4, 1>。这时SP=1*5+2*3+3*2+4*4+5*1=38。

现在给定输入的数据包序列，以及一个总延迟惩罚阈值Q。小Hi想知道如果要SP<=Q，缓冲区的大小最小是多少？

输入
Line 1: N Q

Line 2: P1 P2 ... PN

对于50%的数据： 1 <= N <= 1000

对于100%的数据： 1 <= N <= 100000, 0 <= Pi <= 1000, 1 <= Q <= 1013

输出
输出最小的正整数K值能满足SP<=Q。如果没有符合条件的K，输出-1。

样例输入
5 38
5 3 1 2 4
样例输出
2
*/

#include<cstdio>
#include<queue>

using namespace std;

int p[100001], n, sp;
long long q;

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

int main(void)
{
    scanf("%d%lld", &n, &q);
    for(int i = 0; i < n; i ++)
        scanf("%d", &p[i]);
    int k=0;
    int low = 0, high = n-1, mid=0;
    while(low <= high)
    {
        mid = low + (high - low) / 2;
        if(cost(mid+1) <= q)
            high = mid -1;
        else
            low = mid +1;
    }
    k = low+1;
    if(k<=n)
        printf("%d\n",k);
    else
        printf("-1\n");
    return 0;
}


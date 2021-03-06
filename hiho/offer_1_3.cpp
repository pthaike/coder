/**
http://hihocoder.com/contest/hihointerview3/problem/3
题目3 : 建造基地
时间限制:10000ms
单点时限:1000ms
内存限制:256MB
描述
在遥远的未来，小Hi成为了地球联邦外空间联合开发工作组的一员，前往一颗新发现的星球开发当地的重金属资源。

为了能够在当地生存下来，小Hi首先要建立一个基地。建立基地的材料可以直接使用当地的石材和富裕的重金属资源。基地建设分为N级，每一级都需要达成K的建设值后才能够完成建设，当前级别的建设值溢出后不会影响到下一级的建设。

小Hi可以产出的重金属资源按照精炼程度分为M级，根据开采的数量和精炼的工艺，可以将获取精炼程度为第i级的重金属资源的成本量化为Ai。

在建设第1级基地时，一块精炼度为i的重金属可以提供Bi的建设值，此后基地的级别每提高一级，建设值将除以T并下取整(整除)。

现给定N、M、K、T、A[]和B[]，小Hi需要你帮助他计算他完成基地建设的最小成本。

输入
输入包含多组测试数据。

输入的第一行为一个整数Q，表示测试数据的组数。

每组测试数据的第一行为4个整数N、M、K和T，意义如前文所述。

接下来的一行为M个整数，分别表示A1~AM。

接下来的一行为M个整数，分别表示B1~BM。

对于100%的数据，满足1<=N<=10，1<=M<=100，1<=K,T<=104

对于100%的数据，满足Ai和Bi均为32位整型范围内的正整数

对于100%的数据，满足1<=Q<=10

输出
对于每组测试数据，如果小Hi最终能够完成基地建设，则输出小Hi完成基地建设所需要的最小成本，否则输出“No Answer”。

样例输入
2
2 2 2 2
1 3
1 2
2 2 2 2
1 2
1 1
样例输出
8
No Answer
*/

#include <cstdio>

using namespace std;

int n, m, k, t, a[101], b[101],

int main(void)
{
    int q;
    scanf("%d", &q);
    while(q--)
    {
        scanf("%d%d%d%d", &n, &m, &k, &t);
        for(int i = 0; i < m; i++)
            scanf("%d", &a[i]);
        for(int i = 0; i < m; i++)
            scanf("%d", &b[i]);

    }
    return 0;
}

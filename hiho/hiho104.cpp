/**
http://hihocoder.com/contest/hiho104/problem/1
描述

小Ho：小Hi，上一次你跟我讲了Treap，我也实现了。但是我遇到了一个关键的问题。

小Hi：怎么了？

小Ho：小Hi你也知道，我平时运气不太好。所以这也反映到了我写的Treap上。

小Hi：你是说你随机出来的权值不太好，从而导致结果很差么？

小Ho：就是这样，明明一样的代码，我的Treap运行结果总是不如别人。小Hi，有没有那种没有随机因素的平衡树呢？

小Hi：当然有了，这次我就跟你讲讲一种叫做Splay的树吧。而且Splay树能做到的功能比Treap要更强大哦。

小Ho：那太好了，你快告诉我吧！

提示：Splay

输入

第1行：1个正整数n，表示操作数量，100≤n≤200,000

第2..n+1行：可能包含下面3种规则：

1个字母'I'，紧接着1个数字k，表示插入一个数字k到树中，1≤k≤1,000,000,000，保证每个k都不相同

1个字母'Q'，紧接着1个数字k。表示询问树中不超过k的最大数字

1个字母'D'，紧接着2个数字a,b，表示删除树中在区间[a,b]的数。

输出

若干行：每行1个整数，表示针对询问的回答，保证一定有合法的解

样例输入
6
I 1
I 2
I 3
Q 4
D 2 2
Q 2
样例输出
3
1
*/

#include<cstdio>
#include<cstdlib>

using namespace std;



int main(void)
{
    int n,k;
    char c;
    scanf("%d", &n);
    while(n--)
    {
        scanf("%c %c %d", &c, &c, &k);

    }
    return 0;
}

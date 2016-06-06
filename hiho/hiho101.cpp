/**
http://hihocoder.com/contest/hiho101/problem/1
跳舞链

输入

第1行：1个正整数t，表示数据组数，1≤t≤10。

接下来t组数据，每组的格式为：

第1行：2个正整数n,m，表示输入数据的行数和列数。2≤n,m≤100。

第2..n+1行：每行m个数，只会出现0或1。

输出

第1..t行：第i行表示第i组数据是否存在解，若存在输出"Yes"，否则输出"No"。

样例输入
2
4 4
1 1 0 1
0 1 1 0
1 0 0 0
0 1 0 1
4 4
1 0 1 0
0 1 0 0
1 0 0 0
0 0 1 1
样例输出
No
Yes
*/

#include <stdio.h>
using namespace std;

#define MAXLEN 100

int matrix[MAXLEN];

struct _node
{
    struct _node * left;
    struct _node * right;
    struct _node * up;
    struct _node * down;
    int x;
    int y;
};

struct _node * init(int m, int n)
{
    struct _node * head = {left:head, right:head, up:head, down:head, x:0, y:0};
    struct _node * pre = head;
    for(int i = 0; i < m; i++)
    {
        struct _node * p = {x:0, y:i};
        p.down = p;
        p.up = p;
        p.left = pre;
        p.right = pre.right;
        pre.right = p;

    }
    return head;
}

void remove()
{

}

void resume()
{

}

bool dance()
{
    return false;
}

int main(void)
{
    int t, m, n;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d%d", &n, &m);
        for(int i = 0; i < n; i ++)
            for(int j = 0; j < m; j++)
                scanf("%d", &matrix[i][j]);
        if(dance())
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}

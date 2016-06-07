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

struct _node * columnHead[MAXLEN+1];
struct _node * node[MAXLEN*MAXLEN];
int id[MAXLEN][MAXLEN];
int m,n;

struct _node * init(int m, int n)
{
    //构建表头
    struct _node * head = {left:head, right:head, up:head, down:head, x:-1, y:-1};
    struct _node * pre = head;

    for(int i = 0; i < n; i++)
    {
        struct _node * p = {x:0, y:i};
        columnHead[i] = p;
        p->down = p;
        p->up = p;
        p->left = pre;
        p->right = pre->right;
        pre->right->left = p;
        pre->right = p;
        pre = p;
    }
    //初始化并编号
    int cnt = 0;

    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(matrix[i][j] == 1)
            {
                id[i][j] = cnt;
                node[cnt++] = {left:node[cnt], right:node[cnt], up:node[cnt], down:node[cnt], x:i, y:j};
            }
        }
    }
    //纵向添加结点
    struct _node * p;
    for(int i = 0; i < m; i++)
    {
        pre = columnHead[i];
        for(int j = 0; j < n; j++)
        {
            if(matrix[i][j] == 1)
            {
                p = node[id[i][j]];
                p.down = pre.down;
                p.up = pre;
                pre.down.up = p;
                pre.down = p;
                pre = p;
            }
        }
    }
    //横向添加结点
    for(int i = 0; i < n; i++)
    {
        pre = NULL;
        for(int j = 0; j < m; j++)
        {
            if(matrix[j][i] == 1)
            {
                if(pre == NULL)
                    pre = node[id[j][i]];
                else
                {
                    p = node[id[j][i]];
                    p.left = pre;
                    p.right = pre.right;
                    pre.right.left = p;
                    pre.right = p;
                    pre = p;
                }
            }
        }
    }

    return head;
}
/**
删除col列
*/
void remove(int col)
{
    struct _node * p = columnHead[col];
    p.right.left = p.left;
    p.left.right = p.right;
    struct _node *p1 = p.down;
    while(p1 != p)
    {
        //获取该列下的每个结点
        struct _node * p2 = p1.right;
        while(p2 != p1)
        {
            p2.down.up = p2.up;
            p2.up.down = p2.down;
            p2 = p2.right;
        }
        p1 = p1.down;
    }
}
/**
回复col列
*/
void resume(int col)
{
    struct _node * p = columnHead[col];
    p.right.left = p;
    p.left.right = p;
    struct _node * p1 = p.down;
    while(p1 != p)
    {
        struct _node * p2 = p1.right;
        while(p2 != p1)
        {
            p2.up.down = p2;
            p2.down.up = p2;
            p2 = p2.right;
        }
        p1 = p1.down;
    }
}

bool dance(int m, int n)
{
    struct _node * head = init(m,n);
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

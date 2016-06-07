/**
http://hihocoder.com/contest/hiho101/problem/1
������

����

��1�У�1��������t����ʾ����������1��t��10��

������t�����ݣ�ÿ��ĸ�ʽΪ��

��1�У�2��������n,m����ʾ�������ݵ�������������2��n,m��100��

��2..n+1�У�ÿ��m������ֻ�����0��1��

���

��1..t�У���i�б�ʾ��i�������Ƿ���ڽ⣬���������"Yes"���������"No"��

��������
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
�������
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
    //������ͷ
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
    //��ʼ�������
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
    //������ӽ��
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
    //������ӽ��
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
ɾ��col��
*/
void remove(int col)
{
    struct _node * p = columnHead[col];
    p.right.left = p.left;
    p.left.right = p.right;
    struct _node *p1 = p.down;
    while(p1 != p)
    {
        //��ȡ�����µ�ÿ�����
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
�ظ�col��
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

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

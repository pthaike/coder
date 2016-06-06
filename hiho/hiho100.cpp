/**
http://hihocoder.com/contest/hiho100/problem/1
八数码问题

输入

第1行：1个正整数t，表示数据组数。1≤t≤8。

接下来有t组数据，每组数据有3行，每行3个整数，包含0~8，每个数字只出现一次，其中0表示空位。

输出

第1..t行：每行1个整数，表示该组数据解的步数。若无解输出"No Solution!"

样例输入
3
1 2 3
4 5 6
7 8 0
1 2 3
4 5 6
8 7 0
8 0 1
5 7 4
3 6 2
样例输出
0
No Solution!
25
*/


#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <queue>
#include <math.h>

using namespace std;

int factorial[9];
int target[][3] = {1,2,3,4,5,6,7,8,0};

int cantor(int num[][3])
{
    int x = 0;
    int count;
    bool used[9];
    memset(used, false, sizeof(used));
    for(int i = 0; i < 9; i ++)
    {
        count = 0;
        for(int j = 0; j < num[i/3][i%3]; j++)
        {
            if(!used[j])
                count ++;
        }
        x = x +  count * factorial[8 - i];
        used[num[i/3][i%3]] = true;
    }
    return x;
}

void unCantor(int x, int num[][3])
{
    int mod, count;
    bool used[9];
    memset(used, false, sizeof(used));
    for(int i = 0; i < 9; i ++)
    {
        mod = x / factorial[8-i];
        count = 0;
        int j;
        for(j = 0; j < 9 && count < mod+1; j ++)
        {
            if(!used[j])
                count ++;
        }
        num[i/3][i%3] = j -1;
        used[j-1] = true;
        x %= factorial[8-i];
    }
}



int search(int matrix[][3])
{
    int step[362880];
    queue<int> q;
    int cur = cantor(matrix);
    int end = cantor(target);
    int x, y, tmpx, tmpy, tmp, pre;
    int next[4][2] = {{1, 0}, {0, -1}, {-1, 0}, {0, 1}};
    for(int i = 0 ; i < 362880; i ++)
        step[i] = -1;
    step[cur] = 0;
    q.push(cur);
    while(!q.empty())
    {
        cur = q.front();
        q.pop();
        if(cur == end)
            return step[cur];
        unCantor(cur, matrix);
        for(int i = 0; i < 9; i++)
        {
            if(matrix[i/3][i%3] == 0)
            {
                x = i / 3;
                y = i % 3;
                break;
            }
        }
        for(int i = 0; i < 4; i ++)
        {
            tmpx = x + next[i][0];
            tmpy = y + next[i][1];
            if(tmpx >= 0 && tmpx < 3 && tmpy >= 0 && tmpy < 3)
            {
                tmp = matrix[x][y];
                matrix[x][y] = matrix[tmpx][tmpy];
                matrix[tmpx][tmpy] = tmp;
                pre = cantor(matrix);
                if(step[pre] < 0)
                {
                    if(pre == end)
                        return step[cur] + 1;
                    step[pre] = step[cur] + 1;
                    q.push(pre);
                }
                tmp = matrix[x][y];
                matrix[x][y] = matrix[tmpx][tmpy];
                matrix[tmpx][tmpy] = tmp;
            }
        }
    }
    return -1;
}

struct node
{
    int statu;
    int g;
    int h;
    int f;
    int x;
    int y;
};


/*************************************************************
利用小顶堆来实现优先队列，下标从0开始
*************************************************************/

/**
对于节点nod， 从上而下调整堆，
*/
void adjustHead(struct node d[], int n, int nod)
{
    if(nod > n || nod < 0)
        return;
    int j = nod;
    struct node tmp;
    while(2*j+1 <= n)
    {
        if(d[2 * j + 1].f < d[j].f && (2 * j + 2 > n || 2 * j + 2 <= n && d[2 * j + 1].f <= d[2 * j + 2].f))
        {
            tmp = d[j];
            d[j] = d[2 * j + 1];
            d[2 * j + 1] = tmp;
            j = 2 * j + 1;
        }
        else if(2 * j + 2 <= n && d[2 * j + 2].f < d[j].f && d[2 * j + 2].f <= d[2 * j + 1].f)
        {
            tmp = d[j];
            d[j] = d[2 * j + 2];
            d[2 * j + 2] = tmp;
            j = 2 * j + 2;
        }
        else
            break;
    }
}

/**
初始化小顶堆
*/
void initHead(struct node d[], int n)
{
    int m = (n - 1) / 2;
    for(int i = m; i >= 0; i--)
    {
        adjustHead(d, n, i);
    }
}

/**
获得堆顶元素,并且重新调整堆
返回堆顶元素
*/
struct node minHead(struct node d[], int n)
{
    struct node res = d[0];
    d[0] = d[n];
    adjustHead(d, n-1, 0);
    return res;
}

/**
添加元素nod到堆里面,重新调整堆,并且返回堆大小
*/
int addHead(struct node d[], int n, struct node nod)
{
    d[n] = nod;
    int j = n;
    struct node tmp;
    while(j >= 0)
    {
        if(d[j].f < d[(j-1)/2].f)
        {
            tmp = d[j];
            d[j] = d[(j-1)/2];
            d[(j-1)/2] = tmp;
            j = (j-1)/2;
        }
        else
            break;
    }
    return n + 1;
}

int mhtDist(int matrix[][3])
{
    int dis = 0;
    int x,y;
    for(int i = 0; i < 3; i ++)
    {
        for(int j = 0; j < 3; j++)
        {
            if(matrix[i][j] == 0)
            {
                x = 2;
                y = 2;
            }
            else
            {
                x = (matrix[i][j] - 1) / 3;
                y = (matrix[i][j] - 1) % 3;
            }
            dis = dis + abs(i - x) + abs(j - y);
        }
    }
    return dis;
}

int find(struct node d[], int n, int statu)
{
    for(int i =0; i < n; i++)
    {
        if(d[i].statu == statu)
            return i;
    }
    return -1;
}

int heuristic_search(int matrix[][3])
{
    struct node open[36288];
    bool closed[362880];
    memset(closed, false, sizeof(closed));
    int cur = cantor(matrix);
    int end = cantor(target);
    int openlen = 0;
    int x,y;
    for(int i = 0; i < 9; i++)
    {
        if(matrix[i/3][i%3] == 0)
        {
            x = i / 3;
            y = i % 3;
            break;
        }
    }
    struct node nod;
    nod.statu = cur;
    nod.x = x;
    nod.y = y;
    nod.g = 0;
    nod.h = mhtDist(matrix);
    nod.f = nod.g + nod.h;
    open[openlen++] = nod;
    initHead(open, openlen-1);
    int pre;
    int next[4][2] = {{1, 0}, {0, -1}, {-1, 0}, {0, 1}};
    int count = 0;
    while(openlen >= 0)
    {

        struct node tmp = minHead(open, --openlen);
        if(tmp.statu == end)
        {
            return tmp.g;
        }
        closed[tmp.statu] = true;
        unCantor(tmp.statu, matrix);
        for(int i = 0; i < 4; i++)
        {
            x = tmp.x + next[i][0];
            y = tmp.y + next[i][1];
            if(x >= 0 && x <= 2 && y >= 0 && y <= 2)
            {
                int t = matrix[x][y];
                matrix[x][y] = matrix[tmp.x][tmp.y];
                matrix[tmp.x][tmp.y] = t;
                pre = cantor(matrix);
                if(pre == end)
                    return tmp.g + 1;
                if(!closed[pre])
                {
                    t = find(open,openlen,pre);
                    int h = mhtDist(matrix);
                    if(t >= 0)
                    {
                        open[t].f = open[t].f < open[t].g+1+h ? open[t].f : open[t].g+1+h;
                    }
                    else
                    {
                        struct node nnod;
                        nnod.statu = pre;
                        nnod.g = tmp.g+1;
                        nnod.h = h;
                        nnod.f = nnod.h + nnod.g;
                        nnod.x = x;
                        nnod.y = y;
                        addHead(open, openlen++, nnod);
                    }
                }
                t = matrix[x][y];
                matrix[x][y] = matrix[tmp.x][tmp.y];
                matrix[tmp.x][tmp.y] = t;
            }
        }
        count ++;
    }
    return -1;
}


int main(void)
{
    int t;
    int matrix[3][3];
    factorial[0] = 1;
    for(int i =1; i < 9; i ++)
        factorial[i] = factorial[i-1] * i;

    scanf("%d", &t);
    for(int n = 0; n < t; n++)
    {
        for(int i = 0; i < 9; i++)
        {
            scanf("%d", &matrix[i/3][i%3]);
        }
        //int res = search(matrix);
        int res = heuristic_search(matrix);
        if(res < 0)
            printf("No Solution!\n");
        else
            printf("%d\n", res);
    }
    return 0;
}

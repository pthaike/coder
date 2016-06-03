/*
http://hihocoder.com/problemset/problem/1308

描述

小Hi：小Ho你会下国际象棋么？

小Ho：应该算会吧，我知道每个棋子的移动方式，马走日象飞田什么的...

小Hi：象飞田那是中国象棋啦！

小Ho：哦，对。国际象棋好像是走斜线来着。

小Hi：不过马走日倒是对了。国际象棋中的马一般叫做骑士，关于它有个很有意思的问题。

小Ho：什么啊？

小Hi：骑士巡游问题，简单来说就是关于在棋盘上放置若干个骑士，然后探究移动这些骑士是否能满足一定的而要求。举个例子啊：一个骑士从起始点开始，能否经过棋盘上所有的格子再回到起点。

小Ho：哦，看上去好像很难的样子。

小Hi：其实也还好了。简单一点的比如棋盘上有3个骑士，能否通过若干次移动走到一起。

小Ho：能够么？

小Hi：当然能够了。由于骑士特殊的移动方式，放置在任何一个初始位置的骑士，都可以通过若干次移动到达棋盘上任意一个位置。

小Ho：那么只要选定一个位置，把它们全部移动过去就好了是吧？

小Hi：是的，那么这里又有另一个问题了：要选择哪一个位置汇合，使得3个骑士行动的总次数最少？

小Ho：嗯，这个好像不是很难，让我想一想。

提示：骑士问题

输入

第1行：1个正整数t，表示数据组数，2≤t≤10。

第2..t+1行：用空格隔开的3个坐标, 每个坐标由2个字符AB组成，A为'A'~'H'的大写字母，B为'1'~'8'的数字，表示3个棋子的初始位置。

输出

第1..t行：每行1个数字，第i行表示第i组数据中3个棋子移动到同一格的最小行动步数。

样例输入
2
A1 A1 A1
B2 D3 F4
样例输出
0
2

*/
#include <stdio.h>
#include <queue>
using namespace std;

struct node
{
    int x;
    int y;
};

void bfs(struct node start, int chess[][8])
{
    queue<struct node> q;
    struct node cur;
    int x, y;
    int a[][2] = {{1, 2}, {1, -2}, {2, 1}, {2, -1}, {-1, 2}, {-1, -2}, {-2, -1}, {-2, 1}};
    q.push(start);
    chess[start.x][start.y] = 0;
    while(!q.empty())
    {
        cur = q.front();
        q.pop();
        for(int i = 0; i < 8; i++)
        {
            x = a[i][0] + cur.x;
            y = a[i][1] + cur.y;
            if(x >= 0 && x < 8 && y >= 0 && y < 8 && chess[x][y] < 0)
            {
                struct node cor = {x, y};
                chess[x][y] = chess[cur.x][cur.y] + 1;
                q.push(cor);
            }
        }
    }
}

int search(struct node* start)
{
    int chess[3][8][8];
    int minres = 1000;
    int tmp;
    //for(int i = 0; i < 3*8*8; i++)
    //    chess[i/64][i/8][i%8] = -1;
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 8; j++)
            for(int k = 0; k < 8; k ++)
                chess[i][j][k] = -1;
    for(int i = 0; i < 3; i++)
    {
        bfs(start[i], chess[i]);
    }
    for(int i = 0; i < 64; i ++)
    {
        tmp = chess[0][i/8][i%8] + chess[1][i/8][i%8] + chess[2][i/8][i%8];
        minres = minres > tmp ? tmp : minres;
    }
     return minres;
}

int main(void)
{
    int t;
    int flag[8][8] = {0};
    int matrix[8][8] = {0};
    char x,c;
    int y;
    struct node cor[3];
    scanf("%d", &t);
    for(; t > 0; t--)
    {
        for(int i = 0; i < 3; i++)
        {
            scanf("%c%c%d", &c,&x,&y);
            cor[i].x = x - 'A';
            cor[i].y = y - 1;
        }
        printf("%d\n", search(cor));
    }
    return 0;
}

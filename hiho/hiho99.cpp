/*
http://hihocoder.com/problemset/problem/1308

����

СHi��СHo����¹�������ô��

СHo��Ӧ�����ɣ���֪��ÿ�����ӵ��ƶ���ʽ�������������ʲô��...

СHi������������й���������

СHo��Ŷ���ԡ����������������б�����š�

СHi�����������յ��Ƕ��ˡ����������е���һ�������ʿ���������и�������˼�����⡣

СHo��ʲô����

СHi����ʿѲ�����⣬����˵���ǹ����������Ϸ������ɸ���ʿ��Ȼ��̽���ƶ���Щ��ʿ�Ƿ�������һ���Ķ�Ҫ�󡣾ٸ����Ӱ���һ����ʿ����ʼ�㿪ʼ���ܷ񾭹����������еĸ����ٻص���㡣

СHo��Ŷ������ȥ������ѵ����ӡ�

СHi����ʵҲ�����ˡ���һ��ı�����������3����ʿ���ܷ�ͨ�����ɴ��ƶ��ߵ�һ��

СHo���ܹ�ô��

СHi����Ȼ�ܹ��ˡ�������ʿ������ƶ���ʽ���������κ�һ����ʼλ�õ���ʿ��������ͨ�����ɴ��ƶ���������������һ��λ�á�

СHo����ôֻҪѡ��һ��λ�ã�������ȫ���ƶ���ȥ�ͺ����ǰɣ�

СHi���ǵģ���ô����������һ�������ˣ�Ҫѡ����һ��λ�û�ϣ�ʹ��3����ʿ�ж����ܴ������٣�

СHo���ţ���������Ǻ��ѣ�������һ�롣

��ʾ����ʿ����

����

��1�У�1��������t����ʾ����������2��t��10��

��2..t+1�У��ÿո������3������, ÿ��������2���ַ�AB��ɣ�AΪ'A'~'H'�Ĵ�д��ĸ��BΪ'1'~'8'�����֣���ʾ3�����ӵĳ�ʼλ�á�

���

��1..t�У�ÿ��1�����֣���i�б�ʾ��i��������3�������ƶ���ͬһ�����С�ж�������

��������
2
A1 A1 A1
B2 D3 F4
�������
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

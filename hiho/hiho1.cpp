/**
http://hihocoder.com/contest/hiho1/problem/1

样例输入
3
abababa
aaaabaa
acacdas
样例输出
7
5
3
*/

#include <stdio.h>
#include <stdlib.h>

int palindrome(char*str)
{
    return 1;
}

int main(void)
{
    int n;
    char * str;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        scanf("%s", str);
        printf("%d\n", palindrome(str));
    }
    return 0;
}

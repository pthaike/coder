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
#include <string.h>
#include <memory.h>

#define MAXLEN 1000000

char str[MAXLEN + 1];

/**
采用中心枚举的策略
*/
int longPalindrome()
{
    int len = strlen(str);
    int maxlen = 1;
    for(int i = 0; i < len-1; i++)
    {
        int j;
        for(j = 1; i - j >= 0 && i + j < len; j ++)
            if(str[i - j] != str[i + j])
                break;
        maxlen = maxlen > (j - 1) * 2 + 1 ? maxlen : (j - 1) * 2 + 1;
        for(j = 0; i - j >= 0 && i + j + 1 < len; j++)
            if(str[i-j] != str[i+j+1])
                break;
        maxlen = maxlen > 2 * j ? maxlen : 2 * j;
    }
    return maxlen;
}

/**
manacher 策略
*/
int manacher()
{
    int len = strlen(str);
    int maxlen = 1;
    char helpstr[2 * len + 2];
    for(int i = 0; i <= len; i++)
    {
        helpstr[2 * i] = '#';
        helpstr[2 * i + 1] = str[i];
    }
    int helplen = strlen(helpstr);
    int f[helplen];
    int center = 1;
    int rb = 2;
    f[0] = 0;
    f[1] = 1;
    for(int i = 2; i < helplen; i ++)
    {
        if(i > rb)
            f[i] = 0;
        else
            f[i] = (i + f[2 * center - i]) < rb ? f[2 * center - i] : center + f[center] - i;
        while(helpstr[i-f[i]-1] == helpstr[i+f[i]+1] && (i+f[i]+1) > rb && i-f[i]-1 >= 0)f[i] ++;
        if(i + f[i] > rb)
        {
            rb = i + f[i];
            center = i;
        }

        maxlen = maxlen > f[i] ? maxlen : f[i];
    }
    return maxlen;
}

int main(void)
{
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        scanf("%s", str);
        //printf("%d\n", longPalindrome());
        printf("%d\n", manacher());
    }
    return 0;
}

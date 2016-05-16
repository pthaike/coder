/*
Write an algorithm to determine if a number is "happy".

A happy number is a number defined by the following process: Starting with any positive integer, replace the number by the sum of the squares of its digits, and repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1. Those numbers for which this process ends in 1 are happy numbers.

Example: 19 is a happy number

12 + 92 = 82
82 + 22 = 68
62 + 82 = 100
12 + 02 + 02 = 1

*/

#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

bool isHappy(int n)
{
    int m = n;
    int sum = n;
    int a = 0;
    int tmpsum = n;
    vector<int> v;
    while(sum != 1){
        v.push_back(sum);
        sum = 0;
        while(m != 0)
        {
            a = m % 10;
            sum = sum + a * a;
            m /= 10;
        }
        if(!(find(v.begin(), v.end(), sum) == v.end()))
            return false;
        m = sum;
    }
    return true;
}
/*
int main(void)
{
    int n;
    while(scanf("%d", &n)!=EOF)
    {
        if(isHappy(n))
        {
            printf("Happy\n");
        }
        else
        {
            printf("unhappy\n");
        }
    }
    return 0;
}
*/

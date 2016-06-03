/*http://hihocoder.com/contest/hiho98/problem/1
(((a กั b) กั c ) กั d)
((a กั b) กั (c กั d))
*/



#include <stdio.h>

int a[4];
int nowNumber[4];
int ops[] ={0,0,0};
int opType[] = {1,2,3,4,5,6}; //{+,-,*,/,ทด-,ทด/}
bool used[4];

double calhelper(double a, double b, int op)
{
    double res = 0;
    switch(op)
    {
    case 1:
        res = a + b;
        break;
    case 2:
        res = a - b;
        break;
    case 3:
        res = a * b;
        break;
    case 4:
        res = a / b;
        break;
    case 5:
        res = b - a;
        break;
    case 6:
        res = b / a;
        break;
    }
    return res;
}


bool calculate(int* number, int* op)
{
    double res = number[0];
    double res1;
    for(int i = 0; i < 3; i++)
    {
        if(op[i] == 4 && number[i+1] == 0)
            return false;
        if(op[i] == 6 && res == 0.0)
            return false;
        res = calhelper(res, number[i+1], op[i]);
    }
    if(res == 24.0)
        return true;
    res = 0;
    if(op[0] == 4 && number[1] == 0
       || op[0] == 6 && number[0] == 0
       || op[2] == 4 && number[3] == 0
       || op[2] == 6 && number[2] == 0)
        return false;
    res = calhelper(number[0], number[1], op[0]);
    if(op[1] == 6 && res == 0.0)
        return false;
    res1 = calhelper(number[2], number[3], op[2]);
    if(op[1] == 4 && res1 == 0.0)
        return false;
    res = calhelper(res, res1, op[1]);
    if (res == 24.0)
        return true;
    return false;
}

bool makeOperation(int depth)
{
    if(depth >= 3)
    {
        return calculate(nowNumber, ops);
    }
    for(int i = 0; i < 6; i++)
    {
        ops[depth] = opType[i];
        if(makeOperation(depth+1))
            return true;
    }
    return false;
}

bool makeNumber(int depth)
{
    if(depth >= 4)
    {
        return makeOperation(0);
    }
    for(int i = 0; i < 4; i++)
    {
        if(!used[i])
        {
            nowNumber[depth] = a[i];
            used[i] = true;
            if(makeNumber(depth+1))
                return true;
            used[i] = false;
        }
    }
    return false;
}

int main(void)
{
    int t;
    scanf("%d", &t);
    for(int i = 0; i < t; i++){
        for(int m = 0; m < 4; m ++)
            used[m] = false;
        for(int j = 0; j < 4; j++)
            scanf("%d", &a[j]);
        if(makeNumber(0))
        {
            printf("Yes\n");;
        }
        else
            printf("No\n");
    }
    return 0;
}

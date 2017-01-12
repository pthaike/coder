/**
Given a positive integer num, write a function which returns True if num is a perfect square else False.

Note: Do not use any built-in library function such as sqrt.

Example 1:

Input: 16
Returns: True
Example 2:

Input: 14
Returns: False
*/
class Solution {
public:
    bool isPerfectSquare(int num) {
        if(num == 1) return true;
        for(int i = 1; i <= sqrt(num); i++)
        {
            if(i * i == num)
                return true;
        }
        return false;
    }
};

/**
class Solution {
public:
    bool isPerfectSquare(int num) {
        long i = 1;
        long sum=1;
        while(sum < num)
        {
            i += 2;
            sum += i;
        }
        return sum == num;
    }
};
*/

/**
Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

For example,
"A man, a plan, a canal: Panama" is a palindrome.
"race a car" is not a palindrome.

Note:
Have you consider that the string might be empty? This is a good question to ask during an interview.

For the purpose of this problem, we define empty string as valid palindrome.

*/

/*
class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0;
        int j = s.size()-1;
        while(i < j)
        {
            if(!isCharacter(s[i]))
            {
                i ++;
                continue;
            }
            if(!isCharacter(s[j]))
            {
                j --;;
                continue;
            }
            if(s[i] != s[j])
            {
                printf("%c %c\n", s[i], s[j]);
                if((s[i] >= '0' && s[i] <= '9') && (s[j] >= '0' && s[j] <= '9'))
                {
                    return false;
                }
                else if(!((s[i] >= 'a' && s[i] <= 'z' || s[i] >= 'A' && s[i] <= 'Z')
                && (s[j] >= 'a' && s[j] <= 'z' || s[j] >= 'A' && s[j] <= 'Z')
                &&(s[i]- s[j] == ('z'-'Z') || s[j] - s[i] == ('z'-'Z'))))
                {
                    return false;
                }
            }
            i++;
            j--;
        }
        return true;
    }
    bool isCharacter(char c)
    {
        if(c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z' || c >= '0' && c <= '9')
            return true;
        return false;
    }
};

*/

#include <stdio.h>
#include <string>
using namespace std;
int main(void)
{

    if(isdigit('5'))
        printf("0");
    else
        printf("1");
    return 0;
}

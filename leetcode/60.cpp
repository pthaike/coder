/**
https://leetcode.com/problems/permutation-sequence/
The set [1,2,3,бн,n] contains a total of n! unique permutations.

By listing and labeling all of the permutations in order,
We get the following sequence (ie, for n = 3):

"123"
"132"
"213"
"231"
"312"
"321"
Given n and k, return the kth permutation sequence.
*/

class Solution {
public:
    string getPermutation(int n, int k) {
        string s(n,'0');
        int sum = 1;
        for(int i = 1; i <= n; i++)
        {
            sum *= i;
            s[i-1] += i;
        }
        k--;
        for(int i = 0; i < n; i++)
        {
            sum /= (n-i);
            int a = i + k / sum;
            char c = s[a];
            for(int j = a; j > i; j--)
                s[j] = s[j-1];
            s[i] = c;
            k %= sum;
        }
        return s;
    }
};

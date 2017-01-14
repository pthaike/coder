/**
The demons had captured the princess (P) and imprisoned her in the bottom-right corner of a dungeon. The dungeon consists of M x N rooms laid out in a 2D grid. Our valiant knight (K) was initially positioned in the top-left room and must fight his way through the dungeon to rescue the princess.

The knight has an initial health point represented by a positive integer. If at any point his health point drops to 0 or below, he dies immediately.

Some of the rooms are guarded by demons, so the knight loses health (negative integers) upon entering these rooms; other rooms are either empty (0's) or contain magic orbs that increase the knight's health (positive integers).

In order to reach the princess as quickly as possible, the knight decides to move only rightward or downward in each step.


Write a function to determine the knight's minimum initial health so that he is able to rescue the princess.

For example, given the dungeon below, the initial health of the knight must be at least 7 if he follows the optimal path RIGHT-> RIGHT -> DOWN -> DOWN.

-2 (K)	-3	3
-5	-10	1
10	30	-5 (P)

Notes:

The knight's health has no upper bound.
Any room can contain threats or power-ups, even the first room the knight enters and the bottom-right room where the princess is imprisoned.

*/

#include<stdio.h>
#include<vector>

using namespace std;

/*
class Solution {
public:
    int min=100000;
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        helper(dungeon, 0, 0, dungeon[0][0], 100000);
        return min;
    }
    int helper(vector<vector<int>>& dungeon, int x, int y, int cost, int max)
    {
        int tmpmax = max < cost ? max : cost;
        if(x == dungeon[0].size()-1 && y == dungeon.size()-1)
        {
            if(tmpmax <=0)
                min = min < 1-tmpmax ? min : 1-tmpmax;
            else
                min = 1;
            return min;
        }
        if(x < dungeon[0].size() - 1)
        {
            helper(dungeon, x + 1, y, cost + dungeon[y][x+1], tmpmax);
            if(min == 1)
                return min;
        }
        if(y < dungeon.size() -1)
        {

            helper(dungeon, x, y + 1, cost + dungeon[y+1][x], tmpmax);
            if(min == 1)
                return min;
        }
        return min;
    }
};
*/
/*
class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size();
        int n = dungeon[0].size();
        vector<vector<int>> dp(m+1, vector<int>(n+1, 100000));
        dp[m][n-1] = 1;
        dp[m-1][n] = 1;
        for(int i = m-1; i >=0; i--)
        {
            for(int j = n-1; j >= 0; j--)
            {
                int right = dp[i][j+1] - dungeon[i][j];
                int down = dp[i+1][j] - dungeon[i][j];
                int min = right < down ? right : down;
                dp[i][j] = min > 0 ? min : 1;
            }
        }
        return dp[0][0];
    }

};


int main(void)
{
    Solution s;
    vector<int> v1, v2;
    vector<vector<int> > v;
    v1.push_back(-3);
    v1.push_back(-7);
    v.push_back(v1);
    v.push_back(v2);
    printf("%d",s.calculateMinimumHP(v));

    return 0;
}
*/


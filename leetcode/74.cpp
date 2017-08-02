/**
Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.
For example,

Consider the following matrix:

[
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
Given target = 3, return true.
*/
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        if(m == 0) return false;
        int n = matrix[0].size();
        int y = 0, x = n-1;
        while(x >= 0 && y < m)
        {
            //printf("%d %d\n", y, x);
            if(target == matrix[y][x])
                return true;
            else if(target > matrix[y][x])
                y ++;
            else
                m =y;
            if(m == y) break;
        }
        if(m == y && m < matrix.size())
        {
            //printf("binsearch\n");
            int left = 0, right = x;
            while(left <= right)
            {
                int mid = (left + right) / 2;
                if(matrix[y][mid] == target)
                    return true;
                else if(target > matrix[y][mid])
                    left = mid + 1;
                else
                    right = mid -1;
            }
        }
        return false;
    }
};

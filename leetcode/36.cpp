/**
Determine if a Sudoku is valid, according to: Sudoku Puzzles - The Rules.

The Sudoku board could be partially filled, where empty cells are filled with the character '.'.


A partially filled sudoku which is valid.

Note:
A valid Sudoku board (partially filled) is not necessarily solvable. Only the filled cells need to be validated.
*/

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i = 0; i < board.size(); i++)
        {
            int flag[10] = {0};
            for(int j = 0; j < board[0].size(); j++)
            {
                if(board[i][j] != '.')
                {
                    int a = board[i][j] - '0';
                    if(flag[a] == 1)
                        return false;
                    flag[a] = 1;
                }

            }
        }
        for(int i = 0; i < board.size(); i++)
        {
            int flag[10] = {0};
            for(int j = 0; j < board[0].size(); j++)
            {
                if(board[j][i] != '.')
                {
                    int a = board[j][i] - '0';
                    if(flag[a] == 1)
                        return false;
                    flag[a] = 1;
                }

            }
        }
        for(int i = 0; i < 3; i++)
        {
            for(int j = 0; j < 3; j++)
                if(!check(board, i*3, j*3))
                return false;
        }
        return true;
    }

    bool check(vector<vector<char>>& board, int x, int y)
    {
        int flag[10] = {0};
        for(int i = 0; i < 3; i++)
        {
            for(int j = 0; j < 3; j++)
            {
                if(board[i+x][j+y] != '.')
                {
                    int a = board[i+x][j+y] - '0';
                    if(flag[a] == 1)
                        return false;
                    flag[a] = 1;
                }
            }
        }
        return true;
    }
};

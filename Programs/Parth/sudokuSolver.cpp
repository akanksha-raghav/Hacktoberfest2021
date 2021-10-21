//In this we need to find the solution of a sudoku game
//At position of "." check can we put any character
//If we can put the character the put it and call the funtion again 
//If we cannot put any number then return false 
//Till the point we whole matrix is completed then push back into answer

class Solution
{

public:
    bool canPlace(vector<vector<char>> &board, int row, int col, char ch)
    {
        int rowIdx = 3 * (row / 3), colIdx = 3 * (col / 3);

        for (int idx = 0; idx < 9; idx++)
        {
            if (board[row][idx] == ch)
            {
                return false;
            }

            if (board[idx][col] == ch)
            {
                return false;
            }

            if (board[rowIdx + (idx / 3)][colIdx + (idx % 3)] == ch)
            {
                return false;
            }
        }

        return true;
    }

    bool solveSudokuu(vector<vector<char>> &board)
    {
        for (int row = 0; row < 9; row++)
        {
            for (int col = 0; col < 9; col++)
            {
                if (board[row][col] == '.')
                {
                    for (char ch = '1'; ch <= '9'; ch++)
                    {
                        if (canPlace(board, row, col, ch))
                        {
                            board[row][col] = ch;

                            if (solveSudokuu(board))
                            {
                                return true;
                            }

                            board[row][col] = '.';
                        }
                    }

                    return false;
                }
            }
        }

        return true;
    }

    void solveSudoku(vector<vector<char>> &board)
    {
        solveSudokuu(board);
    }
};
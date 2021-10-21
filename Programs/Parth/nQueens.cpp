// In this ques we need to place Queens on a given size of board suck that they do not intersect each other's path
//starting from columns check wheather it is safe to place queen if it is then put 1 over that place and call for next row
//if it is not safe to place then put 2 over that place
// When call reaches at last row make a sting vector at 1 palce Q and at 2 or 0 palce .

class Solution
{
public:
    vector<vector<string>> answer;

    bool isSafe(vector<vector<int>> &arr, int row, int col)
    {
        for (int curRow = row - 1; curRow >= 0; curRow--)
        {
            if (arr[curRow][col] == 1)
            {
                return false;
            }
        }

        for (int curRow = row - 1, curCol = col - 1; curRow >= 0 && curCol >= 0; curRow--, curCol--)
        {
            if (arr[curRow][curCol] == 1)
            {
                return false;
            }
        }

        for (int curRow = row - 1, curCol = col + 1; curRow >= 0 && curCol < arr[0].size(); curRow--, curCol++)
        {
            if (arr[curRow][curCol] == 1)
            {
                return false;
            }
        }

        return true;
    }

    void nQueen(vector<vector<int>> &arr, int row)
    {
        if (row == arr.size())
        {
            vector<string> ans;

            for (int currow = 0; currow < arr.size(); currow++)
            {
                string rowAns;

                for (int col = 0; col < arr[0].size(); col++)
                {
                    if (arr[currow][col] == 0 || arr[currow][col] == 2)
                    {
                        rowAns.append(".");
                    }

                    else
                    {
                        rowAns.append("Q");
                    }
                }

                ans.push_back(rowAns);
            }

            answer.push_back(ans);

            return;
        }

        for (int col = 0; col < arr.size(); col++)
        {
            if (isSafe(arr, row, col))
            {
                arr[row][col] = 1;

                nQueen(arr, row + 1);
            }

            arr[row][col] = 2;
        }

        return;
    }

    vector<vector<string>> solveNQueens(int n)
    {
        vector<vector<int>> arr;

        for (int rowidx = 0; rowidx < n; rowidx++)
        {
            vector<int> temp;

            for (int colidx = 0; colidx < n; colidx++)
            {
                temp.push_back(0);
            }

            arr.push_back(temp);
        }

        nQueen(arr, 0);

        return answer;
    }
};
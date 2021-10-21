//In this we need do make paths through 0 and 1 is obstacle
// 0 0 0
// 1 0 1
// 0 0 0
// Answer is rddr

// Store number in temp and Move in direction r d t l blindly if we encounter 1 then return and make that number temp 
// keep moving till last row and col and print the ans as base case and return 

#include <iostream>
#include <string.h>
#include <vector>

using namespace std;

void floodfill(vector<vector<int>> &maze, int row, int col, string ans)
{

    if (row < 0 || col < 0 || row >= maze.size() || col >= maze[0].size() || maze[row][col] == 1)
    {
        return;
    }

    if (row == maze.size() - 1 && col == maze[0].size() - 1)
    {
        cout << ans << endl;

        return;
    }

    int temp = maze[row][col];

    maze[row][col] = 1;

    floodfill(maze, row, col + 1, ans + "r");

    floodfill(maze, row + 1, col, ans + "d");

    floodfill(maze, row - 1, col, ans + "t");

    floodfill(maze, row, col - 1, ans + "l");

    maze[row][col] = temp;

    return;
}

int main()
{
    int row, col;

    cin >> row >> col;

    vector<vector<int>> arr(row, vector<int>(col));

    for (int idx1 = 0; idx1 < row; idx1++)
    {
        for (int idx2 = 0; idx2 < col; idx2++)
        {
            cin >> arr[idx1][idx2];
        }
    }

    floodfill(arr, 0, 0, "");
}
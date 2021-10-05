/*
Knight Reach
Find the minimum number of steps for a Knight in a chess board to reach from a source/start location to destination/final location.
Sample Test case :
Input :
8 1 1 8 
Output :
6 
*/

#include <bits/stdc++.h>
using namespace std;

//Recursive function that traverses all possible paths of Knight from source to destination location and return the moves required for minimum path
int knight(int board[8][8], int moves[8][2], int x, int y, int dx, int dy, int c = 0, int min = INT_MAX)
{
    //If the Knight goes out of the board then that path is invalid
    //If the Knight returns to an already visited square or the number of moves in current path exceeds the number of moves of minimum path found so far, then the current path is not the minimum path.
    if (x > 8 || x < 1 || y > 8 || y < 1 || board[x - 1][y - 1] == 1 || min <= c)
        return INT_MAX;

    //If Knight reaches the destination path, return the number of moves of the path.
    if (x == dx && y == dy)
        return c;

    //Mark the square as visited (1)
    board[x - 1][y - 1] = 1;

    //Traverse all possible paths from current square using all possible 8 moves from current square
    //Compare the paths and return the minimum number of moves.
    int m[8];
    for (int i = 1; i <= 8; i++)
    {
        m[i - 1] = knight(board, moves, x + moves[i - 1][0], y + moves[i - 1][1], dx, dy, c + 1, min);
        min = (m[i - 1] < min) ? m[i - 1] : min;
    }

    //Before returning, mark the current square as unvisited (0) so that the square will be available for other possible paths.
    board[x - 1][y - 1] = 0;
    return min;
}

int main()
{
    int sx, sy, dx, dy;
    //Initialise 8x8 chess board with 0
    int board[8][8] = {0};
    //All possible moves of knight in {x-move, y-move} format
    int moves[8][2] = {{1, 2}, {-1, 2}, {2, 1}, {2, -1}, {-2, 1}, {-2, -1}, {1, -2}, {-1, -2}};

    // Take row number and column number of source and destination locations as input : (sx, sy) and (dx, dy)
    cin >> sx >> sy >> dx >> dy;

    //Print the function which returns minimum number of moves
    cout << knight(board, moves, sx, sy, dx, dy);
    return 0;
}
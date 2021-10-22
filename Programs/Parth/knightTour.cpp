//We are Given size of keyboard and position of knight we have to generate all the moves that knight
//does so that whole board is being covered
//we put a number on which knight is present right now  and call for next move from position
//row - 2 col + 1 and then clockwise it knight has already visited the we make it previous
// number and return at previous position
// and when the total number are filled we print out 2D array

#include <iostream>
#include <vector>

using namespace std;

void display(vector<vector<int>> &ans, int n)
{
    for (int idx1 = 0; idx1 < n; idx1++)
    {
        for (int idx2 = 0; idx2 < n; idx2++)
        {
            cout << ans[idx1][idx2] << " ";
        }

        cout << endl;
    }

    cout << endl;
}

void printKnightsTour(vector<vector<int>> &ans, int row, int col, int n, int counter)
{

    if (row < 0 || col < 0 || row >= n || col >= n || ans[row][col] != 0)
    {
        return;
    }

    ans[row][col] = counter;

    if (counter == n * n)
    {
        display(ans, n);
    }

    counter++;

    printKnightsTour(ans, row - 2, col + 1, n, counter);

    printKnightsTour(ans, row - 1, col + 2, n, counter);

    printKnightsTour(ans, row + 1, col + 2, n, counter);

    printKnightsTour(ans, row + 2, col + 1, n, counter);

    printKnightsTour(ans, row + 2, col - 1, n, counter);

    printKnightsTour(ans, row + 1, col - 2, n, counter);

    printKnightsTour(ans, row - 1, col - 2, n, counter);

    printKnightsTour(ans, row - 2, col - 1, n, counter);

    ans[row][col] = 0;
}

int main()
{
    int n, row, col;

    cin >> n;

    cin >> row >> col;

    vector<vector<int>> ans;

    for (int idx1 = 0; idx1 < n; idx1++)
    {
        vector<int> small_ans;

        for (int idx2 = 0; idx2 < n; idx2++)
        {
            small_ans.push_back(0);
        }

        ans.push_back(small_ans);
    }

    printKnightsTour(ans, row, col, n, 1);

    return 0;
}
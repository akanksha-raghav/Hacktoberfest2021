#include <iostream>
using namespace std;

int main()
{

    int n;
    cin >> n;

    for (int i = 1; i <= 3; i++)
    {
        if (i == 1)
        {
            int c = 0;
            for (int j = 1; j <= n; j++)
            {
                if (j == 1 || j == 2)
                {
                    cout << "  ";
                }
                else
                {
                    if (c % 4 == 0)
                    {
                        cout << "* ";
                    }
                    else
                    {
                        cout << "  ";
                    }
                    c++;
                }
            }
        }
        else if (i == 2)
        {
            for (int j = 1; j <= n; j++)
            {
                if (j % 2 == 0)
                {
                    cout << "* ";
                }
                else
                {
                    cout << "  ";
                }
            }
        }
        else
        {
            for (int j = 1; j <= n; j++)
            {
                if (j % 4 == 1)
                {
                    cout << "* ";
                }
                else
                {
                    cout << "  ";
                }
            }
        }
        cout << endl;
    }

    return 0;
}

#include <string.h>
#include <iostream>

using namespace std;
 
int main()
{
    // input
    string s1 = "example";
 
    // Copy three characters of s1 (starting from position 1)
    string r = s1.substr(1, 3);

    cout << "String is: " << r;
 
    return 0;
}

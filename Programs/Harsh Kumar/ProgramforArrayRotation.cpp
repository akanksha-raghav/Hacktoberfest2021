// C++ program to rotate an array by d elements by using Juggling Algorithm
//Time Complexity: O(n)
//Space Compelxity: O(1)

#include <bits/stdc++.h>
using namespace std;
 
/*Function to get greatest common divisor (gcd) of a and b*/
int gcd(int a, int b)
{
    if (b == 0)
        return a;
 
    else
        return gcd(b, a % b);
}
 
/*Function to left rotate arr[] of size n by d*/
void leftRotate(int arr[], int d, int n)
{
    /* To handle if d >= n */
    d = d % n;
    int g_c_d = gcd(d, n);
    for (int i = 0; i < g_c_d; i++) {
        /* move i-th values of blocks */
        int temp = arr[i];
        int j = i;
 
        while (1) {
            int k = j + d;
            if (k >= n)
                k = k - n;
 
            if (k == i)
                break;
 
            arr[j] = arr[k];
            j = k;
        }
        arr[j] = temp;
    }
}
 
// Function to print an array
void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
}
 
/* Driver program to test above functions */
int main()
{
    int array[] = { 1, 2, 3, 4, 5, 6, 7 };
    int n = sizeof(array) / sizeof(array[0]);
 
    // Function calling
    leftRotate(array, 2, n);
    printArray(array, n);
 
    return 0;
}

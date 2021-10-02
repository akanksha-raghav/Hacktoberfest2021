#include <iostream>
using namespace std;

class BinSearch
{
public:
    float *A;
    int size;
    int l;

    BinSearch();
    void Display();
    int RBinSearch(float A[], int l, int h, int key);
};

// Default cons. to get array elements.
BinSearch ::BinSearch()
{
    int n;
    cout << "Enter size of an array: ";
    cin >> size;
    A = new float[size];
    l = 0;

    cout << "Enter no. of elements to enter: ";
    cin >> n;

    cout << "Enter the elements: \n";
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }
    l = n;
}

// Recursive function to implement binary search!
int BinSearch ::RBinSearch(float A[], int l, int h, int key)
{
    while (l <= h)
    {
        int mid = (l + h) / 2;
        if (A[mid] == key)
        {
            return mid;
        }
        else if (key < A[mid])
        {
            return RBinSearch(A, l, mid - 1, key);
        }
        else
        {
            return RBinSearch(A, mid + 1, h, key);
        }
    }
    // if key not found.
    return -1;
}

// Can display array elements.
void BinSearch ::Display()
{
    cout << "The array elements are: \n";
    for (int i = 0; i < l; i++)
    {
        cout << A[i] << endl;
    }
}

// Main/Driver function
int main()
{
    int key;
    BinSearch BS;
    cout << "Enter element to be searched: ";
    cin >> key;
    cout << "The element is found at index: " << BS.RBinSearch(BS.A, 0, BS.l, key) << endl;
    //BS.Display();

    return 0;
}
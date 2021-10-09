// Merge sort in C

#include <stdio.h>

// Merge two subarrays L and M into arr
void merge( int lb, int mid, int ub) {

    int i = lb;
    int j = mid + 1;
    int k = ub;
    int A[25];
    int B[25];

    while (i < mid && j <= ub)
    {
        if (A[i] <= A[j])
        {
            B[k] = A[i];
            i++;
        }
        else
        {
            B[k] = A[j];
            j++;
        }
        k++;
  }

 
 if(i > mid)
 {
     while( j <= ub)
     {
         B[k] = A[j];
         j++;
         k++;
     }
 }
 else
 {
         while(i<= mid)
         {
             B[k] = A[i];
             i++;
             k++;
         }
 }
     for (k=lb;k<ub;k++)
     {
         A[k] = B[k];
     }
}

// Divide the array into two subarrays, sort them and merge them
void mergeSort(int arr[], int lb, int ub) 
{
  if (lb < ub) {

    int mid = (lb+ub) / 2;

    mergeSort(arr, lb, mid);
    mergeSort(arr, mid + 1, ub);

    // Merge the sorted subarrays
    mergeSort(arr[], lb, mid, ub);
  }
}

// Driver program
int main() {
    int n,c, arr[25];
    int lb, ub;
    printf("Enter the size of the aray: ");
    scanf("%d", &n);
    printf("Enter the elements in the array: ");
    for (c = 0; c < n;c++){
        scanf("%d", &arr[c]);
    }
    merge(arr[],lb, ub);

    printf("Sorted array: \n");
    for (c = 0; c < n;c++){
        printf("%d", arr[c]);
    }
}
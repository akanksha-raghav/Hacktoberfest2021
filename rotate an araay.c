#include<stdio.h>

int display(int arr[],int n)
{
	int i;
	printf("The array is: ");
	for(i=0;i<n;i++)
	{
		printf("%d, ",arr[i]);
	}
	printf("\n");
}

int rotate(int arr[], int d, int n)
{
	int i;
    for (i=0;i<d;i++)
	{
		int temp=arr[0],i;
    	for (i=0; i < n - 1; i++)
        	arr[i] = arr[i + 1];
    	arr[n-1] = temp;
	}
}

int main()
{
	int n,d,i;
	printf("Enter the number of elements: ");
	scanf("%d",&n);
	int arr[n];
	for(i=0;i<n;i++)
	{
		printf("Enter element %d  in the array: " , i+1);
		scanf("%d",&arr[i]);
	}
	display(arr,n);
	printf("Enter the number of elements by which you want to rotate: ");
	scanf("%d",&d);
	rotate(arr,d,n);
	display(arr,n);
}
#include<stdio.h>
 
main()
{
   int array[100], swap, i, n, c, flag = 0, search, first, last, middle ;
 
   printf("Enter the number of elements in array\n");
   scanf("%d",&n);
 
   printf("Enter %d numbers\n", n);
 
   for ( i = 0 ; i < n ; i++ )
      scanf("%d",&array[i]);
      

   for (i=0; i < n; i++)
	{
	for (c = 0 ; c < n - i - 1; c++)
    {
    if (array[c] >= array[c+1]) 
    	{
        swap       = array[c];
        array[c]   = array[c+1];
        array[c+1] = swap;
        flag = 1;
  		}
	  }
	}
	if (flag == 0)
		printf("This array is already sorted!");
    else
    	{
		printf("\nSorted list in ascending order:\n");

  	    for (i = 0; i < n; i++)
        printf("%d\n", array[i]); 
    	}
    	
    printf("\nEnter value to find\n");
    scanf("%d", &search);

     first = 0;
     last = n - 1;
     middle = (first+last)/2;

    while (first <= last)
	 {
      if (array[middle] < search)
      first = middle + 1;
      else if (array[middle] == search)
	   {
       printf("\n%d found at index %d!\n", search, middle);
       break;
     }
    else
      last = middle - 1;
      middle = (first + last)/2;
 	 }
    if (first > last)
    printf("\nNot found! %d isn't present in the list.\n", search);

  return 0;
}

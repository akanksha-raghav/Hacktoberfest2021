// Input n integers and print the multiplication table of each integer using Dynamic Memory Allocation.

#include <stdio.h>
#include <stdlib.h>
int main()
{
    int i,j,n,*p;
    printf("Enter the total number of elements you want to enter:- \n");
    scanf("%d", &n);
    p = (int*)malloc(n*sizeof(int));
    if(p==NULL)
    {
    printf("Insufficient Memory Existing");
    return 0;
    }
    for (i = 0; i < n; i++)
    {
        printf("Enter the Integers:- \n");
        scanf("%d", p+i);
    }
    for(i=0; i<n; i++)
    {
    	for(j=1; j<=10; j++)
    	printf("%dx%d=%d\t\n",*(p+i),j,*(p+i)*j);
	  }
    free(p);
}

------------------------------------------------------------------------------------------------------------------------------------------------------------------------

/*

Output :-  


Enter the total number of elements you want to enter:-
4
Enter the Integers:-
3
Enter the Integers:-
5
Enter the Integers:-
8
Enter the Integers:-
10
3x1=3
3x2=6
3x3=9
3x4=12
3x5=15
3x6=18
3x7=21
3x8=24
3x9=27
3x10=30
5x1=5
5x2=10
5x3=15
5x4=20
5x5=25
5x6=30
5x7=35
5x8=40
5x9=45
5x10=50
8x1=8
8x2=16
8x3=24
8x4=32
8x5=40
8x6=48
8x7=56
8x8=64
8x9=72
8x10=80
10x1=10
10x2=20
10x3=30
10x4=40
10x5=50
10x6=60
10x7=70
10x8=80
10x9=90
10x10=100


*/

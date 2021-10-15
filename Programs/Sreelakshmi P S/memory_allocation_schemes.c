/**************************************************************
    IMPLEMENTATION OF MEMORY ALLOCATION SCHEMES

                             - Contributed by Sreelakshmi P S
**************************************************************/

#include<stdio.h>

int b,p,block[50],process[50],b1[50],p1[50];

void input()
{
    int i;
    for(i=0;i<b;i++)
        block[i]=b1[i];
    for(i=0;i<p;i++)
        process[i]=p1[i];
}

void firstfit()
{
    int i,j,k,flag;
    printf("\nBlock sizes: ");
	for(i=0;i<b;i++)
		printf("%d\t",block[i]);
	printf("\nProcess sizes: ");
	for(i=0;i<p;i++)
		printf("%d\t",process[i]);
	printf("\n\nMemory Allocation Process.........\n");
	for(i=0;i<p;i++)
	{
		flag=0;
		for(j=0;j<b;j++)
		{
			if(process[i] <= block[j])
			{
				flag=1;
				printf("\nProcess %d allocated to block %d",(i+1),(j+1));
				block[j] = block[j] - process[i];
				printf("\nAfter updation: ");
				for(k=0;k<b;k++)
					printf("%d\t",block[k]);
				printf("\n");
				break;
			}
		}
		if(flag==0)
			printf("\nOops! Sufficient memory not available...The process %d has to wait\n",(i+1));
	}
}

void bestfit()
{
    int i,j,k,flag,min;	
	printf("\nBlock sizes: ");
	for(i=0;i<b;i++)
		printf("%d\t",block[i]);
	printf("\nProcess sizes: ");
	for(i=0;i<p;i++)
		printf("%d\t",process[i]);
	printf("\n\nMemory Allocation Process.........\n");
	for(i=0;i<p;i++)
	{
		flag=0;
		min=-1;		
		for(j=0;j<b;j++)
		{
			if(process[i] <= block[j])
			{
				flag=1;
				if(min==-1)	
					min=j;
				else		
				{
					if(block[j] < block[min])
						min=j;
				}
			}
		}
		if(flag==0)
			printf("\nOops! Sufficient memory not available...The process %d has to wait\n",(i+1));
		else
		{
			printf("\nProcess %d allocated to block %d",(i+1),(min+1));
			block[min] = block[min] - process[i];
			printf("\nAfter updation: ");
			for(k=0;k<b;k++)
				printf("%d\t",block[k]);
			printf("\n");
		}		
	}
}

void worstfit()
{
    int i,j,k,flag,max;	
	printf("\nBlock sizes: ");
	for(i=0;i<b;i++)
		printf("%d\t",block[i]);
	printf("\nProcess sizes: ");
	for(i=0;i<p;i++)
		printf("%d\t",process[i]);
	printf("\n\nMemory Allocation Process.........\n");
	for(i=0;i<p;i++)
	{
		flag=0;
		max=-1;		
		for(j=0;j<b;j++)
		{
			if(process[i] <= block[j])
			{
				flag=1;
				if(max==-1)	
					max=j;
				else		
				{
					if(block[j] > block[max])
						max=j;
				}
			}
		}
		if(flag==0)
			printf("\nOops! Sufficient memory not available...The process %d has to wait\n",(i+1));
		else
		{
			printf("\nProcess %d allocated to block %d",(i+1),(max+1));
			block[max] = block[max] - process[i];
			printf("\nAfter updation: ");
			for(k=0;k<b;k++)
				printf("%d\t",block[k]);
			printf("\n");
		}		
	}
}

void main()
{	
    int op,i;
    printf("\n   MEMORY ALLOCATION SCHEMES");
    printf("\n--------------------------------");
    printf("\n\nEnter the no. of blocks: ");
    scanf("%d",&b);
    printf("\nEnter the no. of processes: ");
    scanf("%d",&p);
    printf("\nEnter the block sizes: ");
    for(i=0;i<b;i++)
        scanf("%d",&b1[i]);
    printf("\nEnter the process sizes: ");
    for(i=0;i<p;i++)
        scanf("%d",&p1[i]);
    do
    {
        printf("\n\nMENU :");
        printf("\n1. First Fit Memory Allocation");
        printf("\n2. Best Fit Memory Allocation");
        printf("\n3. Worst Fit Memory Allocation");
        printf("\n4. Exit");
        printf("\nEnter your option number:\t");
        scanf("%d",&op);
        switch(op)
        {
            case 1:     printf("\n\nFirst Fit Memory Allocation.........\n");
                        input();
                        firstfit();
                        break;
            case 2:     printf("\n\nBest Fit Memory Allocation.........\n");
                        input();
                        bestfit();
                        break;
            case 3:     printf("\n\nWorst Fit Memory Allocation.........\n");
                        input();
                        worstfit();
                        break;
            case 4:     printf("\n\nExiting..........\n");
                        break;
            default:    printf("\nInvalid Option!!");

        }
    }while(op!=4);
}






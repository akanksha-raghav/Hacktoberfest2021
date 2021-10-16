/******************************************************************
             DISK SCHEDULING ALGORITHMS
                                              
                              - Contributed by Sreelakshmi P S
*******************************************************************/

#include<stdio.h>

int n,head,arr[50];


void fcfs()
{
	int t[50],i,total_head=0,diff[50];
	float avg_head;

    t[0]=head;

	for(i=1; i<=n; i++)
		t[i]=arr[i];
	for(i=0; i<n; i++)
	{
		diff[i] = t[i+1] - t[i];
		if(diff[i] < 0)
			diff[i] = diff[i] * (-1);
	}
	for(i=0; i<n; i++)
		total_head = total_head + diff[i];
    printf("\nScheduling Order :\n");
	for(i=0; i<=n; i++)
		printf("%d \t",t[i]);
	printf("\n\nTotal Head Movements : %d\n",total_head);
	avg_head = total_head / n;
	printf("\nAverage Head Movements : %f\n",avg_head);
}


void scan()
{
	int t[20],diff[20],track[20],i,j,temp,k,pos,total_head=0,end=199;
	float avg_head;

	t[0]=0;
	t[1]=head;
	t[n+2]=end;
	
	for(i=2; i<n+2; i++)
		t[i]=arr[i-1];
	for(i=0; i<n+2; i++)								// Bubble sort
	{
		for(j=0; j<((n+2)-1-i); j++)
		{
			if(t[j] > t[j+1])
			{
				temp = t[j];
				t[j] = t[j+1];
				t[j+1] = temp;
			}
		}
	}
	for(i=0; i<n+2; i++)							// To find the position of head
	{
		if(t[i]==head)
		{
			k=i;									// Head at position 'k'
			pos=0;
		}
	}
	if(head < (end-head))						// If difference to left side of Head is less
	{
		for(i=k; i>=0; i--)
		{
			track[pos] = t[i];
			pos++;
		}
		for(i=k+1; i<n+2; i++)
		{
			track[pos] = t[i];
			pos++;
		}
	}
	else										// If difference to right side of Head is less
	{
		for(i=k; i<=n+2; i++)
		{
			track[pos] = t[i];
			pos++;
		}
		for(i=k-1; i>0; i--)
		{
			track[pos] = t[i];
			pos++;
		}
	}
	printf("\nScheduling Order :\n");
	for(pos=0; pos<n+2; pos++)
		printf("%d \t",track[pos]);
	for(j=0; j<n+1; j++)
	{
		diff[j]=0;
		if(track[j] > track[j+1])
			diff[j] = track[j] - track[j+1];
		else
			diff[j] = track[j+1] - track[j];
		total_head = total_head + diff[j];
	}
	printf("\n\nTotal Head Movements : %d\n",total_head);
    avg_head = total_head / n;
	printf("\nAverage Head Movements : %f\n",avg_head);
}


void cscan()
{
	int t[20],diff[20],track[20],i,j,temp,k,pos,total_head=0,end=199;
	float avg_head;
	
	t[0]=0;
	t[1]=head;
	t[n+2]=end;
	
	for(i=2; i<n+2; i++)
		t[i]=arr[i-1];
	for(i=0; i<n+2; i++)									// Bubble sort
	{
		for(j=0; j<((n+2)-1-i); j++)
		{
			if(t[j] > t[j+1])
			{
				temp = t[j];
				t[j] = t[j+1];
				t[j+1] = temp;
			}
		}
	}
	for(i=0; i<n+2; i++)							// To find the position of head
	{
		if(t[i]==head)
		{
			k=i;									// Head at position 'k'
			pos=0;
		}
	}
	if(head < (end-head))							// If difference to left side of Head is less
	{
		for(i=k; i>=0; i--)
		{
			track[pos] = t[i];
			pos++;
		}
		for(i=n+2; i>k; i--)
		{
			track[pos] = t[i];
			pos++;
		}
	}
	else									// If difference to right side of Head is less
	{
		for(i=k; i<=n+2; i++)
		{
			track[pos] = t[i];
			pos++;
		}
		for(i=0; i<k; i++)
		{
			track[pos] = t[i];
			pos++;
		}
	}
	printf("\nScheduling Order :\n");
	for(pos=0; pos<=n+2; pos++)
		printf("%d \t",track[pos]);
	for(j=0; j<n+2; j++)
	{
		diff[j]=0;
		if(track[j] > track[j+1])
			diff[j] = track[j] - track[j+1];
		else
			diff[j] = track[j+1] - track[j];
		total_head = total_head + diff[j];
	}
	printf("\n\nTotal Head Movements : %d\n",total_head);
    avg_head = total_head / n;
	printf("\nAverage Head Movements : %f\n",avg_head);
}


void main()
{	
    int op,i;
    printf("\n   DISK SCHEDULING ALGORITHMS");
	printf("\n--------------------------------");
    printf("\n\nEnter the no. of tracks : ");
	scanf("%d",&n);
	printf("\nEnter the current position of head : ");
	scanf("%d",&head);
	printf("\nEnter the tracks to be traversed (assuming there are 200 cylinders): ");
	for(i=1; i<=n; i++)
		scanf("%d",&arr[i]);
    do
    {
        printf("\n\nMENU :");
        printf("\n1. First Come First Served (FCFS)");
        printf("\n2. SCAN");
        printf("\n3. C-SCAN");
        printf("\n4. Exit");
        printf("\nEnter your option number:\t");
        scanf("%d",&op);
        switch(op)
        {
            case 1:     printf("\n\nFirst Come First Served (FCFS).........\n");
                        fcfs();
                        break;
            case 2:     printf("\n\nSCAN.........\n");
                        scan();
                        break;
            case 3:     printf("\n\nC-SCAN.........\n");
                        cscan();
                        break;
            case 4:     printf("\n\nExiting..........\n");
						break;
            default:    printf("\nInvalid Option!!");

        }
    }while(op!=4);
}
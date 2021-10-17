/*********************************************************************
		Round Robin Scheduling Implementation

                                    - Contributed by Sreelakshmi P S
*********************************************************************/

#include<stdio.h>
#include<string.h>

int q[100],front=-1,rear=0;

struct process
{
	char pname[20];				        
	int at,bt,wt,tt,status,left;		
}p[20];

struct done
{
	char name[20];
	int st,ct;
};
struct done d[20];

void enqueue(int j)
{
	q[rear]=j;
	rear++;
	if(front==-1)				
		front++;
}

int dequeue()
{
	int item;
	item = q[front];
	front++;
	if(front==rear)				
	{
		front = -1;
		rear = 0;
	}
	return item;
}

void main()
{
	int n,i,j,idle,item,l,num,time_quantum;
	float totalwt=0.0,totaltt=0.0,avgwt,avgtt;
	printf("\nEnter the no. of processes : ");
	scanf("%d",&n);
	for(i=0;i<n;i++)			
	{
		printf("\nEnter the process name: ");
		__fpurge(stdin);
		gets(p[i].pname);
		printf("\nEnter the arrival time: ");
		scanf("%d",&p[i].at);
		printf("\nEnter the burst time: ");		
		scanf("%d",&p[i].bt);
		p[i].left = p[i].bt;	
		p[i].status=0;		    
	}
	printf("\nEnter the time quantum: ");
	scanf("%d",&time_quantum);
	idle=0;					
	for(i=0,num=0;l<n;)
	{
		for(j=0;j<n;j++)		
		{
			if(p[j].at<=i && p[j].status==0)
			{
				enqueue(j);
				p[j].status = 1;	
			}
		}
		
		if(idle==0 && front==-1)	
		{
			strcpy(d[num].name,"idle");
			d[num].st = i;
			i++;
			idle = 1;
		}
		else if(front!=-1)	
		{
			if(idle==1)
			{
				d[num].ct = i;
				idle = 0;
				num++;
			}
			item = dequeue();
			strcpy(d[num].name,p[item].pname);
			d[num].st = i;
			if(p[item].left <= time_quantum)	
			{
				d[num].ct = i + p[item].left;
				p[item].tt = d[num].ct - p[item].at;	
				p[item].wt = p[item].tt - p[item].bt;	
				i = d[num].ct;
				p[item].status = 2;	
				l++;
				num++;
			}
			else	
			{
				d[num].ct = i + time_quantum;
				p[item].left = p[item].left - time_quantum;
				i = d[num].ct;
				num++;
				for(j=0;j<n;j++)	
				{
					if(p[j].at<=i && p[j].status==0)
					{
						enqueue(j);
						p[j].status = 1;	
					}
				}
				enqueue(item);	
			}
		}
		else
		{
			i++;
		}
	}
	printf("\n\n | PName | Arrival Time\t| Burst Time\t| Status\t| Wait\t| Turn");
	for(i=0;i<n;i++)
		printf("\n | %s \t | %d \t \t| %d \t \t| %d \t \t| %d \t| %d \n",p[i].pname,p[i].at,p[i].bt,p[i].status,p[i].wt,p[i].tt);
	printf("\n\n\nGantt Chart\n");
	for(i=0;i<num;i++)
		printf("__________");
	printf("\n|");
	for(i=0;i<num;i++)
		printf("%s\t|",d[i].name);		
	printf("\n");
	for(i=0;i<num;i++)
		printf("__________");
	printf("\n0\t");
	for(i=0;i<num;i++)
		printf("%d\t",d[i].ct);
	for(i=0;i<n;i++)
	{
		totalwt = totalwt + p[i].wt;
		totaltt = totaltt + p[i].tt;
	}
	avgwt = (float)(totalwt/n);
	avgtt = (float)(totaltt/n);
	printf("\n\n\n Average Waiting Time = %f ms",avgwt);
	printf("\n Average Turnaround Time = %f ms\n",avgtt);
}

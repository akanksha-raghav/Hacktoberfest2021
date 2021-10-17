/*********************************************************************
	First Come First Serve Scheduling (FCFS) Implementation
    
                                    - Contributed by Sreelakshmi P S
*********************************************************************/

#include<stdio.h>
#include<string.h>

struct process
{
	char pname[20];
	int at,bt,wt,tt,status;
}p[20],t;

struct done
{
	char name[20];
	int st,ct;
};
struct done d[20];

void main()
{
	int n,i,j,idle,k,num;
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
		p[i].status=0;	
	}
	for(i=0;i<n;i++)
	{ 	
		for(j=0;j<n-i-1;j++)
		{
			if(p[j].at > p[j+1].at)
			{
				t = p[j];
				p[j] = p[j+1];
				p[j+1] = t;
			}
		}
	}
	idle=0;
	for(i=0,k=0,num=0;k<n;)
	{
		if(p[k].at<=i && p[k].status==0)
		{
			if(idle==1)
			{
				d[num].ct = i;
				num++;
			}
			strcpy(d[num].name,p[k].pname);
			d[num].st = i;
			d[num].ct = i + p[k].bt;
			p[k].wt = d[num].st - p[k].at;
			p[k].tt = p[k].wt + p[k].bt;
			i = d[num].ct;
			p[k].status = 1;
			k++;
			num++;
			idle = 0;
		}
		else if(idle==0)
		{
			strcpy(d[num].name,"idle");
			d[num].st = i;
			i++;
			idle = 1;
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
	printf("______________________________________________\n");
	printf("|");
	for(i=0;i<n;i++)
		printf("%s\t|",p[i].pname);
	printf("\n______________________________________________");
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
	printf("\n\n\n Average Waiting Time = %f",avgwt);
	printf("\n Average Turnaround Time = %f\n",avgtt);
}

#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
int n,i,j,dist,count=0,move,size;

void reset(int sr[],int rstr[])
{   for(i=0;i<n;i++)
        sr[i]=rstr[i];
}

void sort(int sr[])
{   for(i=0;i<n;i++)
        for(j=0;j<n-i-1;j++)
            if(sr[j]>sr[j+1])
            {
                int temp;
                temp=sr[j];
                sr[j]=sr[j+1];
                sr[j+1]=temp;
            }
}

void fcfs(int rstr[],int head)
{   printf("\nFCFS\n");
    dist=0;
    for(i=0;i<n;i++)
    {
        dist=dist+abs(rstr[i]-head);
        printf("%d->",head);
        head=rstr[i];
    }
    printf("%d\n",head);
    printf("Total head movement for FCFS=%d\n",dist);
}

void sstf(int rstr[],int head)
{   printf("\nSSTF\n");
    dist=0;
    while(count!=n)
    {
        int min=1000,d,index;
        for(i=0;i<n;i++)
        {
           d=abs(rstr[i]-head);
           if(min>d)
           {
               min=d;
               index=i;
           }
           
        }
        dist=dist+min;
        printf("%d->",head);
        head=rstr[index];
        rstr[index]=1000;
        count++;
    }
    printf("%d\n",head);
    printf("Total head movement for SSTF=%d\n",dist);
}

void scan(int rstr[],int head)
{   printf("\nSCAN\n");
    int index;
    dist=0;
    for(i=0;i<n;i++)
    {
        if(head<rstr[i])
        {
            index=i;
            break;
        }
    }
    if(move==1)
    {   for(i=index;i<n;i++)
        {
            dist=dist+abs(rstr[i]-head);
            printf("%d->",head);
            head=rstr[i];
        }
        dist=dist+abs(size-rstr[i-1]-1);
        printf("%d->",head);
        head=size-1;
        for(i=index-1;i>=0;i--)
        {
            dist=dist+abs(rstr[i]-head);
            printf("%d->",head);
            head=rstr[i];
        }
    }
    else
    {   for(i=index-1;i>=0;i--)
        {
            dist=dist+abs(rstr[i]-head);
            printf("%d->",head);
            head=rstr[i];
        }
        dist=dist+abs(rstr[i+1]-0);
        printf("%d->",head);
        head=0;
        for(i=index;i<n;i++)
        {
            dist=dist+abs(rstr[i]-head);
            printf("%d->",head);
            head=rstr[i];
        }
    }
    printf("%d\n",head);
    printf("Total head movement for SCAN=%d\n",dist);
}

void cscan(int rstr[],int head)
{   printf("\nCSCAN\n");
    int index;
    dist=0;
    for(i=0;i<n;i++)
    {
        if(head<rstr[i])
        {
            index=i;
            break;
        }
    }
    if(move==1)
    {   for(i=index;i<n;i++)
        {
            dist=dist+abs(rstr[i]-head);
            printf("%d->",head);
            head=rstr[i];
        }
        dist=dist+abs(size-rstr[i-1]-1);
        dist=dist+abs(size-1-0);
        printf("%d->",head);
        printf("%d->",size-1);
        head=0;
        for(i=0;i<index;i++)
        {
            dist=dist+abs(rstr[i]-head);
            printf("%d->",head);
            head=rstr[i];
        }
    }
    else
    {   for(i=index-1;i>=0;i--)
        {
            dist=dist+abs(rstr[i]-head);
            printf("%d->",head);
            head=rstr[i];
        }
        dist=dist+abs(rstr[i+1]-0);
        dist=dist+abs(size-1-0);
        printf("%d->",head);
        head=size-1;
        for(i=n-1;i>=index;i++)
        {
            dist=dist+abs(rstr[i]-head);
            printf("%d->",head);
            head=rstr[i];
        }
    }
    printf("%d\n",head);
    printf("Total head movement for CSCAN=%d\n",dist);
}

void look(int rstr[],int head)
{   printf("\nLOOK\n");
    int index;
    dist=0;
    for(i=0;i<n;i++)
    {
        if(head<rstr[i])
        {
            index=i;
            break;
        }
    }
    if(move==1)
    {   for(i=index;i<n;i++)
        {
            dist=dist+abs(rstr[i]-head);
            printf("%d->",head);
            head=rstr[i];
        }
        for(i=index-1;i>=0;i--)
        {
            dist=dist+abs(rstr[i]-head);
            printf("%d->",head);
            head=rstr[i];
        }
    }
    else
    {   for(i=index-1;i>=0;i--)
        {
            dist=dist+abs(rstr[i]-head);
            printf("%d->",head);
            head=rstr[i];
        }
        for(i=index;i<n;i++)
        {
            dist=dist+abs(rstr[i]-head);
            printf("%d->",head);
            head=rstr[i];
        }
    }
    printf("%d\n",head);
    printf("Total head movement for LOOK=%d\n",dist);
}

void clook(int rstr[],int head)
{   printf("\nCLOOK\n");
    int index;
    dist=0;
    for(i=0;i<n;i++)
    {
        if(head<rstr[i])
        {
            index=i;
            break;
        }
    }
    if(move==1)
    {   for(i=index;i<n;i++)
        {
            dist=dist+abs(rstr[i]-head);
            printf("%d->",head);
            head=rstr[i];
        }
        for(i=0;i<index;i++)
        {
            dist=dist+abs(rstr[i]-head);
            printf("%d->",head);
            head=rstr[i];
        }
    }
    else
    {   for(i=index-1;i>=0;i--)
        {
            dist=dist+abs(rstr[i]-head);
            printf("%d->",head);
            head=rstr[i];
        }
        for(i=n-1;i>=index;i--)
        {
            dist=dist+abs(rstr[i]-head);
            printf("%d->",head);
            head=rstr[i];
        }
    }
    printf("%d\n",head);
    printf("Total head movement for CLOOK=%d\n",dist);
}

void main()
{   int RQ[100],sr[100],head;
    printf("Enter no of requests:");
    scanf("%d",&n);
    printf("Enter request sequence:");
    for(i=0;i<n;i++)
        scanf("%d",&RQ[i]);
    printf("Enter initial head position:");
    scanf("%d",&head);
    printf("Enter total disk size:");
    scanf("%d",&size);
    printf("Enter head movement direction(right-1/left-0):");
    scanf("%d",&move);
    fcfs(RQ,head);
    reset(sr,RQ);
    sstf(sr,head);
    reset(sr,RQ);
    sort(sr);
    scan(sr,head);
    reset(sr,RQ);
    sort(sr);
    cscan(sr,head);
    reset(sr,RQ);
    sort(sr);
    look(sr,head);
    reset(sr,RQ);
    sort(sr);
    clook(sr,head);
}

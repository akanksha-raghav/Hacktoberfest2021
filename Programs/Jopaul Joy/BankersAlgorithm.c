#include <stdio.h>
int pn, rn;
int alloc[20][10], max[20][10],avail[10], reqP, reqR[10], need[20][10], completed[20];
int main()
{
    printf("NO OF PROCESS ");
    scanf("%d", &pn);
    printf("NO OF RECOURCE ");
    scanf("%d", &rn);
    for (int i = 0; i < pn; i++)
    {
        completed[i] = 0;
        printf("\nP%d\nENTER THE MAXIMUM RECOUCES ", i);
        for (int j = 0; j < rn; j++)
        {
            scanf("%d", &max[i][j]);
        }
        printf("ENTER THE ALLOCATED RECOURCCES ");
        for (int j = 0; j < rn; j++)
        {
            scanf("%d", &alloc[i][j]);
        }
    }
    printf("\nENTER THE AVAILABLE RECOURCES ");
    for (int i = 0; i < rn; i++)
    {
        scanf("%d", &avail[i]);
    }
    printf("\nENTER THE PROCESS TO REQUEST ");
    scanf("%d", &reqP);
    printf("ENTER THE RECOURCES TO ALLOCATE ");
    for (int i = 0; i < rn; i++)
    {
        scanf("%d", &reqR[i]);
    }

    printf("\nAVAILABLE RESOURCES ");
    for (int i = 0; i < rn; i++)
    {
        printf("%d ", avail[i]);
    }

    //NEED CALC
    for (int i = 0; i < pn; i++)
    {
        for (int j = 0; j < rn; j++)
        {
            need[i][j] = max[i][j] - alloc[i][j];
        }
    }
    int c = 0;
    for (int j = 0; j < rn; j++)
    {
        if (need[reqP][j] > reqR[j])
        {
            c += 1;
        }
        else if (need[reqP][j] == reqR[j])
        {
            c += 2;
        }
    }
    int count = pn;
    if (c >= rn)
    {
        printf("\nREQUEST GRANTED ");
        for (int i = 0; i < rn; i++)
        {
            need[reqP][i] -= reqR[i];
            alloc[reqP][i] += reqR[i];
            avail[i] -= reqR[i];
        }
        if (c == 2 * rn)
        {count = pn,
            completed[reqP] = 1;
        }
    }
    printf("\nAVAILABLE RESOURCES ");
    for (int i = 0; i < rn; i++)
    {
        printf("%d ", avail[i]);
    }

    //DISPLAY
    printf("\n-----------------------------------------\n");
    printf("\nPROCESS | MAX | ALLOC | NEED\n");

    for (int i = 0; i < pn; i++)
    {
        printf("\nP%d | ", i);
        for (int j = 0; j < rn; j++)
        {
            printf("%d ", max[i][j]);
        }
        printf("| ");
        for (int j = 0; j < rn; j++)
        {
            printf("%d ", alloc[i][j]);
        }
        printf("| ");
        for (int j = 0; j < rn; j++)
        {
            printf("%d ", need[i][j]);
        }
    }
    printf("\n-----------------------------------------\n");

    //POCESS
    int  pCpy = 0;
    while (count > 0 && pCpy < pn * pn)
    {
        c=0;
        for (int j = 0; j < rn; j++)
        {
            if (need[pCpy%pn][j] <= avail[j]&&completed[pCpy%pn]==0)
            {
                c += 1;
            }
        }
        if (c == rn)
        {
            count--;
          completed[pCpy%pn]=1;
          printf("\nP%d EXECUTED \n",pCpy%pn);
    printf("AVAILABLE RECOURCES ");
          for (int i = 0; i < rn; i++)
          {
          avail[i] += alloc[pCpy%pn][i];
        alloc[pCpy%pn][i] = max[pCpy%pn][i];
        need[pCpy%pn][i] = 0;
        printf("%d ",avail[i]);
          }
          
        }
        pCpy++;
    }
    if(count==0){
        printf("\nSAFE");
    }else  {
        printf("\nNOT SAFE");
    }
}

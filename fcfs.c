#include <stdio.h>

void main()
{
    int bt[20],tat[20],wt[20],temp,n,i,j;
    float atat=0,awt=0;

    printf("Enter number of proceess: ");
    scanf("%d",&n);

    printf("Enter the brust time: ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&bt[i]);
    }

    wt[0]=0;
    for(i=0;i<n;i++)
    {
        for(j=0;j<i;j++)
            wt[i]=+bt[j];

        awt+=wt[i];

        tat[i]=wt[i]+bt[i];

        atat+=tat[i];
    }
    printf("\nprocess bt \twt \ttat");
    for(i=0;i<n;i++)
    {
        printf("\n%d\t%d\t%d\t%d\t",i,bt[i],wt[i],tat[i]);
    }

    printf("Avg. wt= %d",awt);
    printf("Avg. tat= %d", atat);

}


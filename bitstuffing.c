#include<stdio.h>

void main()
{
    int a[30],b[30],i=0,j=0,k,n,count;
    printf("Enter frame size: ");
    scanf("%d",&n);
    printf("Enter frame data in 0 and 1 formate: ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }

    while(i<n)
    {
        if(a[i]==1)
        {
            count=1;
            b[j]=a[i];

            for(k=i+1;a[k]==1&&k<n&&count<5;k++)
            {
                j++;
                b[j]=a[k];
                count++;
            if(count == 5)
            {
                j++;
                b[j]=0;
            }
            i=k;
            }
        }
        else
        {
            b[j]=a[i];
            i++;
            j++;
        }
    }

    printf("After bit stuffing: ");
    for(i=0;i<j;i++)
    {
        printf("%d",b[i]);
    }
}

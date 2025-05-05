#include<stdio.h>

void main()
{
    int a[30],b[30],i,j=0,k,n,count=0;
    printf("Enter frame size: ");
    scanf("%d",&n);
    printf("Enter frame data in 0 and 1 formate: ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }

    for(i=0;i<n;i++)
    {
        b[j]=a[i];
        if(a[i]== 1)
        {
            count++;
            if (count == 5)
            {
                j++;
                b[j]=0;
                count=0;
            }
        }
        else
        {
            count =0;
        }
        j++;
    }

    printf("After bit stuffing: ");
    for(i=0;i<n;i++)
    {
        printf("%d",b[i]);
    }
}

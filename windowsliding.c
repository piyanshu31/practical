#include<stdio.h>
int maxsum(int a[],int k,int n);

void main()
{
    int n,k;
    printf("Enter size of array: ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the elements: ");
    for(int i=0; i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("Enter length of window: ");
    scanf("%d",&k);
    int max = maxsum(arr, k, n);
    printf("Sum of %d consecative elements is: %d",k,max);
}

int maxsum(int a[], int k, int n)
{
    int i,maxm,sum;
    for(i=0;i<k;i++)
    {
        sum+=a[i];
    }
    maxm = sum;

    for(i=k;i<n;i++)
    {
        sum += a[i]-a[i-k];
    }
    if(sum>maxm)
    {
        maxm=sum;
    }
    return maxm;
}

#include<stdio.h>

void main()
{
    int n;
    printf("Enter address: ";)
    scanf("%d",&n);
    if(n>0&&n<=127)
        printf("A");
    else if(n>128&&n<191)
        printf("B");
    else if(n>192&&n<223)
        printf("C");
    else if(n>224&&n<239)
        printf("D");
    else if(n>240&&n<255)
        printf("E");
    else
        printf("Invalud");
}

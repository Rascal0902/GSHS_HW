#include<stdio.h>
int main()
{
    int i,j,arr[5];
    for(i=0;i<5;i++)
        scanf(" %d",&arr[i]);
    for(i=0;i<5;i++)
        printf("%d ",arr[4-i]);
}

#include<stdio.h>
int main()
{
    int arr[5][5];
    int i,j,k;
    k=0;
    for(i=0;i<4;i++)
    {
         for(j=0;j-i<=0;j++)
         {
             arr[i][j]=++k;
         }
    }

    for(i=0;i<4;i++)
    {
         for(j=0;j-i<=0;j++)
         {
             printf("%3d",arr[i][j]);
         }
         printf("\n");
    }


}

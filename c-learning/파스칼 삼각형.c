#include<stdio.h>
int main()
{
    int a[10][20]={0,},i,j;
    a[0][10]=1;
    for(i=1;i<10;i++)
    {
        for(j=1;j<=19;j++)
    {
        a[i][j]=a[i-1][j-1]+a[i-1][j+1];
    }
    }
    for(i=0;i<10;i++)
    {
        for(j=0;j<20;j++)
    {
        if(a[i][j]==0)
        {
            printf("     ");
        }
       else  printf("%5d",a[i][j]);
    }
    printf("\n");
    }
    return 0;


}

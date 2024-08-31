#include<stdio.h>
int main()
{
    int r[9][9],i,j;
        for(i=0;i<=9;i++)
    {
      scanf("%s",r[i]);
    }
    for(i=0;i<=9;i++)
    {
    for(j=0;j<=9;j++)
    {
        printf("%d",r[i][j]);
    }
    printf("\n");
    }
    return 0;
}

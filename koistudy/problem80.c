#include<stdio.h>
int main()
{
    int i,j,m,n;
    scanf("%d %d",&m,&n);
    for(i=1;i<=m;i++)
    {
        for(j=1;j<=n;j++)
        {
            printf("%d %d\n",i,j);
        }
    }
    return 0;
    }

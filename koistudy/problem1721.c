#include<stdio.h>
int main()
{
    int n,m,a[101][101],i,j;
    scanf("%d %d",&n,&m);
    a[n][m]=1;
    for(i=n; i>=1; i--)
    {
        if((n-i)%2==0)
        {
            for(j=m-1; j>=1; j--)
            {
                a[i][j]=a[i][j+1]+1;
            }
            a[i-1][1]=a[i][1]+1;
        }
        else
        {
            for(j=2; j<=m; j++)
            {
                a[i][j]=a[i][j-1]+1;
            }
            a[i-1][m]=a[i][m]+1;
        }

    }
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
    return 0;
}

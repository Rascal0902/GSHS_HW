#include<stdio.h>
int main()
{
    int n,m,a[101][101],i,j;
    scanf("%d %d",&n,&m);
    a[1][m]=1;
    for(i=m; i>=1; i--)
    {
        if((m-i)%2==0)
        {
            for(j=2; j<=n; j++)
            {
                a[j][i]=a[j-1][i]+1;
            }
            a[n][i-1]=a[n][i]+1;


        }
        else
        {
            for(j=n-1; j>=1; j--)
            {
                a[j][i]=a[j+1][i]+1;
            }
            a[1][i-1]=a[1][i]+1;

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



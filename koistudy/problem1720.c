#include<stdio.h>
int main()
{
    int n,a[100][100],i,j;
    scanf("%d",&n);
    a[n-1][0]=1;
    for(i=0;i<=n-1;i++)
    {
        if(i%2==0)
        {
            for(j=n-2;j>=0;j--)
        {
            a[j][i]=a[j+1][i]+1;
        }
        a[0][i+1]=a[0][i]+1;
        }
        if(i%2==1)
        {
            for(j=1;j<=n-1;j++)
        {
            a[j][i]=a[j-1][i]+1;
        }
        a[n-1][i+1]=a[n-1][i]+1;
        }

    }
    for(i=0;i<=n-1;i++)
    {
        for(j=0;j<=n-1;j++)
        {
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
    return 0;
}

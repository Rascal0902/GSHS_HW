#include<stdio.h>
int main()
{
    int n,a[100][100],i,j;
    scanf("%d",&n);
    a[0][0]=1;
    for(i=0;i<n;i++)
    {
        if(i%2==0)
        {
            for(j=1;j<n;j++)
            {
                a[i][j]=a[i][j-1]+1;
            }
            a[i+1][n-1]=a[i][n-1]+1;
        }
        else
        {
             for(j=n-2;j>=0;j--)
            {
                a[i][j]=a[i][j+1]+1;
            }
            a[i+1][0]=a[i][0]+1;
        }
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
    return 0;
}

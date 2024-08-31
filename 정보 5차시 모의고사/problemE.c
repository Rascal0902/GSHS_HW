#include<stdio.h>
int a[1000][1000];
int main()
{
    int i,j,m,n,k=0;
    int t;
    scanf("%d %d",&m,&n);
    for(i=0;i<m;i++)
    {
       for(j=0;j<n;j++)
       {
           scanf("%1d",&a[i][j]);
       }
    }
    for(j=0;j<n;j++)
    {
        for(i=0;i<m;i++)
        {
            if(a[i][j]==0)
            {
                k=0;
            }
            else
            {
                k+=a[i][j];
                a[i][j]=k;
            }
        }
        k=0;
    }
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
    return 0;
}


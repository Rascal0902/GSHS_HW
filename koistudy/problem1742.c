#include<stdio.h>
int n,m,a[100][100],i,j,k,w;
int f(int x,int y)
{
    int s=0;
    for(k=0;k<=x;k++)
    {
        for(w=0;w<=y;w++)
        {
            s+=a[k][w];
        }
    }
    printf("%d ",s);
    return 1;
}
int main()
{

    scanf("%d %d",&n,&m);
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            f(i,j);
        }
        printf("\n");
    }
    return 0;
}

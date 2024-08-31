#include <stdio.h>
#include <memory.h>
int n,m,A[505][505],a,b,c,sum,v[506],i,j,k;
void f1(int k)
{
    v[k]=1;
    for(int i=1; i<=n; i++)
    {
        if(A[k][i]==1 && v[i]==0)
        {
            c++;
            f1(i);
        }
    }
}
void f2(int k)
{
    v[k]=1;
    for(int i=1; i<=n; i++)
    {
        if(A[k][i]==-1 && v[i]==0)
        {
            c++;
            f2(i);
        }
    }
}
int main()
{
    scanf("%d %d", &n, &m);

    for(i=1; i<=m; i++)
    {
        scanf("%d %d",&a,&b);
        A[a][b]=1;
        A[b][a]=-1;
    }

    for(i=1; i<=n; i++)
    {
        f1(i);
        f2(i);
        if(c==n-1)
        {
            sum++;
        }
        memset(v,0,sizeof(v));
        c=0;
    }
    printf("%d",sum);
}

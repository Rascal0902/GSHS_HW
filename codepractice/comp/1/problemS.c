/*´«³»¸®´Â °Ü¿ï¹ã ¿¹½Ã
#include <cstdio>
int d[1005][1005],i,j,n,m,k,x1,y1,x2,y2,u,sum[1005][1005];
int main()
{
    scanf("%d%d%d",&n,&m,&k);
    for(i=1;i<=k;i++){
        scanf("%d%d%d%d%d",&x1,&y1,&x2,&y2,&u);
        d[x1][y1]+=u;
        d[x2+1][y2+1]+=u;
        d[x1][y2+1]-=u;
        d[x2+1][y1]-=u;
    }
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            printf("%d ", d[i][j]);
        }
        puts("");
    }
    puts("");
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
            d[i][j+1]+=d[i][j];
    for(j=1;j<=m;j++)
        for(i=1;i<=n;i++)
            d[i+1][j]+=d[i][j];
    for(i=1;i<=n;i++)for(j=1;j<=m;j++){
        sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+d[i][j];
    }
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            printf("%d ",d[i][j]);
        }
        puts("");
    }
    return 0;
}*/
#include<stdio.h>
long long int i,j,n,q,a,c,b,d,w,snow[100005][5],add[1000][1000],k;
int main()
{
    scanf("%lld %lld",&n,&q);
    for(i=0;i<q;i++)
    {
       scanf("%lld %lld %lld %lld %lld",&snow[i][0],&snow[i][1],&snow[i][2],&snow[i][3],&snow[i][4]);
    }
    for(i=0;i<q;i++)
    {
       add[snow[i][0]][snow[i][1]]+=snow[i][4];
       add[snow[i][0]][snow[i][3]+1]-=snow[i][4];
       add[snow[i][2]+1][snow[i][1]]-=snow[i][4];
       add[snow[i][2]+1][snow[i][3]+1]+=snow[i][4];

    }
     for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            add[i][j]=add[i-1][j]+add[i][j-1]-add[i-1][j-1]+add[i][j];
            printf("%lld ",add[i][j]);
        }
        printf("\n");
    }
    return 0;
}





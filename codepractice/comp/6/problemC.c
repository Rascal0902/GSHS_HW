#include<stdio.h>
long long int m,n,k,x,y,a[1005][1005],qx[1000005],qy[1000005],stx=0,sty=0,endx=0,endy=0;
void pushx(long long int k)
{
    qx[endx]=k;
    endx++;
}
void pushy(long long int k)
{
    qy[endy]=k;
    endy++;
}
void popx()
{
    qx[stx]=0;
    stx++;
}
void popy()
{
    qy[sty]=0;
    sty++;
}
int main()
{
  scanf("%lld %lld %lld",&n,&m,&k);
  long long int x,y;
  for(int i=0;i<k;i++)
  {
      scanf("%lld %lld",&x,&y);
      a[x][y]=1;
      pushx(x);
      pushy(y);
  }
  while(stx!=endx)
  {
         if((qx[stx]+1<=n)&&(a[qx[stx]+1][qy[sty]]==0))
         {
             a[qx[stx]+1][qy[sty]]=a[qx[stx]][qy[sty]]+1;
             pushx(qx[stx]+1);
             pushy(qy[sty]);
         }
         if((qx[stx]-1>=1)&&(a[qx[stx]-1][qy[sty]]==0))
         {
             a[qx[stx]-1][qy[sty]]=a[qx[stx]][qy[sty]]+1;
             pushx(qx[stx]-1);
             pushy(qy[sty]);
         }
         if((qy[sty]+1<=m)&&(a[qx[stx]][qy[sty]+1]==0))
         {
             a[qx[stx]][qy[sty]+1]=a[qx[stx]][qy[sty]]+1;
             pushx(qx[stx]);
             pushy(qy[sty]+1);
         }
        if((qy[sty]-1>=1)&&(a[qx[stx]][qy[sty]-1]==0))
        {
            a[qx[stx]][qy[sty]-1]=a[qx[stx]][qy[sty]]+1;
            pushx(qx[stx]);
            pushy(qy[sty]-1);
        }
        popx();
        popy();
        /*for(long long int i=1; i<=n; i++)
        {
            for(long long int j=1; j<=m; j++)
            {
                printf("%lld ",a[i][j]);
            }
            printf("\n");
        }
        printf("\n\n");*/
    }
    for(long long int i=1; i<=n; i++)
    {
        for(long long int j=1; j<=m; j++)
        {
            printf("%lld ",a[i][j]);
        }
        printf("\n");
    }
    return 0;
}

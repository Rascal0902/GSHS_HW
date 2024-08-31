#include<stdio.h>
int n,m,k,a[105][105][105],qx[100000000],qy[100000000],qz[100000000],endx=0,endy=0,endz=0,stx=0,sty=0,stz=0;
void pushx(int k)
{
    qx[endx]=k;
    endx++;
}
void pushy(int k)
{
    qy[endy]=k;
    endy++;
}
void pushz(int k)
{
    qz[endz]=k;
    endz++;
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
void popz()
{
    qz[stz]=0;
    stz++;
}
int main()
{
   scanf("%d %d %d",&n,&k,&m);
   int x,y,z;
   for(int i=0;i<k;i++)
   {
       scanf("%d %d %d",&x,&y,&z);
       a[x][y][z]=1;
       pushx(x);
       pushy(y);
       pushz(z);
   }
   int t=0,sum=k;
   while(stx!=endx)
   {
        if(a[qx[stx]][qy[sty]][qz[stz]]<=m-1)
        {
            if((qx[stx]+1<=n)&&(a[qx[stx]+1][qy[sty]][qz[stz]]==0))
            {
                a[qx[stx]+1][qy[sty]][qz[stz]]=a[qx[stx]][qy[sty]][qz[stz]]+1;
                sum++;
                pushx(qx[stx]+1);
                pushy(qy[sty]);
                pushz(qz[stz]);
            }
             if((qx[stx]-1>=1)&&(a[qx[stx]-1][qy[sty]][qz[stz]]==0))
            {
                a[qx[stx]-1][qy[sty]][qz[stz]]=a[qx[stx]][qy[sty]][qz[stz]]+1;
                sum++;
                pushx(qx[stx]-1);
                pushy(qy[sty]);
                pushz(qz[stz]);
            }
            if((qy[sty]+1<=n)&&(a[qx[stx]][qy[sty]+1][qz[stz]]==0))
            {
                a[qx[stx]][qy[sty]+1][qz[stz]]=a[qx[stx]][qy[sty]][qz[stz]]+1;
                sum++;
                pushx(qx[stx]);
                pushy(qy[sty]+1);
                pushz(qz[stz]);
            }
            if((qy[sty]-1>=1)&&(a[qx[stx]][qy[sty]-1][qz[stz]]==0))
            {
                a[qx[stx]][qy[sty]-1][qz[stz]]=a[qx[stx]][qy[sty]][qz[stz]]+1;
                sum++;
                pushx(qx[stx]);
                pushy(qy[sty]-1);
                pushz(qz[stz]);
            }
            if((qz[stz]+1<=n)&&(a[qx[stx]][qy[sty]][qz[stz]+1]==0))
            {
                a[qx[stx]][qy[sty]][qz[stz]+1]=a[qx[stx]][qy[sty]][qz[stz]]+1;
                sum++;
                pushx(qx[stx]);
                pushy(qy[sty]);
                pushz(qz[stz]+1);
            }
            if((qz[stz]-1>=1)&&(a[qx[stx]][qy[sty]][qz[stz]-1]==0))
            {
                a[qx[stx]][qy[sty]][qz[stz]-1]=a[qx[stx]][qy[sty]][qz[stz]]+1;
                sum++;
                pushx(qx[stx]);
                pushy(qy[sty]);
                pushz(qz[stz]-1);
            }
        }
        popx();
        popy();
        popz();
    }
    printf("%d",sum);
    return 0;
}

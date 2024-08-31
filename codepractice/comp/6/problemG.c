#include<stdio.h>
int H,W,qx[10000000],qy[10000000],T[10000000],sty=0,endy=0,stx=0,endx=0,stt=0,endt=0;
char map[105][105];
void pushx(int k)
{
    qx[endx]=k;
    endx++;
}
void popx()
{
    qx[stx]=0;
    stx++;
}
void pushy(int k)
{
    qy[endy]=k;
    endy++;
}
void popy()
{
    qy[sty]=0;
    sty++;
}
void pusht(int k)
{
    T[endt]=k;
    endt++;
}
void popt()
{
    T[stt]=0;
    stt++;
}
int main()
{
    scanf("%d %d",&H,&W);
    for(int i=0;i<H; i++)
    {
        for(int j=0;j<W;j++)
        {
            scanf(" %c",&map[i][j]);
            if(map[i][j]=='S')
            {
                map[i][j]='X';
                pushx(i);
                pushy(j);
                pusht(0);
            }
        }
    }
    while(stx!=endx)
    {
      /*   for(int i=0;i<H; i++)
    {
        for(int j=0;j<W;j++)
        {
            printf("%c ",map[i][j]);
        }
        printf("\n");
    }
    printf("\n\n\n\n");*/
            if(((map[qx[stx]+1][qy[sty]]=='.')||(map[qx[stx]+1][qy[sty]]=='G'))&&(qx[stx]+1<H))
            {
                if(map[qx[stx]+1][qy[sty]]=='G')
                {
                    printf("%d",T[stt]+1);
                    return 0;
                }
                map[qx[stx]+1][qy[sty]]='X';
                pushx(qx[stx]+1);
                pushy(qy[sty]);
                pusht(T[stt]+1);
            }
            if(((map[qx[stx]-1][qy[sty]]=='.')||(map[qx[stx]-1][qy[sty]]=='G'))&&(qx[stx]-1>=0))
            {
                if(map[qx[stx]-1][qy[sty]]=='G')
                {
                    printf("%d",T[stt]+1);
                    return 0;
                }
                map[qx[stx]-1][qy[sty]]='X';
                pushx(qx[stx]-1);
                pushy(qy[sty]);
                pusht(T[stt]+1);
            }
            if(((map[qx[stx]][qy[sty]+1]=='.')||(map[qx[stx]][qy[sty]+1]=='G'))&&(qy[sty]+1<W))
            {
                if(map[qx[stx]][qy[sty]+1]=='G')
                {
                    printf("%d",T[stt]+1);
                    return 0;
                }
                map[qx[stx]][qy[sty]+1]='X';
                pushx(qx[stx]);
                pushy(qy[sty]+1);
                pusht(T[stt]+1);
            }
            if(((map[qx[stx]][qy[sty]-1]=='.')||(map[qx[stx]][qy[sty]-1]=='G'))&&(qy[sty]-1>=0))
            {
                if(map[qx[stx]][qy[sty]-1]=='G')
                {
                    printf("%d",T[stt]+1);
                    return 0;
                }
                map[qx[stx]][qy[sty]-1]='X';
                pushx(qx[stx]);
                pushy(qy[sty]-1);
                pusht(T[stt]+1);
            }
            popx();
            popy();
            popt();

    }
    return 0;
}


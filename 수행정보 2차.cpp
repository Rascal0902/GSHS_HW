#include<stdio.h>
#include<math.h>
#include<iostream>
#define WIDTH 1024
#define HEIGHT 768
#define HEADER 54
using namespace std;
int ct[1025], bl[1025],Y[1025],Yc[1025],i,j,k,l,m=1,n,nm=1,max1=0,max2=0,Ymidx,Ymidy,Bmidx,Bmidy,P1y,P1x,P0y,P0x,P2y,P2x;
unsigned char R[HEIGHT][WIDTH],G[HEIGHT][WIDTH],B[HEIGHT][WIDTH];
double dist=0,sum=0,sum2=0,mid1,mid2;
double x1,x2,z1,z2;
FILE *fp1 = fopen("bezierbefore.bmp","rb");
FILE *fp2 = fopen("copy1.bmp","wb");
FILE *fp3 = fopen("copy1.bmp","rb");
FILE *fp4 = fopen("copy2.bmp","wb");
void Bezier(int P0x,int P0y,int P1x,int P1y,int P2x,int P2y)
{

    double t=0;
    int a,b;
    t=0;
    while(1)
    {
        if(t>=1)
        {
            break;
        }

        a=floor((double)P0y*(1-t)*(1-t)+2*(double)P1y*t*(1-t)+(double)P2y*t*t);
        b=floor((double)P0x*(1-t)*(1-t)+2*(double)P1x*t*(1-t)+(double)P2x*t*t);
        i=0;
        j=0;
        for(i=a-2;i<=a+2;i++)
        {
            for(j=b-2;j<=b+2;j++)
            {
               // printf("%d %d\n",i,j);
               R[i][j]=0;
               G[i][j]=0;
               B[i][j]=0;
            }
        }
        t+=0.0001;
    }
}
int Pcheck()
{

    P0x=10;
    P0y=Y[10];
    P2x=1000;
    P2y=Y[1000];
    printf("%d %d %d %d",Bmidx,Bmidy,Ymidx,Ymidy);
    P1x=Bmidx+(Bmidx-Ymidx);
    P1y=Bmidy+(Bmidy-Ymidy);
    printf(" %d %d",P1x,P1y);
    for(i=P1y-5;i<=P1y+5;i++)
    {
        for(j=P1x-5;j<=P1x+5;j++)
        {
             B[i][j]=0;
             R[i][j]=255;
             G[i][j]=127;
        }
    }
    for(i=P0y-5;i<=P0y+5;i++)
    {
        for(j=P0x-5;j<=P0x+5;j++)
        {
             B[i][j]=0;
             R[i][j]=255;
             G[i][j]=127;
        }
    }
    for(i=P2y-5;i<=P2y+5;i++)
    {
        for(j=P2x-5;j<=P2x+5;j++)
        {
             B[i][j]=0;
             R[i][j]=255;
             G[i][j]=127;
        }
    }
}
void Ymid(int low,int high)
{
    int z;
    z=(low+high)/2;
    Ymidx=z;
    Ymidy=Y[z];
    for(i=Ymidy-5; i<=Ymidy+5; i++)
    {
        for(j=Ymidx-5; j<=Ymidx+5; j++)
        {
            B[i][j]=255;
            R[i][j]=255;
            G[i][j]=255;
        }
    }

}
void ctmax(int low,int high)
{
    for(i=low; i<high; i++)
    {
        if(ct[i]>400)
        {
            continue;
        }
        if(max1<ct[i])
        {
            max1=ct[i];
            max2=i;
        }
    }
    Bmidy=bl[max2];
    Bmidx=max2;

    for(i=bl[max2]-5; i<=bl[max2]+5; i++)
    {
        for(j=max2-5; j<max2+5; j++)
        {
            B[i][j]=0;
            R[i][j]=255;
            G[i][j]=0;
        }
    }
}
void bugcheck(int low1,int high1,int low2,int high2)
{
    for(i=low1; i<high1; i++)
    {
        for(j=low2; j<high2; j++)
        {
            if((B[j][i]==0)&&(G[j][i]==255)&&(R[j][i]==0))
            {
                B[j][i]=225;
                G[j][i]=0;
                R[j][i]=127;
                ct[i]--;
            }
            else if(((B[j][i]==0)&&(G[j][i]==0)&&(R[j][i]==0))||(B[j][i]==0)&&(G[j][i]==255)&&(R[j][i]==255))
            {
                j=HEIGHT-21;
            }
            else {}
        }
    }
}
void green(int low1,int high1,int low2,int high2)
{
    for(i=low1; i<high1; i++)
    {
        j=1;
        if((Y[i]-bl[i]<=3)&&(Y[i]-bl[i]>=-3))
        {
            continue;
        }
        for(j=low2; j<300; j++)
        {
            //printf("%d %d\n",i,j);

            if((R[Y[i]+j*Yc[i]][i]==0)&&(G[Y[i]+j*Yc[i]][i]==0)&&(B[Y[i]+j*Yc[i]][i]==0)&&(nm==1))
            {
                j=767;
                nm=2;
            }
            else if(nm==1)
            {
                ct[i]++;
                R[Y[i]+j*Yc[i]][i]=0;
                G[Y[i]+j*Yc[i]][i]=255;
                B[Y[i]+j*Yc[i]][i]=0;
            }
            else {}
        }
        nm=1;

    }
}
void upblue()
{
    for(i=HEIGHT; i>HEIGHT-50; i--)
    {
        B[i][j]=255;
        G[i][j]=0;
        R[i][j]=0;
    }


}
void line(int low,int high)
{
    for(i=low; i<high; i++)
    {

        n=floor(double((z2-z1))*((double)i/WIDTH)+z1);
        Y[i]=n;
        if(B[n][i]==225)
        {
            Yc[i]=1;
        }
        else
        {
            Yc[i]=-1;
        }
        //printf("%d\n",Yc[i]);
        G[n][i]=255;
        R[n][i]=255;
        B[n][i]=0;

        n=0;
    }
}
void checkblack2(int where)
{
    j=where;
    for(i=0; i<HEIGHT; i++)
    {
        if((B[i][j]==0)&&(G[i][j]==0)&&(R[i][j]==0))
        {
            x2=j;
            z2=i;
        }

    }
}
void checkblack1(int where)
{
    j=where;
    for(i=0; i<HEIGHT; i++)
    {
        if((B[i][j]==0)&&(G[i][j]==0)&&(R[i][j]==0))
        {
            x1=j;
            z1=i;
        }

    }
}
void half(int low1, int high1,int low2,int high2)
{
    for(j=low1; j<high1; j++)
    {
        for(i=low2; i<high2; i++)
        {
            if((B[i][j]==0)&&(G[i][j]==0)&&(R[i][j]==0)&&(m==1))
            {
                m=0;
                if(j==1)
                {
                    x2=(double)j;
                    z2=(double)i;
                }
                else
                {
                    x1=(double)x2;
                    z1=(double)z2;
                    x2=(double)j;
                    z2=(double)i;
                }
            }
            else
            {
            }
        }
        m=1;
        if(j>=3)
        {
            dist=sqrt((double)((x2-x1)*(x2-x1)+(z2-z1)*(z2-z1)));
            sum+=dist;
        }
    }
    for(j=low1; j<high1; j++)
    {
        for(i=low2; i<high2; i++)
        {
            if((B[i][j]==255)&&(G[i][j]==255)&&(R[i][j]==255)&&(m==1))
            {
                continue;
            }
            else if((B[i][j]==0)&&(G[i][j]==0)&&(R[i][j]==0)&&(m==1))
            {
                m=0;
                if(j==2)
                {
                    x2=(double)j;
                    z2=(double)i;
                }
                else
                {
                    x1=(double)x2;
                    z1=(double)z2;
                    x2=(double)j;
                    z2=(double)i;
                }
            }
            else
            {
            }
        }
        m=1;
        if(j>=3)
        {
            dist=sqrt((double)((x2-x1)*(x2-x1)+(z2-z1)*(z2-z1)));
            sum2+=(double)dist/sum;
            if(sum2>0.5)
            {
                mid1=x2;
                mid2=z2;
                for(k=mid1-5; k<=mid1+5; k++)
                {
                    for(l=mid2-5; l<=mid2+5; l++)
                    {
                        /*R[l][k]=255;
                        B[l][k]=0;
                        G[l][k]=0;*/
                    }
                }
                break;
            }
        }
    }

}
void print2()
{
    for(i=1; i<HEIGHT; i++)
    {
        for(j=0; j<WIDTH; j++)
        {
            putc(B[i][j],fp4);
            putc(G[i][j],fp4);
            putc(R[i][j],fp4);
        }
    }
}
void print1()
{
    for(i=1; i<HEIGHT; i++)
    {
        for(j=0; j<WIDTH; j++)
        {
            putc(B[i][j],fp2);
            putc(G[i][j],fp2);
            putc(R[i][j],fp2);
        }
    }
}
void color(int low1, int high1,int low2,int high2)
{
    for(j=low1; j<high1; j++)
    {
        for(i=low2; i<high2; i++)
        {
            if((B[i][j]==255)&&(G[i][j]==255)&&(R[i][j]==255)&&(m==1))
            {

                B[i][j]=225;
                G[i][j]=0;
                R[i][j]=127;
            }
            else if((B[i][j]==0)&&(G[i][j]==0)&&(R[i][j]==0)&&(m==1))
            {
                m=0;
            }
            else
            {
                B[i][j]=255;
                G[i][j]=0;
                R[i][j]=0;
            }
        }
        m=1;
    }
}
void colorblack()
{
    for(j=2; j<WIDTH; j++)
    {
        B[bl[j]][j]=0;
        G[bl[j]][j]=0;
        R[bl[j]][j]=0;
    }
}
void blackcheck()
{
    for(j=2; j<WIDTH; j++)
    {
        for(i=0; i<HEIGHT; i++)
        {
            if((B[i][j]==0)&&(G[i][j]==0)&&(R[i][j]==0))
            {
                bl[j]=i;
            }
        }
    }
}
void check2()
{
    for(i=0; i<HEIGHT; i++)
    {
        for(j=0; j<WIDTH; j++)
        {
            B[i][j]=0;
            G[i][j]=0;
            R[i][j]=0;
            B[i][j]=getc(fp3);
            G[i][j]=getc(fp3);
            R[i][j]=getc(fp3);
        }
    }
}
void check1()
{
    for(i=0; i<HEIGHT; i++)
    {
        for(j=0; j<WIDTH; j++)
        {
            B[i][j]=getc(fp1);
            G[i][j]=getc(fp1);
            R[i][j]=getc(fp1);
        }
    }
}
void header1()
{
    for(i=0; i<HEADER; i++)
    {
        putc(getc(fp1),fp2);
    }
}
void header2()
{
    for(i=0; i<HEADER; i++)
    {
        putc(getc(fp3),fp4);
    }
}
void goBezier( int low,int high)
{
    m=1;

    checkblack1(low+2);
    checkblack2(high);
    line(low+2,high-10);
    colorblack();
    upblue();
    green(low+1,high-20,1,768);
    colorblack();
    bugcheck(low+4,high-20,5,HEIGHT-20);
    ctmax(low+2,high-20);
    colorblack();
    Ymid(low+1,high-4);
    Pcheck();
    Bezier(P0x,P0y,P1x,P1y,P2x,P2y);
}
int main()
{
    header1();
    check1();
    blackcheck();
    colorblack();
    color(0,WIDTH,0,HEIGHT);
    m=1;
    colorblack();
    print1();
    fclose(fp1);
    fclose(fp2);
    header2();
    check2();
    goBezier(1,WIDTH-10);
    print2();
    printf("finish");
    return 0;
}


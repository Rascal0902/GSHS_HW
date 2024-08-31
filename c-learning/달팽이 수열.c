#include<stdio.h>
int main()
{
    int i,j,k=0,a[5][5]={0};
    for(j=0;j<5;j++)
    {
            if(k<5)
            a[0][j]=++k;
    }
    for(i=1;i<5;i++)
    {
           if(k<9)
            a[i][4]=++k;
    }
    for(j=3;j>=0;j--)
    {
           if(k<13)
            a[4][j]=++k;
    }
    for(i=3;i>= 1;i--)
    {
           if(k<16)
            a[i][0]=++k;
    }
    for(j=1;j<4;j++)
    {
           if(k<19)
            a[1][j]=++k;
    }

     a[2][3]=20;
     a[3][3]=21;
     a[3][2]=22;
     a[3][1]=23;
     a[2][1]=24;
     a[2][2]=25;
    for(i=0;i<5;i++)
    {
        for(j=0;j<5;j++)
        {
            printf("%3d",a[i][j]);
        }
        printf("\n");
    }


}

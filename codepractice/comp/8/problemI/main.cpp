#include<stdio.h>
#include<iostream>
using namespace std;
int Fx,Fy,Cx,Cy,cnt=0,NC=0,NF=0;
int dx[4]={-1,0,1,0},dy[4]={0,1,0,-1};
char a[15][15];
int main()
{
    for(int i=0;i<10;i++)
    {
        scanf("%s",a[i]);
        for(int j=0;j<10;j++)
        {
            if(a[i][j]=='F')
            {
                Fx=i;
                Fy=j;
            }
            if(a[i][j]=='C')
            {
                Cx=i;
                Cy=j;
            }
        }
    }
    while(1)
    {
        if(((Fx==Cx)&&(Fy==Cy))||(cnt==10000000))
        {
            break;
        }
        else
        {
            if((a[Fx+dx[NF%4]][Fy+dy[NF%4]]!='*')&&(Fx+dx[NF%4]>=0)&&(Fx+dx[NF%4]<=9)&&(Fy+dy[NF%4]>=0)&&(Fy+dy[NF%4]<=9))
            {
                Fx=Fx+dx[NF%4];
                Fy=Fy+dy[NF%4];
            }
            else
            {
                NF++;
            }
            if((a[Cx+dx[NC%4]][Cy+dy[NC%4]]!='*')&&(Cx+dx[NC%4]>=0)&&(Cx+dx[NC%4]<=9)&&(Cy+dy[NC%4]>=0)&&(Cy+dy[NC%4]<=9))
            {
                Cx=Cx+dx[NC%4];
                Cy=Cy+dy[NC%4];
            }
            else
            {
                NC++;
            }
            cnt++;
        }
    }
    if(cnt==10000000)
    {
        printf("0");
    }
    else
    {
        printf("%d",cnt);
    }
    return 0;
}

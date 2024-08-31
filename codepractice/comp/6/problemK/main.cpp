#include<stdio.h>
#include<iostream>
#include<utility>
#include<queue>
using namespace std;
queue < pair<int, pair<int, int> > > Q;
int map[1005][1005],chk[1005][1005][5],n,m,finx,finy;
int main()
{
    scanf("%d %d",&m,&n);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            scanf("%d",&map[i][j]);
            if(map[i][j]==2)
            {
                chk[i][j][0]=0;
                Q.push({0, {i,j}});
            }
            if(map[i][j]==3)
            {
                finx=i;
                finy=j;
            }
        }
    }
    while(!Q.empty())
    {
        int s,t,x,y;
        s=(Q.front()).first;
        x=(Q.front().second).first;
        y=(Q.front().second).second;
        if((x==finx)&&(y==finy)&&(s==1))
        {
            printf("%d",chk[x][y][1]);
            return 0;
        }
        else
        {
            int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};
            for(int i=0;i<4;i++)
            {
                if((x+dx[i]<0)||(x+dx[i]>=n)||(y+dy[i]<0)||(y+dy[i]>=m))
                {
                    continue;
                }
                if((map[x+dx[i]][y+dy[i]]==4)&&(chk[x+dx[i]][y+dy[i]][1]==0))
                {
                    chk[x+dx[i]][y+dy[i]][1]= chk[x][y][s]+1;
                    Q.push({1,{x+dx[i],y+dy[i]}});
                }
                else
                {
                    if((map[x+dx[i]][y+dy[i]]!=1)&&(chk[x+dx[i]][y+dy[i]][s]==0)&&(x+dx[i]>=0)&&(x+dx[i]<n)&&(y+dy[i]>=0)&&(y+dy[i]<m))
                    {
                        if((x+dx[i]==finx)&&(y+dy[i]==finy)&&(s==1))
                        {
                            printf("%d",chk[x][y][s]+1);
                            return 0;
                        }
                        chk[x+dx[i]][y+dy[i]][s]=chk[x][y][s]+1;
                        Q.push({s,{x+dx[i],y+dy[i]}});
                    }
                }
            }
            Q.pop();
        }
    }
}

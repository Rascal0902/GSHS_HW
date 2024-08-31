#include<stdio.h>
#include<iostream>
#include<utility>
#include<queue>
#include<memory.h>
using namespace std;
queue <pair <int, int> > q1,q2,q3;
int map[1005][1005],n,m,v[1005][1005];
bool isempty()
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(map[i][j]!=0)
            {
                return 0;
            }
        }
    }
    return 1;
}
int main()
{
    int cnt=0;
    scanf("%d %d",&n,&m);
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            scanf("%d",&map[i][j]);
            if(map[i][j]==1)
            {
                map[i][j]=2;
            }
            else
            {
                map[i][j]=0;
                cnt++;
            }
        }
    }
    int time=0;
    while(1)
    {
        int a,b;
        int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1} ;
        q3.push({0,0});
        q1.push({0,0});
        memset(v,0,sizeof(v));
        v[0][0]=1;
        while(!q3.empty())
        {
            a=(q3.front()).first;
            b=(q3.front()).second;
                   for(int i=0; i<4; i++)
                    {
                        if((a+dx[i]>=0)&&(b+dy[i]>=0)&&(a+dx[i]<n)&&(b+dy[i]<m)&&(map[a+dx[i]][b+dy[i]]==0)&&(v[a+dx[i]][b+dy[i]]==0))
                        {
                            v[a+dx[i]][b+dy[i]]=1;
                            q3.push({a+dx[i],b+dy[i]});
                            q1.push({a+dx[i],b+dy[i]});
                        }

                     }
                    q3.pop();
        }
        if(isempty())
        {
            break;
        }
        else
        {
            while(!q1.empty())
            {
                a=(q1.front()).first;
                b=(q1.front()).second;
                    for(int i=0; i<4; i++)
                    {
                        if((a+dx[i]>=0)&&(b+dy[i]>=0)&&(a+dx[i]<=n)&&(b+dy[i]<=m)&&(map[a+dx[i]][b+dy[i]]>=1))
                        {
                            map[a+dx[i]][b+dy[i]]--;
                        }

                    }
                    q1.pop();
                }
            }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(map[i][j]>=1)
            {
                map[i][j]=2;
            }
        }
    }
    time++;
    }
    printf("%d",time);
    return 0;
}
/*
20 30
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 1 1 0 1 0 1 1 1 1 1 0 1 0 1 1 1 0 0 1 0 1 0 1 0
0 1 1 0 0 0 0 0 1 0 1 0 1 0 0 0 1 0 0 0 1 1 0 0 1 0 0 1 0 0
0 1 0 0 0 0 0 1 1 0 0 1 1 1 0 1 0 0 0 0 0 0 0 1 1 0 1 0 0 0
0 0 0 0 1 0 0 0 0 0 1 1 0 1 1 0 1 0 0 0 1 0 0 1 1 0 0 1 0 0
0 0 0 0 0 1 0 0 0 1 1 1 0 1 0 0 0 0 0 1 0 1 0 1 0 1 0 1 0 0
0 1 1 1 0 0 1 0 1 0 0 1 0 1 1 0 1 0 0 1 1 0 0 1 1 0 1 0 0 0
0 0 0 1 0 0 1 1 0 0 0 0 1 0 1 0 0 0 1 0 0 0 0 1 0 0 1 0 0 0
0 0 0 1 0 0 0 0 0 1 1 0 0 0 0 0 0 1 0 0 0 0 1 1 0 0 0 1 1 0
0 0 1 1 0 1 0 0 0 0 0 1 0 1 1 0 0 0 0 0 1 0 1 0 0 1 0 0 1 0
0 1 0 0 1 0 1 1 1 0 1 0 0 1 1 1 1 1 1 1 1 0 0 1 0 1 1 1 0 0
0 1 1 0 1 0 1 1 0 1 0 0 0 0 0 1 0 0 1 0 0 0 0 0 0 1 0 1 0 0
0 0 1 0 0 0 0 1 1 1 0 0 0 0 0 0 0 0 1 0 1 0 0 0 1 0 0 0 1 0
0 1 0 0 0 0 0 0 0 1 0 1 0 0 0 0 1 0 0 0 0 0 0 1 1 0 0 1 0 0
0 0 1 0 0 0 0 0 0 0 1 0 0 1 1 0 0 1 0 0 1 0 0 0 0 0 0 0 1 0
0 0 0 0 0 0 0 1 0 0 1 1 1 0 0 0 1 1 0 0 0 1 0 1 0 0 0 1 0 0
0 0 0 0 1 0 0 0 0 1 0 1 1 0 0 0 1 0 0 0 0 0 0 0 1 1 1 1 1 0
0 1 1 1 0 0 0 0 1 1 1 0 0 0 0 1 1 1 1 0 1 0 1 1 1 1 0 0 0 0
0 1 0 0 0 0 0 1 0 0 0 1 1 1 0 0 1 1 0 1 0 0 0 0 0 0 1 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0*/

#include<stdio.h>
#include<iostream>
#include<queue>
using namespace std;
queue <pair <int , int> > q,q3;
int n,h,w,kr,map[105][105],v[105][105],dx[4]={-1,0,1,0},dy[4]={0,1,0,-1};
int ans[1000],ansend=0;
int main()
{
    scanf("%d",&n);
    for(int i=0; i<n; i++)
    {
        scanf("%d %d %d",&h,&w,&kr);
        for(int j=0; j<h; j++)
        {
            for(int k=0; k<w; k++)
            {
                scanf("%d",&map[j][k]);
                if(map[j][k]>kr)
                {
                    map[j][k]-=kr;
                    q.push({j,k});
                }
                else
                {
                    map[j][k]=0;
                }

            }
        }
        int cnt=0;
        while(!q.empty())
        {
            int x,y,a,b;
            x=(q.front()).first;
            y=(q.front()).second;
            q.pop();
            if(v[x][y]==0)
            {
                cnt++;
                v[x][y]=1;
                q3.push({x,y});
                while(!q3.empty())
                {
                    a=(q3.front()).first;
                    b=(q3.front()).second;
                    for(int n=0; n<4; n++)
                    {
                        if((a+dx[n]>=0)&&(b+dy[n]>=0)&&(a+dx[n]<h)&&(b+dy[n]<w)&&(map[a+dx[n]][b+dy[n]]>=1)&&(v[a+dx[n]][b+dy[n]]==0))
                        {
                            v[a+dx[n]][b+dy[n]]=1;
                            q3.push({a+dx[n],b+dy[n]});
                        }

                    }
                    q3.pop();
                }
            }

        }
        for(int g=0;g<h;g++)
        {
            for(int y=0;y<w;y++)
            {
                v[g][y]=0;
            }
        }
         ans[ansend]=cnt;
         ansend++;
    }
    for(int i=0;i<ansend;i++)
    {
        printf("%d\n",ans[i]);
    }
    return 0;
}


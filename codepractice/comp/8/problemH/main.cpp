#include<stdio.h>
#include<iostream>
#include<queue>
#include<utility>
#include<algorithm>
using namespace std;
int v[1005][85],H,W,ans[100000000],cnt=0,n;
int map1[1005][85];
queue <pair<int, int> > bfs,bfs2;
int main()
{
    scanf("%d",&n);
    W=n;
    H=n;
    for(int i=0;i<H;i++)
    {
        for(int j=0;j<W;j++)
        {
            scanf("%1d",&map1[i][j]);
            if(map1[i][j]==1)
            {
                bfs.push( { i,j } );
            }
        }
    }
    int x,y,dx[4]={0,1,0,-1},dy[4]={1,0,-1,0},sum=0;
    while(!bfs.empty())
    {
        if((map1[(bfs.front()).first][(bfs.front()).second]!=0)&&(v[(bfs.front()).first][(bfs.front()).second]==0))
        {
            sum=0;
            bfs2.push( { (bfs.front()).first,(bfs.front()).second } ) ;
            while(!bfs2.empty())
            {
                x=(bfs2.front()).first;y=(bfs2.front()).second;
                sum++;
                bfs2.pop();
                v[x][y]=1;
                for(int i=0;i<4;i++)
                {
                    if((v[x+dx[i]][y+dy[i]]==0)&&(map1[x+dx[i]][y+dy[i]]==1)&&(x+dx[i]>=0)&&(x+dx[i]<H)&&(y+dy[i]>=0)&&(y+dy[i]<W))
                    {
                        v[x+dx[i]][y+dy[i]]=1;
                        bfs2.push( { x+dx[i],y+dy[i] } );
                    }
                }
            }
            ans[cnt]=sum;
            cnt++;
        }
        bfs.pop();
    }
    printf("%d\n",cnt);
    sort(ans,ans+cnt);
    for(int i=0;i<cnt;i++)
    {
        printf("%d\n",ans[i]);

    }
    return 0;
}
/*입력
3
101
101
100

출력
2
2
3
*/

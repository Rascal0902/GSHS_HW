
#include<stdio.h>
#include<iostream>
#include<utility>
#include<queue>
using namespace std;
queue < pair <int, int> > Q;
int map[1005][1005],n;
char x[1005];
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%s",x);
        for(int j=0;j<n;j++)
        {
            if(x[j]=='1')
            {
                map[i][j]=1;
                Q.push({i,j});
            }
        }
    }
    while(!Q.empty())
    {
        int x,y;
        x=(Q.front()).first;
        y=(Q.front()).second;
        for(int i=0;i<n;i++)
        {
            if(((map[x][i]==1)||(map[i][x]==1))&&((map[y][i]==0)||(map[i][y]==0))&&(i!=y)&&(i!=x))
            {
                map[i][y]=1;
                map[y][i]=1;
                Q.push({i,y});
            }
            if(((map[y][i]==1)||(map[i][y]==1))&&((map[x][i]==0)||(map[i][x]==0))&&(i!=x)&&(i!=y))
            {
                map[i][x]=1;
                map[x][i]=1;
                Q.push({i,x});
            }
        }
        Q.pop();
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("%d ",map[i][j]);
        }
        printf("\n");
    }
    return 0;
}

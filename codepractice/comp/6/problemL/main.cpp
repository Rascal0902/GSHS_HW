#include<stdio.h>
#include<iostream>
#include<utility>
#include<queue>
using namespace std;
queue <pair <int, int> > q1,q2;
char x[1005];
int map[1005][1005],n,m;
int main()
{
    scanf("%d %d",&n,&m);
    for(int i=0; i<n; i++)
    {
        scanf("%s",x);
        for(int j=0; j<m; j++)
        {
            if(((int)(x[j]-'0')>=0)&&((int)(x[j]-'0')<=9))
            {
                map[i][j]=(int)(x[j]-'0');
            }
            else
            {
                map[i][j]=1000;
                q1.push({i,j});
            }
        }
    }
    int time=0;
    while(1)
    {
        if(q1.empty())
        {
            time--;
            break;
        }
        else
        {
            while(!q1.empty())
            {
                int a,b;
                a=(q1.front()).first;
                b=(q1.front()).second;
                //printf("%d %d\n",a,b);
                    int dx[8]= {1,1,0,-1,-1,-1,0,1},dy[8]= {0,-1,-1,-1,0,1,1,1} ;
                    for(int i=0; i<8; i++)
                    {
                        if((a+dx[i]>=0)&&(b+dy[i]>=0)&&(a+dx[i]<=n)&&(b+dy[i]<=m)&&(map[a+dx[i]][b+dy[i]]>=1))
                        {
                            map[a+dx[i]][b+dy[i]]--;
                            if(map[a+dx[i]][b+dy[i]]==0)
                            {
                                q2.push({a+dx[i],b+dy[i]});
                            }
                        }

                    }
                    q1.pop();
                }
            }

        /*printf("\n\n\n");
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                printf("%d  ",map[i][j]);
            }
            printf("\n");
        }*/
        time++;
        q1=q2;
        while(!q2.empty())
        {
            q2.pop();
        }
    }
    printf("%d",time);
    return 0;

}

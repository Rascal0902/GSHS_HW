#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
vector <int> v[2005];
queue <int> q;
int n,m,visit[2005];

int main()
{
    scanf("%d %d",&n,&m);
    int x,y;
    for(int i=0;i<m;i++)
    {
        scanf("%d %d",&x,&y);
        v[x].push_back(y);
        v[y].push_back(x);
    }
    printf("%d ",1);
    visit[1]=1;
    q.push(1);
    while(!q.empty())
    {
        int t;
        t=q.front();
        q.pop();
        for(int i=0; i<v[t].size(); i++)
        {
            if(visit[v[t][i]]==0)
            {
                printf("%d ",v[t][i]);
                visit[v[t][i]]=1;
                q.push(v[t][i]);
            }

        }
    }
    return 0;
}


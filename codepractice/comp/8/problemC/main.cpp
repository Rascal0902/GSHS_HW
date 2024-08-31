#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
vector <int> v[105];
queue <int> q;
int n,m,visit[105];

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
    for( int i=1;i<=n;i++)
    {
        sort(v[i].begin(),v[i].end());
    }
    printf("1");
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
                printf(" %d",v[t][i]);
                visit[v[t][i]]=1;
                q.push(v[t][i]);
            }

        }
    }
    return 0;
}

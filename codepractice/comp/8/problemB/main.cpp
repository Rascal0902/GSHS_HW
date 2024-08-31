#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector <int> v[2005];
int n,m,visit[2005];
void dfs(int t)
{
    for(int i=0;i<v[t].size();i++)
    {
        if(visit[v[t][i]]==0)
        {
            printf("%d ",v[t][i]);
            visit[v[t][i]]=1;
            dfs(v[t][i]);
        }

    }
}
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
    /*for( int i=1;i<=n;i++)
    {
        sort(v[i].begin(),v[i].end());
    }*/
    printf("%d ",1);
    visit[1]=1;
    dfs(1);
}

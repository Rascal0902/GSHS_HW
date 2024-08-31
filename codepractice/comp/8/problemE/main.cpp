#include<iostream>
#include<queue>
#include<stdio.h>
using namespace std;
#define INF 922337203685
struct node{long long int k, len;};
struct ver {long long int idx, w;};
bool operator<(node a,node b){return a.len > b.len; }
long long int v,e;
vector <long long int> length;
vector<vector<ver> > adj;
priority_queue<node> pq;
main()
{
    cin >> v >> e;
    length.resize(v+5,INF), adj.resize(v+5);
    int st=1;
    while(e--)
    {
        int u,v,w; cin >> u >> v >>w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    pq.push({st,0});
    length[st]=1;
    while(!pq.empty())
    {
        long long int k=pq.top().k;
        long long int len=pq.top().len;
        pq.pop();
        if(length[k]<=len) continue;
        length[k]=len;
        for(auto i : adj[k])
        {pq.push({i.idx,(i.w)+len});}
    }
    if(length[v]==INF)
    {
        printf("-1");
    }
    else
    {
        printf("%lld",length[v]);
    }
    return 0;
}

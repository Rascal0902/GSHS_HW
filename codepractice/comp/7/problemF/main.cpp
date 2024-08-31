/*#include<stdio.h>
#include<iostream>
#include<queue>
#include<utility>
#include<vector>
#include<memory.h>
#define INF 922337203685
using namespace std;
struct RANGE
{
    long long int s,e,M;
    RANGE()
    {
        s=0;
        e=0;
    }
    RANGE(long long int a,long long int b,long long int c)
    {
        s=a;
        e=b;
        M=c;
    }
};
bool operator<(const RANGE A,const RANGE B)
{
    long long int disa=A.M;
    long long int disb=B.M;
    return disa>disb;
}
priority_queue <RANGE> q,b;
queue <long long int> Q;
vector <pair<long long int,long long int> > a[100005];
long long int N,M,v[100005],m[100005];
int main()
{
    scanf("%lld %lld",&N,&M);
    for(long long int i=1; i<=N; i++)
    {
        m[i]=INF;
    }
    long long int st,en,mo;
    for(int i=1;i<=M;i++)
    {
        scanf("%lld %lld %lld",&st,&en,&mo);
        a[st].push_back({en,mo});
        a[en].push_back({st,mo});
    }
    Q.push(1);
    v[1]=1;
    m[1]=0;
    long long int start;
    while(!Q.empty())
    {
        start=Q.front();
        Q.pop();
        for(int i=0;i<a[start].size();i++)
        {
            if(v[a[start][i].first]==1)
            {
                continue;
            }
            else
            {
                q.push(RANGE(start,a[start][i].first,a[start][i].second));
            }
        }
        b=q;
        while(!b.empty())
        {
            if(v[(b.top()).e]!=0)
            {
                continue;
            }
            else
            {
                Q.push((b.top()).e);
            }
            b.pop();
        }
        if(!q.empty())
        {
            long long int lowdistance;
            lowdistance=(q.top()).e;
            if(m[lowdistance]>m[start]+(q.top()).M)
            {
                m[lowdistance]=m[start]+(q.top()).M;
            }
            v[lowdistance]=1;
            q.pop();
            while(!q.empty())
            {
                if(m[(q.top()).e]>m[start]+(q.top()).M)
                {
                    m[(q.top()).e]=m[start]+(q.top()).M;
                }

                q.pop();
            }
        }
    }
    long long int max=0,indexi=0;
    for(int i=1;i<=N;i++)
    {
        if((max<m[i])&&(m[i]!=INF))
        {
            max=m[i];
            indexi=(long long int)i;
        }
    }
    long long int index=0;
    for(int i=1; i<=N; i++)
    {
        if(max==m[i])
        {
            index++;
        }
    }
    printf("%lld %lld",indexi,index);
    return 0;
}*/
/*
입력
5 5
1 2 7
1 4 2
2 3 3
3 4 8
5 4 8


출력
3 2
*/
/*#include<iostream>
#include<queue>
#include<vector>
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
    long long int max=-5,indexi=0,index=0;
    length[1]=0;
    for(int i=1;i<=v;i++)
    {
        if(max<length[i])
        {
            max=length[i];
            indexi=(long long int)i;
        }
    }
    for(int i=1;i<=v;i++)
    {
        if(max==length[i])
        {
            index++;
        }
    }
   cout << indexi << " " << index;
    return 0;
}
/*for(int i=1; i<=v; i++)
    {
        if(length[i]==INT_MAX) cout << "INF\n";
        else cout << length[i] << '\n';
    }*/
#include<stdio.h>
#include<iostream>
#include<vector>
#include<queue>
#define INF INT_MAX
using namespace std;
struct node{int idx;int money;};
struct node2{int witch;int length;};
bool operator<(node A,node B){return A.money>B.money;}
vector<vector<node2>> adj;
vector<int> length;
priority_queue <node> pq;
int v,e;
int main()
{
    scanf("%d %d",&v,&e);
    length.resize(v+5,INF);adj.resize(v+5);
    int st=1;
    for(int i=0;i<e;i++)
    {
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        adj[a].push_back({b,c});
        adj[b].push_back({a,c});
    }
    length[1]=1;
    pq.push({st,0});
    while(!pq.empty())
    {
        int idxf=pq.top().idx;
        int moneyf=pq.top().money;
        pq.pop();
        if(length[idxf]<=moneyf) continue;
        length[idxf]=moneyf;
        for(auto i: adj[idxf])
        {
            pq.push({i.witch,(i.length)+moneyf});
        }
    }
    for(int i=1; i<=v; i++)
    {
        if(length[i]==INT_MAX) cout << "INF\n";
        else cout << length[i] << '\n';
    }
}

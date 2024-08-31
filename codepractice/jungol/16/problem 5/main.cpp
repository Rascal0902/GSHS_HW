//해밀턴 순환 회로
/*#include<stdio.h>
#include<iostream>
#include<vector>
using namespace std;
int map[15][15],v[100],n,ans=100000;
struct node{ int ans, money;};
vector < vector< node > > adj;
bool isout()
{
    for(int i=1;i<=n;i++)
    {
        if(v[i]==0)
        {
            return false;
        }
    }
    return true;
}
void dfs(int node,int mon)
{
    if(mon>ans)
    {
        return;
    }
    if(isout())
    {
        if((map[node][1]!=0)&&(ans>mon+map[node][1]))
        {
            ans=mon+map[node][1];
        }
        return;
    }
   for(auto i: adj[node])
   {
       if(v[i.ans]==0){
           v[i.ans]=1;
           dfs(i.ans,mon+i.money);
           v[i.ans]=0;
       }
   }
   return;
}
int main()
{
      adj.resize(15);
      scanf("%d",&n);
      for(int i=1;i<=n;i++)
      {
          for(int j=1;j<=n;j++)
          {
              scanf("%d",&map[i][j]);
              if((i!=j)&&(map[i][j]!=0))
              {
                  adj[i].push_back({j,map[i][j]});
              }
          }
      }
      v[1]=1;
      dfs(1,0);
      printf("%d",ans);
      return 0;
}*/
//N-queen
/*#include<iostream>
int n,col[15],tr1[50],tr2[50],ans=0;
void dfs(int row)
{
    if(row==n)
    {
        ans++;
        return;
    }
    for(int i=0;i<n;i++)
    {
        if((col[i]==0)&&(tr1[25+row-i]==0)&&(tr2[row+i]==0))
        {
            col[i]=1;tr1[25+row-i]=1;tr2[row+i]=1;
            dfs(row+1);
            col[i]=0;tr1[25+row-i]=0;tr2[row+i]=0;
        }
    }
    return;
}
int main()
{
    scanf("%d",&n);
    dfs(0);
    printf("%d",ans);
    return 0;
}*/
//숫자 구술
/*#include<stdio.h>
#include<iostream>
using namespace std;
int n,a[100];
int dfs(int node)
{
    if(node==n)
    {
        for(int i=0;i<n;i++)
        {
            printf("%d",a[i]);
        }
        exit(0);
    }
    else
    {
        for(int i=1;i<=3;i++)
        {
            a[node]=i;
            int check=1;
            for(int dx=1;dx<=n;dx++)
            {
                int set=0;
                if(node-2*dx+1<0){dx=n+1;continue;}
                    for(int j=node-2*dx+1;j<=node-dx;j++)
                    {
                        if(a[j]!=a[j+dx])
                        {
                            set=1;
                        }
                    }
                if(set==0)
                {
                    check=0;
                }
            }
            if(check==1)
            {
               dfs(node+1);
            }
            a[node]=0;
        }
        return 0;
    }
}
int main()
{
    scanf("%d",&n);
    a[0]=1;
    dfs(1);
    return 0;
}
*/
//DNA 조합
/*#include<stdio.h>
#include<iostream>
#include<string.h>
using namespace std;
int n,v[10],min1=105,cnt=0;
char a[10][10],ans[1000];
int dfs(int t)
{
    if(t==n+1)
    {
        printf("%s\n",ans);
        if(cnt<min1)
        {
            min1=cnt;
        }
    }
    else
    {
        int now=cnt;
        for(int i=1;i<=n;i++)
        {
            if(v[i]==1){continue;}
            int j=cnt-1,k=0;
            for(int g=0;g<=100;g++)
            {
                if((j==-1)||(k==strlen(a[i]))||(ans[j]!=a[i][k]))
                {
                    break;
                }
                j--;
                k++;
            }
            while(1)
            {
                if(k==strlen(a[i]))
                {
                    break;
                }
                ans[cnt]=a[i][k];
                cnt++;k++;
            }
            v[i]=1;
            dfs(t+1);
            v[i]=0;
            for(int j=now;j<=cnt;j++)
            {
               ans[j]=' ';
            }
            cnt=now;
        }
    }
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%s",a[i]);
    }
    dfs(1);
    printf("%d",min1);
    return 0;
}*/
//회의실 배정
/*#include<stdio.h>
#include<iostream>
#include<utility>
#include<algorithm>
#include<vector>
using namespace std;
struct node{int node,s,e;};
bool operator<(const node& A,const node& B){
   // printf("%d %d::::\n",A.e,B.e);
    return A.e < B.e;
}
vector <node> adj;
int n;
int main()
{
    int node1,s1,e1;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d %d %d",&node1,&s1,&e1);
        adj.push_back({node1,s1,e1});
    }
    sort(adj.begin(),adj.end());
    int a[100],cnt=0,last=0;
    for(int i=0;i<n;i++)
    {
        if(last<=adj[i].s)
        {a[cnt]=adj[i].node;
         cnt++;
         last=adj[i].e;
        }
    }
    printf("%d\n",cnt);
    for(int i=0;i<cnt;i++)
    {
        printf("%d ",a[i]);
    }
    return 0;
}*/
//냉장고
/*#include<stdio.h>
#include<iostream>
#include<utility>
#include<algorithm>
#include<vector>
using namespace std;
struct node{int s,e;};
bool operator<(const node& A,const node& B){return A.s < B.s;}
vector <node> adj;
int n;
int main()
{
    int s1,e1;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d %d",&s1,&e1);
        adj.push_back({s1,e1});
    }
    sort(adj.begin(),adj.end());
    int cnt=0,lastx=adj[0].s,lasty=adj[0].e;
    for(int i=1;i<n;i++)
    {
       if(lasty<adj[i].s){cnt++;lastx=adj[i].s;lasty=adj[i].e;continue;}
        lastx=(lastx<adj[i].s)? adj[i].s:lastx;
        lasty=(lasty<adj[i].e)? lasty:adj[i].e;
    }
    printf("%d",cnt+1);
    return 0;
}
*/
//개구리 점프
/*#include<stdio.h>
#include<iostream>
#include<utility>
#include<algorithm>
#include<vector>
using namespace std;
struct node{int nod,s,e;};
bool operator<(const node& A,const node& B){return A.s < B.s;}
vector <node> adj;
int n,v[10000000];
int main()
{
    int s1,e1,y;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d %d %d",&s1,&e1,&y);
        adj.push_back({i,s1,e1});
    }
    sort(adj.begin(),adj.end());
    int cnt=1,lastx=adj[0].s,lasty=adj[0].e;
    v[adj[0].nod]=1;
    for(int i=1;i<n;i++)
    {
       if(lasty<adj[i].s){cnt++;v[adj[i].nod]=cnt;lastx=adj[i].s;lasty=adj[i].e;continue;}
        lastx=(lastx<adj[i].s)? lastx:adj[i].s;
        lasty=(lasty<adj[i].e)? adj[i].e:lasty;
        v[adj[i].nod]=cnt;
    }
    for(int i=1;i<=n;i++)
    {
        printf("%d ",v[i]);
    }
    return 0;
}
*/
//동적 계획법

/*#include<stdio.h>
#include<iostream>
using namespace std;
int n,v[10],a[10],end1=0;
void push(int k)
{
    a[end1]=k;
    end1++;
}
void pop()
{
    a[end1-1]=0;
    end1--;
}
void f(int k)
{
    if(k==n)
    {
        for(int i=0;i<n;i++)
        {
            printf("%d",a[i]);
        }
        printf("\n");
        return;
    }
    for(int i=n;i>=1;i--)
    {
        if(v[i]==0)
        {
            v[i]=1;
            push(i);
            f(k+1);
            pop();
            v[i]=0;
        }
    }
    return;
}
int main()
{
    scanf("%d",&n);
    int sum=1;
    for(int i=1;i<=n;i++)
    {
        sum*=i;
    }
    printf("%d\n",sum);
    f(0);
    return 0;
}
*/
/*#include<stdio.h>
#include<iostream>
#include<queue>
#include<utility>
using namespace std;
queue <pair <int , int> > q,q1;
int n,m,a[1005][1005],dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};
int main()
{
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            scanf("%1d",&a[i][j]);
            if(a[i][j]==1)
            {
               q.push({i,j});
            }
        }
    }
    int cnt=0;
    while(!q.empty())
    {
        int px,py;
        px=(q.front()).first;
        py=(q.front()).second;
        q.pop();
        if(a[px][py]==0){continue;}
        else
        {
            cnt++;
            q1.push({px,py});
            while(!q1.empty())
            {
                int p2x,p2y;
                p2x=(q1.front()).first;
                p2y=(q1.front()).second;
                q1.pop();
                for(int i=0;i<4;i++)
                {
                if(p2x+dx[i]>=0 && p2x+dx[i]<n && p2y+dy[i]>=0 && p2y+dy[i]<m && a[p2x+dx[i]][p2y+dy[i]]==1)
                  {
                    a[p2x+dx[i]][p2y+dy[i]]=0;
                    q1.push({p2x+dx[i],p2y+dy[i]});
                  }
                }
            }
        }
    }
    printf("%d",cnt);
    return 0;
}*/
#include <stdio.h>
#include <memory.h>
int n,m,A[505][505],a,b,c,sum,v[506],i,j,k;
void f1(int k)
{
    v[k]=1;
    for(int i=1; i<=n; i++)
    {
        if(A[k][i]==1 && v[i]==0)
        {
            c++;
            f1(i);
        }
    }
}
void f2(int k)
{
    v[k]=1;
    for(int i=1; i<=n; i++)
    {
        if(A[k][i]==-1 && v[i]==0)
        {
            c++;
            f2(i);
        }
    }
}
int main()
{
    scanf("%d %d", &n, &m);

    for(i=1; i<=m; i++)
    {
        scanf("%d %d",&a,&b);
        A[a][b]=1;
        A[b][a]=-1;
    }

    for(i=1; i<=n; i++)
    {
        f1(i);
        f2(i);
        if(c==n-1)
        {
            sum++;
        }
        memset(v,0,sizeof(v));
        c=0;
    }
    printf("%d",sum);
}

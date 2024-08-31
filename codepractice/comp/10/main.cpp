//10-1
/*#include<stdio.h>
#include<iostream>
#include<queue>
#include<stack>
using namespace std;
int n,v[100],cnt=0,a[100],enda=0;
void push(int k)
{
    a[enda]=k;
    enda++;
}
void pop()
{
    a[enda-1]=0;
    enda--;
}
int f(int k)
{
    if(k>=n)
    {
        cnt++;
        for(int i=0;i<enda;i++)
        {
            printf("%d",a[i]);
        }
        printf("\n");
        return 1;
    }
    for(int i=n;i>=1;i--)
    {

        if(v[i]==0)
        {
            push(i);
            v[i]=1;
            f(k+1);
            v[i]=0;
            pop();
        }
    }
}
int g(int k)
{
    if(k>=n)
    {
        cnt++;
        return 1;
    }
    for(int i=n;i>=1;i--)
    {

        if(v[i]==0)
        {
            v[i]=1;
            g(k+1);
            v[i]=0;
        }
    }
}
int main()
{
  scanf("%d",&n);
  g(0);
  printf("%d\n",cnt);
  f(0);
  return 0;
}*/
//10-2
/*#include<stdio.h>
#include<iostream>
#include<queue>
#include<utility>
#include<algorithm>
using namespace std;
int H,W,cnt=0,map1[1010][1010];
queue <pair<int, int> > bfs2;
int main()
{
    scanf("%d %d",&H,&W);

    for(int i=0;i<H;i++)
    {
        for(int j=0;j<W;j++)
        {
            scanf("%1d",&map1[i][j]);
        }
    }
    int x,y,dx[4]={0,1,0,-1},dy[4]={1,0,-1,0},sum=0;
    for(int i=0;i<H;i++)
    {
        for(int j=0;j<W;j++)
        {
            if(map1[i][j]==1)
            {
                    sum++;
                    bfs2.push( { i,j} ) ;
                    map1[i][j]=0;
                    while(!bfs2.empty())
                    {
                        x=(bfs2.front()).first;
                        y=(bfs2.front()).second;
                        bfs2.pop();
                        for(int i=0; i<4; i++)
                        {
                            if((map1[x+dx[i]][y+dy[i]]==1)&&(x+dx[i]>=0)&&(x+dx[i]<H)&&(y+dy[i]>=0)&&(y+dy[i]<W))
                            {
                                map1[x+dx[i]][y+dy[i]]=0;
                                bfs2.push( { x+dx[i],y+dy[i] } );
                            }
                        }
                    }
            }
        }
    }
    printf("%d",sum);
    return 0;
}*/
//10-3
/*#include <stdio.h>
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
}*/

//10-4
/*#include<stdio.h>
#include<iostream>
#include<queue>
#include<stack>
#include<utility>
#include<map>
using namespace std;
queue <pair <long long int,int> > q;
map <long long int , long long int> mapk;
long long int map1[5][5],p9[10],cnt=0,v[363000],n,v2[10],a[100],enda=0;
long long int c=0;
void push(int k)
{
    a[enda]=k;
    enda++;
}
void pop()
{
    a[enda-1]=0;
    enda--;
}
int f(int k)
{
    if(k>=n)
    {
        c++;
        long long int sum=0;
        for(int i=0;i<enda;i++)
        {
            sum*=9;
            sum+=a[i];
        }
        mapk.insert(pair< long long int, long long int> (sum,c));
        return 1;
    }
    for(int i=n-1;i>=0;i--)
    {

        if(v[i]==0)
        {
            push(i);
            v[i]=1;
            f(k+1);
            v[i]=0;
            pop();
        }
    }
}
int main()
{
    p9[0]=1;
    for(long long int i=1;i<=9;i++)
    {
        p9[i]=p9[i-1]*9;
    }
    n=9;
    f(0);

    long long int Hanoi=0,end1=0;
    for(long long int i=0;i<3;i++)
    {
        for(long long int j=0;j<3;j++)
        {
            scanf("%lld",&map1[i][j]);
            Hanoi+=p9[i*3+j]*map1[i][j];
            if(!((i==2)&&(j==2)))
            {
                end1+= p9[i*3+j]*(i*3+j+1);

            }
        }
    }
    q.push({Hanoi,0});
    v[mapk[Hanoi]]=1;
    long long int ans=21,dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};
    while(!q.empty())
    {
        long long int x=(q.front()).first,z=(q.front()).first,y=(q.front()).second;
        q.pop();
        if(y>20)
        {
            break;
        }
        if(x==end1)
        {
            ans=y;
            break;
        }
        int a[15],px,py;
        for(long long int i=0;i<9;i++)
        {
            a[i]=x%9;
            x=x/9;
            if(a[i]==0)
            {
                px=i/3;
                py=i%3;
            }
        }
        for(long long int i=0; i<4; i++)
        {
            if((px+dx[i]>=0)&&(px+dx[i]<3)&&(py+dy[i]>=0)&&(py+dy[i]<3))
            {
                long long int temp,newHanoi=0;
                a[px*3+py]=a[(px+dx[i])*3+py+dy[i]];
                a[(px+dx[i])*3+py+dy[i]]=0;
                newHanoi=z;
                newHanoi-=a[px*3+py]*p9[(px+dx[i])*3+py+dy[i]];
                newHanoi+=a[px*3+py]*p9[px*3+py];
                if(v[mapk[newHanoi]]==0)
                {
                    v[mapk[newHanoi]]=1;
                    q.push( { newHanoi,y+1} );
                }

            }
        }

    }
    if(ans==21)
    {
        printf("-1");
    }
    else
    {
        printf("%lld",ans);
    }
    return 0;
}*/
//10-5
/*#include<stdio.h>
#include<iostream>
#include<queue>
#include<stack>
#include<map>
#include<algorithm>
using namespace std;
map <int,int> mp;
int n,a[1000],b[1000],cnt=1,last=0;
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        b[i]=a[i];
    }
    sort(b,b+n);
    mp.insert(pair<int,int> (b[n-1],1));
    last=b[n-1];
    for(int i=n-2;i>=0;i--)
    {
         if(b[i]==last)
         {
             mp.insert(pair<int,int> (b[i],cnt));
         }
         else
         {
             cnt=n-i;
             last=b[i];
             mp.insert(pair<int,int> (b[i],cnt));
         }
    }
    for(int i=0;i<n;i++)
    {
        printf("%d %d\n",a[i],mp[a[i]]);
    }
    return 0;
}*/
//10-6
/*#include<stdio.h>
#include<iostream>
#include<queue>
#include<stack>
using namespace std;
long long int a[100],n,m,v[100],b[15][2],cnt=-1,endb=0,ans[100],sum1[10000000];
bool compare()
{
    long long int x=0,y=0;
    for(long long int i=0;i<endb;i++)
    {
        if(b[i][1]>=6)
        {
            y+=b[i][0]*(b[i][1]-5);
        }
        else
        {
            x+=b[i][0]*(6-b[i][1]);
        }
    }
    if(x==y)
    {
        return true;
    }
    else
    {
        return false;
    }
}
void f(long long int k)
{
    if(k==11)
    {
        if(compare())
        {
            cnt++;
            for(long long int j=0;j<endb;j++)
            {
                ans[b[j][1]]=b[j][0];
            }
            long long int sum=0;
            for(long long int j=1;j<=10;j++)
            {
                sum*=10;
                sum+=ans[j];
            }
            sum1[cnt]=sum;
            for(long long int j=0;j<99;j++)
            {
                ans[j]=0;
            }
        }
    }
    else
    {
        for(long long int i=0;i<=n;i++)
        {
            if(i==0)
            {
                f(k+1);
            }
            else
            {
                if(v[i]==0)
                {
                    v[i]=1;
                    b[endb][0]=a[i];
                    b[endb][1]=k;
                    endb++;
                    f(k+1);
                    v[i]=0;
                    b[endb-1][0]=0;
                    b[endb-1][1]=0;
                    endb--;
                }
            }
        }
    }
}
int main()
{
   scanf("%lld",&n);
   for(long long int i=1;i<=n;i++)
   {
       scanf("%lld",&a[i]);
   }
    scanf("%lld",&m);
    f(1);
    if(cnt<m)
    {
        printf("%lld",sum1[cnt]);
    }
    else
    {
        printf("%lld",sum1[m]);
    }
    return 0;
}
*/
//10-7
/*#include <iostream>
using namespace std;
int N,s,e, M;
int arr[30];
long long int ans=1LL<<61;
void f(int s, int e, long long int cnt, int num)
{
    if(num==M)
    {
        ans=min(ans, cnt);
        return;
    }
    int temp=arr[num];
    if(s<=temp && temp<=e)
    {
        f(s, temp, cnt+abs(e-temp), num+1);
        f(temp, e, cnt+abs(s-temp), num+1);
    }
    else if(temp<s)
    {
        f(temp, e, cnt+abs(s-temp), num+1);
    }
    else if(e<temp)
    {
        f(s, temp, cnt+abs(e-temp), num+1);
    }
}
int main()
{
    scanf("%d", &N);
    scanf("%d %d", &s, &e);
    scanf("%d", &M);
    for(int i=0; i<M; i++) scanf("%d", arr+i);
    f(s,e, 0, 0);

    cout<<ans;
}*/

//10-8
/*#include<stdio.h>
#include<iostream>
#include<queue>
#include<stack>
using namespace std;
int n,L,a[50][50],s[1000000],end1=1,cnt=0;
void push(int k)
{
    s[end1]=k;
    end1++;
}
void pop()
{
    s[end1-1]=0;
    end1--;
}
bool istr()
{
    int c=1,d=end1-1;
    for(int i=1;i<end1;i++)
    {
        if(s[c]!=s[d])
        {
            return false;
        }
        c++;
        d--;
    }
    return true;
}
void dfs(int x,int y,int time)
{
    if(time==L)
    {
        if(istr())
        {
            cnt++;
        }
        return ;
    }
    else
    {
        int dx[8]= {1,0,-1,0,1,1,-1,-1},dy[8]= {0,1,0,-1,1,-1,1,-1};
        for(int i=0; i<8; i++)
        {
            if(((x+dx[i])>=0)&&((x+dx[i])<n)&&((y+dy[i])>=0)&&((y+dy[i])<n))
            {
                push(a[x+dx[i]][y+dy[i]]);
                dfs(x+dx[i],y+dy[i],time+1);
                pop();
            }
        }
    }
    return ;
}
int main()
{
   scanf("%d %d",&n,&L);
   for(int i=0;i<n;i++)
   {
       for(int j=0;j<n;j++)
       {
           scanf("%d",&a[i][j]);
       }
   }
   for(int i=0;i<n;i++)
   {
       for(int j=0;j<n;j++)
       {
           push(a[i][j]);
           dfs(i,j,1);
           pop();
       }
   }
   printf("%d",cnt);
   return 0;
}*/
/*#include<stdio.h>
#include<iostream>
using namespace std;
int dp[30][30][30][30][30],n,L,a[30][30],dx[8]= {1,0,-1,0,1,1,-1,-1},dy[8]= {0,1,0,-1,1,-1,1,-1},ans=0;
int main()
{
    scanf("%d %d",&n,&L);
   for(int i=0;i<n;i++)
   {
       for(int j=0;j<n;j++)
       {
           scanf("%d",&a[i][j]);
           dp[i][j][i][j][1]=1;
       }
   }
   for(int i=0;i<n;i++)
   {
       for(int j=0;j<n;j++)
       {
           for(int k=0;k<8;k++)
           {
               if((i+dx[k]>=0)&&(i+dx[k]<n)&&(j+dy[k]>=0)&&(j+dy[k]<n)&&(a[i][j]==a[i+dx[k]][j+dy[k]]))
               {
                   dp[i][j][i+dx[k]][j+dy[k]][2]=1;
               }
           }
       }
   }
   for(int x=3;x<=L;x++)
   {
       for(int i=0;i<n;i++)
       {
           for(int j=0;j<n;j++)
           {
               for(int k=0;k<n;k++)
               {
                   for(int l=0;l<n;l++)
                   {
                       if(a[i][j]==a[k][l])
                       {
                           for(int p=0;p<8;p++)
                           {
                               for(int q=0;q<8;q++)
                               {
                                   if((i+dx[p]>=0)&&(i+dx[p]<n)&&(j+dy[p]>=0)&&(j+dy[p]<n)&&(k+dx[q]>=0)&&(k+dx[q]<n)&&(l+dy[q]>=0)&&(l+dy[q]<n))
                                   {
                                       dp[i][j][k][l][x]+=dp[i+dx[p]][j+dy[p]][k+dx[q]][l+dy[q]][x-2];
                                   }
                               }
                           }
                       }
                   }
               }
           }
       }
   }
   for(int i=0;i<n;i++)
       {
           for(int j=0;j<n;j++)
           {
               for(int k=0;k<n;k++)
               {
                   for(int l=0;l<n;l++)
                   {
                       ans+=dp[i][j][k][l][L];
                   }
               }
           }
       }
       printf("%d",ans);
       return 0;
}*/

//10-9
/*#include <stdio.h>
#include<iostream>
#include <queue>
using namespace std;
struct pos{int x,y;};
queue <pos> q;
int n,arr[501][501],ch[501][501],num,land;
int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};
void reset()
{
    for(int i=1; i<=n ; i++)
        for(int j=1 ; j<=n ; j++)
            ch[i][j]=0;
}
bool okay(int x,int y)
{
    if(x>0 && x<=n && y>0 && y<=n && ch[x][y]==0)
        return true;
    return false;
}
void bfs(int d)
{
    int x=q.front().x;
    int y=q.front().y;
    q.pop();

    for(int i=0 ; i<4 ; i++)
    {
        if(okay(x+dx[i],y+dy[i]) && arr[x][y]+d>=arr[x+dx[i]][y+dy[i]] && arr[x][y]-d<=arr[x+dx[i]][y+dy[i]])
        {
            ch[x+dx[i]][y+dy[i]]=1;
            num++;
            q.push({x+dx[i],y+dy[i]});
        }
    }
}

bool go(int i)
{
        reset();
        land=0;
        for(int x=1 ; x<=n ; x++)
        {
            for(int y=1 ; y<=n ; y++)
            {
                num=1;
                if(ch[x][y]==0)
                {
                    q.push({x,y});
                    ch[x][y]=1;
                    while(!q.empty())
                        bfs(i);
                }
                if(land<num)
                    land=num;
            }
        }

        //printf("i:%d  %d\n",i,land);
        if(land>=(n*n+1)/2)
        {
            return true;
        }
        else
        {
            return false;
        }
}
void search1(int low,int high)
{
    //printf("%d %d\n",low,high);
    if(low==high)
    {
        printf("%d",low);
        exit(0);
    }
    else
    {
        int mid=(low+high)/2;
        if(go(mid))
        {
            search1(low,mid);
        }
        else
        {
            search1(mid+1,high);
        }
    }
}
int main()
{
    int maxheight=0;
    scanf("%d",&n);
    for(int i=1 ; i<=n ; i++)
    {
        for(int j=1 ; j<=n ; j++)
        {
            scanf("%d",&arr[i][j]);
            if(maxheight<arr[i][j])
            {
                maxheight=arr[i][j];
            }
        }
    }
   search1(0,maxheight);
   return 0;
}*/
/*
//10-10
#include <stdio.h>
#include <algorithm>
using namespace std;
int comp[101][101],arr[101][101];
int temp[101],cnt,ch[101],n;
void dfs(int x)
{
    ch[x]=1;
    for(int i=1 ; i<=100 ; i++)
    {
        if(ch[i]==0 && comp[x][i]==1)
        {
            temp[++cnt]=i;
            dfs(i);
        }
    }
}
void reset()
{
    for(int i=1 ; i<=100 ; i++)
    {
        ch[i]=0;
    }
}
bool cmp(int x, int y)
{
    if(x>y)
        return true;
    return false;
}
int main()
{
    scanf("%d",&n);
    int a,b,c;
    for(int i=1 ; i<=n ; i++)
    {
        scanf("%d %d %d",&a,&b,&c);
        arr[a][b]=c;
    }
    for(int l=1 ; l<=100 ; l++)
    {
        for(int i=1 ; i<=100 ; i++)
        {
            for(int j=1 ; j<=100 ; j++)
            {
                if(arr[i][j]>50 && comp[i][j]==0)
                {
                    comp[i][j]=1;
                    for(int k=1 ; k<=100 ; k++)
                    {
                        arr[i][k]+=arr[j][k];
                    }
                }
            }
        }
    }
    for(int i=1 ; i<=100  ; i++)
    {
        reset();
        dfs(i);
        sort(temp+1,temp+cnt+1,cmp);
        while(cnt>0)
        {
            printf("%d %d\n",i,temp[cnt]);
            temp[cnt--]=0;
        }
    }
    return 0;
*/
//10-11
/*#include<stdio.h>
#include<iostream>
#include<queue>
#include<utility>
using namespace std;
queue <pair <int,int> >  q;
int n,m,a[105][105],b[1000005][2],cnt=0,visit[105][105];
void reset()
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
          visit[i][j]=0;
        }
    }
}
int main()
{
  scanf("%d %d",&n,&m);
  for(int i=0;i<n;i++)
  {
      for(int j=0;j<m;j++)
      {
          scanf("%d",&a[i][j]);
      }
  }
  for(int i=n-1;i>=0;i--)
  {
      for(int j=m-1;j>=0;j--)
      {
          if(a[i][j]==1)
          {
               b[cnt][0]=i;
               b[cnt][1]=j;
               cnt++;
          }
      }
  }
  int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1},ansx=0,ansy=0,ans=1000000;
  for(int i=0;i<cnt;i++)
  {
      a[b[i][0]][b[i][1]]=0;
      reset();
      visit[n-1][0]=1;
      q.push({n-1,0});
      while(!q.empty())
      {
          int x,y;
          x=(q.front()).first;
          y=(q.front()).second;
          q.pop();
          for(int k=0;k<4;k++)
          {
              if((x+dx[k]>=0)&&(x+dx[k]<n)&&(y+dy[k]>=0)&&(y+dy[k]<m)&&(a[x+dx[k]][y+dy[k]]==0)&&(visit[x+dx[k]][y+dy[k]]==0))
              {
                   visit[x+dx[k]][y+dy[k]]=visit[x][y]+1;
                   if(visit[x+dx[k]][y+dy[k]]>ans)
                  {
                      while(!q.empty())
                      {
                          q.pop();
                      }
                  }
                  else
                  {
                      q.push({x+dx[k],y+dy[k]});
                  }
              }
          }
      }
      if(visit[0][m-1]==0)
      {
          a[b[i][0]][b[i][1]]=1;
          continue;
      }
      if(ans>=visit[0][m-1])
      {
          ans=visit[0][m-1];
          ansx=b[i][0];
          ansy=b[i][1];
      }
      a[b[i][0]][b[i][1]]=1;
  }
      reset();
      visit[n-1][0]=1;
      q.push({n-1,0});
      while(!q.empty())
      {
          int x,y;
          x=(q.front()).first;
          y=(q.front()).second;
          q.pop();
          for(int k=0;k<4;k++)
          {
              if((x+dx[k]>=0)&&(x+dx[k]<n)&&(y+dy[k]>=0)&&(y+dy[k]<m)&&(a[x+dx[k]][y+dy[k]]==0)&&(visit[x+dx[k]][y+dy[k]]==0))
              {
                  visit[x+dx[k]][y+dy[k]]=visit[x][y]+1;
                  if(visit[x+dx[k]][y+dy[k]]>ans)
                  {
                      while(!q.empty())
                      {
                          q.pop();
                      }
                  }
                  else
                  {
                      q.push({x+dx[k],y+dy[k]});
                  }
              }
          }
      }

      if(visit[0][m-1]==0)
      {
          printf("%d %d\n%d",ansx+1,ansy+1,ans);
          return 0;
      }
      if(ans>=visit[0][m-1])
      {
          ans=visit[0][m-1];
          ansx=0;
          ansy=0;
          printf("%d %d\n%d",0,0,ans);
          return 0;
      }
      else
      {
          printf("%d %d\n%d",ansx+1,ansy+1,ans);
          return 0;
      }
}*/
//10-12
/*
#include<stdio.h>
#include<iostream>
#include<queue>
#include<stack>
#include<memory.h>
using namespace std;
int dp[1030][1030][15][5],k,N,X,Y;
char C;
int dfs(int x,int y,int level)
{
    if(level==1)
    {
        int min1=10000;
        for(int i=0;i<4;i++)
        {
            for(int j=0;j<4;j++)
            {
                for(int k=0;k<4;k++)
                {

                       if((i!=j)&&(j!=k)&&(k!=i)&&(dp[x][y][0][i]+dp[x+1][y][0][j]+dp[x][y+1][0][k]+dp[x+1][y+1][0][6-k-i-j]<min1))
                       {
                           min1=dp[x][y][0][i]+dp[x+1][y][0][j]+dp[x][y+1][0][k]+dp[x+1][y+1][0][6-k-i-j];
                       }
                }
            }
        }
        dp[x][y][1][3]=min1;
        for(int i=0;i<3;i++)
        {
            dp[x][y][1][i]=dp[x][y][0][i]+dp[x+1][y][0][i]+dp[x][y+1][0][i]+dp[x+1][y+1][0][i];
        }
        return dp[x][y][1][3];
    }
    else
    {
        int min1=10000;
        dfs(x,y,level-1);
        dfs(x+(1<<(level-1)),y,level-1);
        dfs(x,y+(1<<(level-1)),level-1);
        dfs(x+(1<<(level-1)),y+(1<<(level-1)),level-1);
        for(int i=0;i<4;i++)
        {
            for(int j=0;j<4;j++)
            {
                for(int k=0;k<4;k++)
                {
                    if((i!=j)&&(j!=k)&&(k!=i)&&(dp[x][y][level-1][i]+dp[x+(1<<(level-1))][y][level-1][j]+dp[x][y+(1<<(level-1))][level-1][k]+dp[x+(1<<(level-1))][y+(1<<(level-1))][level-1][6-k-i-j]<min1))
                       {
                           min1=dp[x][y][level-1][i]+dp[x+(1<<(level-1))][y][level-1][j]+dp[x][y+(1<<(level-1))][level-1][k]+dp[x+(1<<(level-1))][y+(1<<(level-1))][level-1][6-k-i-j];
                       }
                }
            }
        }
        dp[x][y][level][3]=min1;
        for(int i=0;i<3;i++)
        {
            dp[x][y][level][i]=dp[x][y][level-1][i]+dp[x+(1<<(level-1))][y][level-1][i]+dp[x][y+(1<<(level-1))][level-1][i]+dp[x+(1<<(level-1))][y+(1<<(level-1))][level-1][i];
        }
        return min1;
    }
}
int main()
{
   scanf("%d %d",&k,&N);
   for(int i=0;i<N;i++)
   {
       scanf("%d %d %c",&Y,&X,&C);
       if(C=='K')
       {
          dp[X-1][Y-1][0][0]=0;
          dp[X-1][Y-1][0][1]=1;
          dp[X-1][Y-1][0][2]=1;
          dp[X-1][Y-1][0][3]=0;
       }
         if(C=='O')
       {
          dp[X-1][Y-1][0][0]=1;
          dp[X-1][Y-1][0][1]=0;
          dp[X-1][Y-1][0][2]=1;
          dp[X-1][Y-1][0][3]=0;
       }
         if(C=='I')
       {
          dp[X-1][Y-1][0][0]=1;
          dp[X-1][Y-1][0][1]=1;
          dp[X-1][Y-1][0][2]=0;
          dp[X-1][Y-1][0][3]=0;
       }
   }
   printf("%d", dfs(0,0,k));
   return 0;
}
*/
//10-13
/*#include <iostream>

using namespace std;
int N, M;
int arr[30][30];
int dp[30][30][910];
int visit[30][30][910];

int dx[]={1, -1, 0, 0}, dy[]={0, 0, 1, -1};
bool safe(int x, int y)
{
    return (0<=x && x<N && 0<=y && y<M);
}

int main()
{
    cin>>N>>M;
    for(int i=0; i<N; i++)
        for(int j=0; j<M; j++)
        {
            cin>>arr[i][j];
            for(int k=0; k<N*M; k++) dp[i][j][k]=2e9;
        }
    visit[0][0][0]=1;
    dp[0][0][0]=0;

    for(int k=1; k<N*M; k++) // k=걸린 경우의 수, coin * (2*(i+j)-1)
    {
        for(int i=0; i<N; i++)
        {
            for(int j=0; j<M; j++) // dp[i][j][k]를 만들 것이다.
            {
                int ret=2e9;
                for(int l=0; l<4; l++)
                {
                    int px=i+dx[l], py=j+dy[l];
                    int pk=k-1;
                    if(!safe(px, py)) continue;
                    if(!visit[px][py][pk]) continue;

                    ret=min(ret, dp[px][py][pk]+arr[i][j]*(2*pk+1));
                }
                dp[i][j][k]=ret;
                if(dp[i][j][k]!=2e9) visit[i][j][k]=1;
            }
        }
    }

    int ans=2e9;
    for(int i=0; i<N*M; i++) ans=min(ans, dp[N-1][M-1][i]);

    cout<<ans;

    return 0;
}*/
//10-14
/*
#include<stdio.h>
#include<iostream>
#include<vector>
#include<queue>
#define INF 2000000000
using namespace std;
struct node{long long int idx;long long int money;};
struct node2{long long int witch;long long int length;};
bool operator<(node A,node B){return A.money<B.money;}
vector<vector<node2>> adj;
vector<long long int> length;
priority_queue <node> pq;
long long int v,e,S,D,T;
int main()
{
    scanf("%lld %lld",&v,&e);
    scanf("%lld %lld %lld",&S,&D,&T);
    length.resize(e+5,1);adj.resize(e+5);
    long long int st=S,max1=0;
    for(long long int i=0;i<e;i++)
    {
        long long int a,b,c;
        scanf("%lld %lld %lld",&a,&b,&c);
        adj[a].push_back({b,c-1});
        adj[b].push_back({a,c-1});
        if(max1<c)
        {
            max1=c;
        }
    }
    length[st]=max1;
    pq.push({st,max1+1});
    while(!pq.empty())
    {
        long long int idxf=pq.top().idx;
        long long int moneyf=pq.top().money;
        pq.pop();
        if(length[idxf]>=moneyf) continue;
        length[idxf]=moneyf;
        for(auto i: adj[idxf])
        {
            pq.push({i.witch,min((i.length),moneyf)});
        }
    }
    /*for(int i=1; i<=v; i++)
    {
        cout << length[i] << '\n';
    }*/
    /*if(S==D)
    {
        printf("1");
    }
    else
    {
        printf("%lld",(long long int)((T+length[D]-1)/length[D]));
    }
}

*/
#include<stdio.h>
#include<iostream>
#include<map>
#include<algorithm>
using namespace std;
map < int , int > s;
int n,a[105],b[105];
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        b[i]=a[i];
    }
    sort(b,b+n);
    int cnt=1,last=b[n-1];
    for(int i=n-1;i>=0;i--)
    {
        if(last==b[i])
        {
            s[b[i]]=cnt;
        }
        else
        {
            last=b[i];
            s[b[i]]=n-i;
            cnt=n-i;
        }
    }
    for(int i=0;i<n;i++)
    {
        printf("%d %d\n",a[i],s[a[i]]);
    }
    return 0;
}

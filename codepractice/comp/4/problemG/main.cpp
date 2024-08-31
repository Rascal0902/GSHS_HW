/*#include<stdio.h>
int n,m,a[7];
long long int s=0;
int dfs(int time)
{
    if(time>m)
    {
        return 1;
    }
    if(time<=m)
    {
        int i=0,time2=0;
        for(i=1;i<=n;i++)
        {
            //printf("%d ",a[i]);
            if(a[i]==2)
            {
                time2++;
            }
            else
            {
                break;
            }
        }
        //printf("\n\n\n");
        if(time2==n)
        {
            s++;
            s=s%1000000007;
            return 1;
        }
        else
        {

        }

    }
    if(time<m)
    {
        int amin=100,bmin=100,cmin=100,i;
        i=0;
        for(i=1;i<=n;i++)
        {
            if(a[i]==0)
            {
                if(amin>i)
                {
                    amin=i;
                }
            }
             if(a[i]==1)
            {
                if(bmin>i)
                {
                    bmin=i;
                }
            }
             if(a[i]==2)
            {
                if(cmin>i)
                {
                    cmin=i;
                }
            }
        }
        if((amin>bmin)&&(bmin>cmin))
        {
            a[cmin]=0;
            dfs(time+1);
            a[cmin]=2;
            a[cmin]=1;
            dfs(time+1);
            a[cmin]=2;
            a[bmin]=0;
            dfs(time+1);
            a[bmin]=1;
        }
        else if((amin>cmin)&&(cmin>bmin))
        {
            a[bmin]=0;
            dfs(time+1);
            a[bmin]=1;
            a[bmin]=2;
            dfs(time+1);
            a[bmin]=1;
            a[cmin]=0;
            dfs(time+1);
            a[cmin]=2;
        }
        else if((bmin>amin)&&(amin>cmin))
        {
             a[cmin]=1;
            dfs(time+1);
            a[cmin]=2;
            a[cmin]=0;
            dfs(time+1);
            a[cmin]=2;
            a[amin]=1;
            dfs(time+1);
            a[amin]=0;
        }
         else if((bmin>cmin)&&(cmin>amin))
        {
             a[amin]=1;
            dfs(time+1);
            a[amin]=0;
            a[amin]=2;
            dfs(time+1);
            a[amin]=0;
            a[cmin]=1;
            dfs(time+1);
            a[cmin]=2;
        }
         else if((cmin>amin)&&(amin>bmin))
        {
             a[bmin]=2;
            dfs(time+1);
            a[bmin]=1;
            a[bmin]=0;
            dfs(time+1);
            a[bmin]=1;
            a[amin]=2;
            dfs(time+1);
            a[amin]=0;
        }
         else if((cmin>bmin)&&(bmin>amin))
        {
             a[amin]=2;
            dfs(time+1);
            a[amin]=0;
            a[amin]=1;
            dfs(time+1);
            a[amin]=0;
            a[bmin]=2;
            dfs(time+1);
            a[bmin]=1;
        }
        else if((amin==100)&&(bmin==100))
        {
                a[cmin]=1;
                dfs(time+1);
                a[cmin]=2;
                a[cmin]=0;
                dfs(time+1);
                a[cmin]=2;
        }
        else if((bmin==100)&&(cmin==100))
        {
                a[amin]=1;
                dfs(time+1);
                a[amin]=0;
                a[amin]=2;
                dfs(time+1);
                a[amin]=0;
        }
          else if((amin==100)&&(cmin==100))
        {
                a[bmin]=0;
                dfs(time+1);
                a[bmin]=1;
                a[bmin]=2;
                dfs(time+1);
                a[bmin]=1;
        }
        else
        {

        }

    }
    return 1;
}
int main()
{
   scanf("%d %d",&n,&m);
    int i=0;
    for(i=1;i<=n;i++)
    {
        a[i]=0;
    }
    dfs(0);
    printf("%lld",s);
    return 0;
}*/
/*#include<stdio.h>
#include<memory.h>
long long int n,m,dp[300][1000],a[7],p3[7];//1000은 남는 시간
long long int dfs(long long int Hanoi,long long int time)
{
    if(time>m)
    {
        return 0;
    }
    if(time<=m)
    {
        if(dp[Hanoi][m-time]!=-1)
        {
            return dp[Hanoi][m-time]%1000000007;
        }
        else
        {
            long long int sum=0,amin=100,bmin=100,cmin=100,i=0;
            for(i=1; i<=n; i++)
            {
                a[i]=Hanoi%3;
                Hanoi=Hanoi/3;
            }
            i=0;
            for(i=1; i<=n; i++)
            {
                if(a[i]==0)
                {
                    if(amin>i)
                    {
                        amin=i;
                    }
                }
                if(a[i]==1)
                {
                    if(bmin>i)
                    {
                        bmin=i;
                    }
                }
                if(a[i]==2)
                {
                    if(cmin>i)
                    {
                        cmin=i;
                    }
                }
            }
            if((amin>bmin)&&(bmin>cmin))
            {
                Hanoi-=p3[cmin-1]*2;
                sum+=dfs(Hanoi,time+1);
                Hanoi+=p3[cmin-1]*2;
                Hanoi-=p3[cmin-1]*2;
                Hanoi+=p3[bmin-1];
                sum+=dfs(Hanoi,time+1);
                Hanoi+=p3[cmin-1]*2;
                Hanoi-=p3[bmin-1];
                Hanoi-=p3[bmin-1];
                sum+=dfs(Hanoi,time+1);
                Hanoi+=p3[bmin-1];

            }
            else if((amin>cmin)&&(cmin>bmin))
            {
                Hanoi-=p3[bmin-1];
                sum+=dfs(Hanoi,time+1);
                Hanoi+=p3[bmin-1];
                Hanoi-=p3[bmin-1];
                Hanoi+=p3[cmin-1]*2;
                sum+=dfs(Hanoi,time+1);
                Hanoi+=p3[bmin-1];
                Hanoi-=p3[cmin-1]*2;
                Hanoi-=p3[cmin-1]*2;
                sum+=dfs(Hanoi,time+1);
                Hanoi+=p3[cmin-1]*2;
            }
            else if((bmin>amin)&&(amin>cmin))
            {
                Hanoi-=p3[cmin-1]*2;
                Hanoi+=p3[bmin-1];
                sum+=dfs(Hanoi,time+1);
                Hanoi+=p3[cmin-1]*2;
                Hanoi-=p3[bmin-1];
                Hanoi-=p3[cmin-1]*2;
                sum+=dfs(Hanoi,time+1);
                Hanoi+=p3[cmin-1]*2;
                Hanoi+=p3[bmin-1];
                sum+=dfs(Hanoi,time+1);
                Hanoi-=p3[bmin-1];
            }
            else if((bmin>cmin)&&(cmin>amin))
            {
                Hanoi+=p3[bmin-1];
                sum+=dfs(Hanoi,time+1);
                Hanoi-=p3[bmin-1];
                Hanoi+=p3[cmin-1]*2;
                sum+=dfs(Hanoi,time+1);
                Hanoi-=p3[cmin-1]*2;
                Hanoi-=p3[cmin-1]*2;
                Hanoi+=p3[bmin-1];
                sum+=dfs(Hanoi,time+1);
                Hanoi+=p3[cmin-1]*2;
                Hanoi-=p3[bmin-1];
            }
            else if((cmin>amin)&&(amin>bmin))
            {
                Hanoi-=p3[bmin-1];
                sum+=dfs(Hanoi,time+1);
                Hanoi+=p3[bmin-1];
                Hanoi-=p3[bmin-1];
                Hanoi+=p3[cmin-1]*2;
                sum+=dfs(Hanoi,time+1);
                Hanoi+=p3[bmin-1];
                Hanoi-=p3[cmin-1]*2;
                Hanoi+=p3[cmin-1]*2;
                sum+=dfs(Hanoi,time+1);
                Hanoi-=p3[cmin-1]*2;
            }
            else if((cmin>bmin)&&(bmin>amin))
            {
                Hanoi+=p3[cmin-1]*2;
                sum+=dfs(Hanoi,time+1);
                Hanoi-=p3[cmin-1]*2;
                Hanoi+=p3[bmin-1];
                sum+=dfs(Hanoi,time+1);
                Hanoi-=p3[bmin-1];
                Hanoi-=p3[bmin-1];
                Hanoi+=p3[cmin-1]*2;
                sum+=dfs(Hanoi,time+1);
                Hanoi+=p3[bmin-1];
                Hanoi-=p3[cmin-1]*2;
            }
            else if((amin==100)&&(bmin==100))
            {
                sum++;
            }
            else if((bmin==100)&&(cmin==100))
            {
                Hanoi+=2;
                sum+=dfs(Hanoi,time+1);
                Hanoi-=2;
                Hanoi+=1;
                sum+=dfs(Hanoi,time+1);
                Hanoi-=1;
            }
            else if((amin==100)&&(cmin==100))
            {
                Hanoi-=1;
                sum+=dfs(Hanoi,time+1);
                Hanoi+=1;
                Hanoi-=1;
                Hanoi+=2;
                sum+=dfs(Hanoi,time+1);
                Hanoi+=1;
                Hanoi-=2;
            }
            else
            {

            }
            dp[Hanoi][m-time]=sum%1000000007;
            return sum%1000000007;
        }

    }
}

int main()
{
    long long int i;
    p3[0]=1;
    scanf("%lld %lld",&n,&m);
    for(i=1;i<=n;i++)
    {
        p3[i]=p3[i-1]*3;
    }
    memset(dp,-1,sizeof(dp));
    printf("%lld",dfs(0,0));
    return 0;
}*/
/*#include <iostream>
#include <cmath>
#define MOD 1000000007
using namespace std;

int dp[243][1010];
int v[243][1010];
int N, M;
int dfs(int p, int m)
{
    if(v[p][m]) return dp[p][m];
    if(p==0) return 1;
    if(m==0) return 0;
    v[p][m]=1;
    int t=p;
    int a[6]={};
    int top[3]={-1, -1, -1};

    for(int i=N; i>=1; i--)
    {
        a[i]=t%3;
        t/=3;
        top[a[i]]=i;
    }
    int r=0;
    for(int i=0; i<3; i++)
        for(int j=0; j<3; j++)
        {
            if(i!=j && top[i]!=-1 && (top[j]>top[i] || top[j]==-1))
            {
                a[top[i]]=j;
                int tmp=0;
                for(int i=1; i<=N; i++) tmp=3*tmp+a[i];
                r=(r+dfs(tmp, m-1))%MOD;
                a[top[i]]=i;
            }
        }

    return dp[p][m]=r;
}

int main()
{
    int v;
    cin>>N>>M;
    v=pow(3.0 ,N)-1;
    cout<<dfs(v, M);
    return 0;
}*/
#include<stdio.h>
#include<string.h>
long long int n,m,a[30],b[30],c[30],enda=1,endb=1,endc=1;
char as[30],bs[30],cs[30];
void pusha(long long int k)
{
    a[enda]=k;
    enda++;
}
void popa()
{
    a[enda-1]=0;
    enda--;
}
void pushb(long long int k)
{
    b[endb]=k;
    endb++;
}
void popb()
{
    b[endb-1]=0;
    endb--;
}
void pushc(long long int k)
{
    c[endc]=k;
    endc++;
}
void popc()
{
    c[endc-1]=0;
    endc--;
}
long long int dfs(long long int time)
{
    if(time>m)
    {
        return -1;
    }
    else
    {
        if((enda==n)||(endc==n))
        {
            return time;
        }
        else
        {
            long long int t3[3],i=0,j=0;
            t3[0]=a[enda-1];
            t3[1]=b[endb-1];
            t3[2]=c[endc-1];
            for(i=0; i<=2; i++)
            {
                for(j=0; j<=2; j++)
                {
                    if((t3[i]>t3[j])&&(i!=j))
                    {
                        if((i==0)&&(j==1))
                        {
                            popa();
                            pushb(t3[0]);
                            dfs(time+1);
                            popb();
                            pusha(t3[0]);
                        }
                        if((i==0)&&(j==2))
                        {
                            popa();
                            pushc(t3[0]);
                            dfs(time+1);
                            popc();
                            pusha(t3[0]);
                        }
                        if((i==1)&&(j==2))
                        {
                            popb();
                            pushc(t3[0]);
                            dfs(time+1);
                            popc();
                            pushb(t3[0]);
                        }
                        if((i==1)&&(j==0))
                        {
                            popb();
                            pusha(t3[0]);
                            dfs(time+1);
                            popa();
                            pushb(t3[0]);
                        }
                        if((i==2)&&(j==0))
                        {
                            popc();
                            pusha(t3[0]);
                            dfs(time+1);
                            popa();
                            pushc(t3[0]);
                        }
                        if((i==2)&&(j==1))
                        {
                            popc();
                            pushb(t3[0]);
                            dfs(time+1);
                            popb();
                            pushc(t3[0]);
                        }
                    }
                }
            }
        }
    }
}
int main()
{
    long long int a1,b1,c1,i=0,j=0,t=0;
    scanf("%lld %lld",&n,&m);
    scanf("%lld",&a1);
    a[0]=0;
    b[0]=0;
    c[0]=0;
    for(j=0; j<a1; j++)
    {
        scanf(" %lld",&t);
        pusha(t);
    }
    scanf("%lld",&b1);
    j=0;
    for(j=0; j<b1; j++)
    {
        scanf(" %lld",&t);
        pushb(t);
    }
    scanf("%lld",&c1);
    j=0;
    for(j=0; j<c1; j++)
    {
        scanf(" %lld",&t);
        pushc(t);
    }
   printf("%lld",dfs(0));
   return 1;
}

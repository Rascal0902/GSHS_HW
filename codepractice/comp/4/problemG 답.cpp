/*#include <iostream>

#include <cmath>

#define MOD 1000000007

using namespace std;

 

int dp[243][1010];

int visit[243][1010];

int N, M;

 

 

int f(int p, int m)

{

    if(visit[p][m]) return dp[p][m];

    if(p==0) return 1;

    if(m==0) return 0;

    visit[p][m]=1;

 

    int t=p;

    int a[6]={};

    int top[3]={-1, -1, -1};

 

    for(int i=N; i>=1; i--)

    {

        a[i]=t%3; t/=3;

        top[a[i]]=i;

    }

    int ret=0;

    for(int i=0; i<3; i++)

        for(int j=0; j<3; j++)

        {

            if(i!=j && top[i]!=-1 && (top[j]>top[i] || top[j]==-1))

            {

                a[top[i]]=j;

                int tmp=0;

                for(int i=1; i<=N; i++) tmp=3*tmp+a[i];

                ret=(ret+f(tmp, m-1))%MOD;

                a[top[i]]=i;

            }

        }

 

    return dp[p][m]=ret;

}

 

int main()

{

    int v;

    cin>>N>>M;

    v=pow(3.0 ,N)-1;

 

    cout<<f(v, M);

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

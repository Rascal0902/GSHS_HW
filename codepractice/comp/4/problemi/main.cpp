#include<stdio.h>
long long int n,m,p3[20],minx=10000000000000,s=0,e=0,q[14348910];
int T[14348910];
void push(long long int k)
{
    q[e]=k;
    e++;
}
void pop()
{
    q[s]=0;
    s++;
}
int main()
{
    long long int amin=0,bmin=0,cmin=0,i=0,j=0,t=0;
    int Hanoist=0,Hanoi;
    scanf("%lld %lld",&n,&m);
    p3[0]=1;
    for(j=1;j<=n;j++)
    {
        p3[j]=p3[j-1]*3;
    }
    j=0;
    scanf("%lld",&amin);
    for(j=0; j<amin; j++)
    {
        scanf(" %lld",&t);
    }
    scanf("%lld",&bmin);
    j=0;
    for(j=0; j<bmin; j++)
    {
        scanf(" %lld",&t);
        Hanoist+=p3[t-1];
    }
    scanf("%lld",&cmin);
    j=0;
    for(j=0; j<cmin; j++)
    {
        scanf(" %lld",&t);
        Hanoist+=p3[t-1]*2;
    }
    push(Hanoist);
    T[Hanoist]=0;
    long long int time=-1;
    while(1)
    {
        Hanoi=q[s];
        if(s==e)
        {
            break;
        }
         if((q[s]==p3[n]-1)||(q[s]==0))
        {
            time=T[q[s]];
            break;
        }
        else
        {
            long long int top[3]= {-1, -1, -1},a[20],i=0,j=0,k=0;
            i=1;
            a[0]=0;
            for(i=1; i<=n; i++)
            {
                a[i]=q[s]%3;
                q[s]/=3;
            }
            i=n;
            for(i=n;i>=1;i--)
            {
                if(a[i]==0)
                {
                    top[0]=i;
                    break;
                }
            }
            i=n;
             for(i=n;i>=1;i--)
            {
                if(a[i]==1)
                {
                    top[1]=i;
                    break;
                }
            }
            i=n;
             for(i=n;i>=1;i--)
            {
                if(a[i]==2)
                {
                    top[2]=i;
                    break;
                }
            }
             i=0;
            for(i=0;i<=2;i++)
            {
                for(j=0;j<=2;j++)
                {
                    if((top[i]>top[j])&&((i==j+1)||(j==i+1)))
                    {
                        a[top[i]]=j;
                        long long int tmp=0;
                         for(k=1; k<=n; k++)
                         {
                              tmp+=a[k]*p3[k-1];
                         }
                         if(T[tmp]!=0)
                         {
                             a[top[i]]=i;
                         }
                         else
                         {
                             T[tmp]=T[Hanoi]+1;
                             push(tmp);
                             a[top[i]]=i;
                         }
                    }
                }
            }
            pop();
        }
    }
    if(time>m)
    {
        printf("-1");
    }
    else
    {
        printf("%lld",time);
    }
    return 0;
}
/*#include<stdio.h>
#include<string.h>
long long int n,m,a[30],b[30],c[30],enda=1,endb=1,endc=1;
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
int dfs(long long int time)
{
    if(time>m)
    {
        printf("%lld",-1);
        return 0;

    }
    else
    {
        if((enda==n)||(endc==n))
        {
            printf("%lld",time);
            return 0;
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
   dfs(0);
   return 1;
}*/

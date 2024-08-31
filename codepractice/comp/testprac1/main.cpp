//A
/*
#include<iostream>
using namespace std;
int n,C[10010][5];
int f(int a,int p){
int s=0;
if(C[a][p]) return C[a][p];
if(a>n) return 0;
else if(a==n) return 1;
s=(f(a+1,p>1?2:p+1)+f(a+2,p>1?2:p+1))%1000000007;
if(p>=2) s=(s+f(a+3,0))%1000000007;
return C[a][p]=s;
}
int main()
{
  cin>> n;
  cout << f(0,2);
}*/
/*#include<stdio.h>
#include<iostream>
using namespace std;
int n,k;
int  f(int t)
{
    if(t==k)
    {
        return 0;
    }
    if(t==n)
    {
        return 1;
    }
    else if(t>n)
    {
        return 0;
    }
    else
    {
        int sum=0;
        for(int i=1;i<=3;i++)
        {
            sum+=f(t+i);
        }
        return sum;
    }
}
int main()
{
    scanf("%d %d",&n,&k);
    printf("%d",f(0));
    return 0;
}*/
/*#include<stdio.h>
#include<iostream>
int n;
int f(int k)
{
      if(k==n)
      {
          return 1;
      }
      else if(k>n)
      {
          return 0;
      }
      else
      {
          int sum=0;
          for(int i=1;i<=2;i++)
          {
              sum+=f(k+i);
          }
          return sum;
      }
}
int main()
{
    scanf("%d",&n);
    printf("%d",f(0));
    return 0;
}*/
/*#include<stdio.h>
#include<iostream>
long long int n,a[10000],cnt=0;
void f(long long int k,long long int sc)
{
      if(k==n)
      {
          if(cnt<sc)
          {
              cnt=sc;
          }
          return;
      }
      else if(k>n)
      {
          return;
      }
      else
      {
          for(int i=1;i<=2;i++)
          {
              f(k+i,sc+a[k+i]);
          }
          return;
      }
}
int main()
{
    scanf("%lld",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",&a[i]);
    }
    f(0,0);
    printf("%lld",cnt);
    return 0;
}*/
/*#include<stdio.h>
#include<iostream>
using namespace std;
long long int n,k,c[1000005];
int main()
{
    int i;
    scanf("%d %d",&n,&k);
    c[0]=1;
    for(int i=3;i<=n+3;i++)
    {
        if(i!=k+3)
        c[i]=(c[i-1]+c[i-2]+c[i-3])%1000000007;
    }
    printf("%d",c[n+3]);
    return 0;
}*/
/*#include<stdio.h>
#include<iostream>
long long int n,a[10000],cnt=0;
void f(long long int k,long long int sc)
{
      if(k==n)
      {
          if(cnt<sc)
          {
              cnt=sc;
          }
          return;
      }
      else if(k>n)
      {
          return;
      }
      else
      {
          for(int i=1;i<=2;i++)
          {
              f(k+i,sc+a[k+i]);
          }
          return;
      }
}
int main()
{
    scanf("%lld",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",&a[i]);
    }
    f(0,0);
    printf("%lld",cnt);
    return 0;
}*/
/*#include<iostream>
#include<algorithm>
using namespace std;
long long int n,A[10000],c[10000],cnt=0;
int main()
{
    scanf("%lld",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",&A[i]);
    }
    c[n]=A[n];
    c[n+1]= -20000000;
    for(int i=n-1;i>=0;i--)
    {
        c[i]=max(c[i+1],c[i+2])+A[i];
    }
    printf("%lld",c[0]);
    return 0;
}*/

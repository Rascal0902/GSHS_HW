#include<stdio.h>
#include<memory.h>
long long int t, a[41000][4],b[35][35][60],c[35][35][60];
long long int f(long long int n,long long int m,long long int k)
{
    //printf("   %lld %lld %lld\n",n,m,k);
    //printf("%d %d %d\n",n,m,k);
    long long int  i,j;
    if(k>m*n)
    {
        return 9999999999;
    }
    if((n==0)||(m==0))
    {
        return 0;
    }
    if((k==n*m)||(k==0))
    {
        return 0;
    }
    if(b[n][m][k]!=-1)
    {
        return c[n][m][k];
    }
    else
    {
        long long int  case1=100000000000000;
        for(i=1;i<=n-1;i++)
        {
           for(j=0;j<=k;j++)
           {
               long long int  sum=0;
               sum=f(i,m,j)+f(n-i,m,k-j)+m*m;
               if(sum<case1)
               {
                   case1=sum;
               }
           }
        }
         for(i=1;i<=m-1;i++)
        {
           for(j=0;j<=k;j++)
           {
              long long int  sum=0;
               sum=f(n,i,j)+f(n,m-i,k-j)+n*n;
               if(sum<case1)
               {
                   case1=sum;
               }
           }
        }
        b[n][m][k]=1;
        c[n][m][k]=case1;
        return case1;
    }
}
int main()
{
    long long int  i,j;
    scanf("%lld",&t);
    memset(b,-1,sizeof(b));
    for(i=0;i<t;i++)
    {
        scanf("%lld %lld %lld",&a[i][0],&a[i][1],&a[i][2]);
        a[i][3]=f(a[i][0],a[i][1],a[i][2]);
    }
    for(i=0;i<t;i++)
    {
        printf("%lld\n",a[i][3]);
    }
    return 0;
}

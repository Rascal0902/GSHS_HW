#include<stdio.h>
long long int a[1000005],b[1000005],c[1000005];
int main()
{
    long long int n,i;
    scanf("%lld",&n);
    a[0]=0;
    for(i=1;i<n+2;i++)
    {
        a[i]=(2*a[i-1]+1)%1000000007;
    }
    b[0]=0;
    c[0]=0;
    for(i=1;i<=n;i++)
    {
        b[i]=(c[i-1]+2*a[i-1]+1)%1000000007;
        c[i]=(b[i-1]+1+4*a[i-1]+1)%1000000007;
    }
    printf("%lld",c[n]);
    return 0;
}

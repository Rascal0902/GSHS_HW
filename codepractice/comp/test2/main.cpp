#include<stdio.h>
#include<iostream>
using namespace std;
long long int n,sum=0,ans=0,t,a[100000000];
int main()
{
    scanf("%lld",&n);
    a[50000000]++;
    for(int i=0;i<n;i++)
    {
        scanf("%lld",&t);
        sum+=t;
        a[50000000+sum]++;
    }
    for(int i=0;i<100000000;i++)
    {
        ans+=a[i]*(a[i]-1)/2;
    }
    printf("%lld",ans);
    return 0;
}

#include<stdio.h>
long long int cache[10000];
long long int f(int k)
{
    if(cache[k]!=(long long int)0)
    {
        return cache[k];
    }
    else
    {
        cache[k]=(f(k-1)+f(k-2))%1000000007;
        return cache[k];
    }
}
int main()
{
    cache[2]=1;
    cache[1]=1;
    int n;
    scanf("%d",&n);
    printf("%lld",f(n));
    return 0;
}

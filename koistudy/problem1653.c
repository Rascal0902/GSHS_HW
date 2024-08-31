#include<string.h>
#include<stdio.h>
int cache[1000];
long long int f(int k)
{
    if(cache[k]!=-1)
    {
        return cache[k];
    }

    else
    {
        cache[k]=(long long int)(f(k-1)+f(k-2))%100000007;
        return cache[k];
    }
}
int main()
{
    int n,i;

    scanf("%d",&n);
    memset(cache,-1,sizeof(cache));
    cache[1]=1;
    cache[2]=2;
    printf("%lld",f(n));
    return 0;
}

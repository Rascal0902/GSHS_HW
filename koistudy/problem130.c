#include<stdio.h>
long long int cache[100];
long long int f(int k)
{
    if(cache[k]!=(long long int)-1)
    {
        return cache[k];
    }
    else
    {
        cache[k]=f(k-1)+f(k-2);
        return cache[k];
    }
}
int main()
{


    int n,i;
    scanf("%d",&n);
    /*for(i=1;i<=n;i++)
    {
        cache[i]=-1;
    }*/
    memset(cache,-1,sizeof(cache));
    cache[1]=(long long int)1;
    cache[2]=(long long int)1;
    printf("%lld",f(n));
}

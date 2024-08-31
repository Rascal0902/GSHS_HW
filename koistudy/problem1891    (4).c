#include<stdio.h>
long long int f(long long int k)
{
    if(k<10)
    {
        return k;
    }
    else
    {
        long long int s;
        s=(long long int)(k%10+f(k/10));
        return s;
    }
}
int main()
{
    long long int n;
    scanf("%lld",&n);

    printf("%lld",f(n));

    return 0;
}

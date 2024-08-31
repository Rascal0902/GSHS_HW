#include<stdio.h>
int main()
{
   long long int n,k;
    scanf("%lld",&n);
    k=(long long int)n*(n+1)*(n+2)/6;
    printf("%lld",k);
}

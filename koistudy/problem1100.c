#include<stdio.h>
int main()
{

    long long int i, m,n,s=(long long)1;
    scanf("%lld %lld",&n,&m);
    for(i=1;i<=m;i++)
    {
        s=(long long int)s*n;
        s=(long long int)s%10000007;
    }

    printf("%lld",s);


}

#include<stdio.h>
long long int m[2005];
int main()
{
    long long int a,b,c,i,n,q,j;
    scanf("%lld %lld",&n,&q);

    for(i=1;i<=q;i++)
    {
        scanf("%lld %lld %lld",&a,&b,&c);
        for(j=a;j<=b;j++)
        {
            m[j]+=c;
        }
    }
    for(i=1;i<=n;i++)
    {
        printf("%lld ",m[i]);
    }
    return 0;
}

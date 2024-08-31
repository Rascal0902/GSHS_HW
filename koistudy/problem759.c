#include<stdio.h>
int main()
{
    int i;
    long long int  n,a[10],b[10],s=(long long int)0,k;
    scanf("%lld",&n);
    for(i=0;i<=9;i++)
    {
        scanf("%lld",&a[i]);
        b[i]=a[i] % n;
        s+=b[i];

    }

    k=(s*2)%n;

    printf("%lld",k);
    return 0;
}

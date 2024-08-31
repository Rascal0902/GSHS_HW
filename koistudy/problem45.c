#include<stdio.h>
int main()
{
    long long int a,b,c,d;
    double e;
    scanf("%lld %lld %lld",&a,&b,&c);
    d=a+b+c;
    e=d/3.0;
    printf("%lld\n%.1lf",d,e);

}

#include<stdio.h>
int main()
{
    long long int a,b,c,d,e,g,h;
    double f;
    scanf("%lld %lld",&a,&b);
    c=a+b;
    d=a-b;
    e=a*b;
    g=a/b;
    h=a%b;
    f=(double)a/b;
    printf("%lld\n%lld\n%lld\n%lld\n%lld\n%.2lf",c,d,e,g,h,f);


}


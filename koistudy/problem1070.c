#include<stdio.h>
int main()
{
    long long int a,b;
    scanf("%lldx^%lld",&a,&b);
    printf("%lldx^%lld",(long long int)a*b,b-1);
    return 0;
}

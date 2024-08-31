#include<stdio.h>
int main()
{
    int a=0,b=10, c=2, d=5, e=5;

    a+=3;
    b-=a;
    c*=3;
    d/=2;
    e%=2;
    printf("%d%d%d%d%d",a, b, c, d, e);
}

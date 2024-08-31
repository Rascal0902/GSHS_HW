#include<stdio.h>
int main()
{
    long long int n;
    scanf("%lld",&n);
    if(n%(long long int)2==0)
    {
        printf("even");

    }
    else
    {
        printf("odd");
    }
    return 0;
}

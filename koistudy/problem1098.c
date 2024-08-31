#include<stdio.h>

int main()
{
    int n,i;
    long long int s=1;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        s*=i;
    }
    printf("%lld",s);
}

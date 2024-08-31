#include<stdio.h>
int main()
{
    long long int n,i;
    scanf("%lld",&n);
    while(1)
    {
        if(n==1)
        {
            break;
        }
        for(i=2; i<1100000; i++)
        {
             if(n%i==0)
             {
                 printf("%lld ",i);
                 n/=i;
                 break;
             }
             if(i==1000009)
             {
                 printf("%lld",n);
                 return 0;
             }
        }

    }
    return 0;
}


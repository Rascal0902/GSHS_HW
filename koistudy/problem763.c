#include<stdio.h>
int main()
{
    long long int n,i;
    scanf("%lld",&n);
    while(1)
    {
        for(i=(long long int)2;i<=n;i++)
        {
           if(n%i==(long long int)0)
           {
               printf("%lld ",i);
               n=(long long int)n/i;
           }
        }

        //printf("%lld \n",n);
        if(n==(long long int)1)
        {
            break;
        }
    }
   // printf("1");
    return 0;
}

#include<stdio.h>
int main()
{
    int n,i;
    long long int s=1;
    scanf("%d",&n);
    if(n%3==0)
   {
       for(i=1;i<=n/3;i++)
    {
        s=s*2%100000007;
    }
        printf("%lld",s);
    return 0;
   }
   else
   {
       printf("0");
       return 0;
   }
}

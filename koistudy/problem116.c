#include<stdio.h>
int main()
{
    int k,n,i,sum=0;
    scanf("%d %d",&n,&k);
    for(i=1;i<=n;i++)
    {
         if(i%k==0)
         {
             sum+=i;
         }
    }
    printf("%d",sum);
    return 0;
}

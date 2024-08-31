#include<stdio.h>
int main()
{
    int n,i,sum=0;
    scanf("%d",&n);
    if(n%2==0)
    {
        for(i=0;i<=n;i++)
        {
            if(i%2==0)
            {
                sum+=i;
            }
        }
        printf("%d",4*sum+1);
    }
    else
    {
        for(i=0;i<=n;i++)
        {
            if(i%2==1)
            {
                sum+=i;
            }
        }
        printf("%d",4*sum);
    }
   return 0;
}

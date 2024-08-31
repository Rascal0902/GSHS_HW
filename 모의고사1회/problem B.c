#include<stdio.h>
int main()
{
    int n,i,sum=0;
    scanf("%d",&n);
    if((n%4==1)||(n%4==2))
    {
        for(i=1;i<=n;i++)
        {
            if(i%2==0)
            {
                sum+=i;
            }
        }
    }
    else
    {
        for(i=1;i<=n;i++)
        {
            if(i%2==1)
            {
                sum+=i;
            }
        }
    }
    printf("%d",sum);
    return 0;
}

#include<stdio.h>
int main()
{
    int n,i,sum=0,t=0;
    scanf("%d",&n);
    if(n==1)
    {
        printf("0\n0");
    }
    else
    {
        for(i=1;i<n;i++)
    {
        if(n%i==0)
        {
            sum+=i;
            t++;
        }
    } printf("%d\n%d",t,sum);
    }


    return 0;
}

#include<stdio.h>
int n;
int f(int k, int t)
{
    int i;
    if(k>n)
    {
        int sum=0;
        return sum;
    }
    else if(k==n)
    {
        int sum=1;
        return sum;
    }
    else
    {
        int sum=0;
        for(i=1;i<=3;i++)
        {
            if(i==t)
            {
                continue;
            }
            sum+=f(k+i,i);
        }
        return sum;
    }
}
int main()
{
    int sum=0,i;
    scanf("%d",&n);
    for(i=1;i<=3;i++)
    {
        sum+=f(i,i);
    }
    printf("%d",sum);
    return 0;
}

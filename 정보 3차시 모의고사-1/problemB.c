#include<stdio.h>
int f(int k)
{
    int i,t=0;
    for(i=2;i<=k-1;i++)
    {
        if(k%i==0)
        {
            continue;
        }
        else
            {
                t++;
            }
    }
    if(t==k-2)
    {
        return 3;
    }
    else
    {
       return 4;
    }
}

int main()
{
    int n,i,t=0;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        if(f(i)==3)
        {
            t+=i;
        }
    }
    printf("%d",t);
    return 0;
}


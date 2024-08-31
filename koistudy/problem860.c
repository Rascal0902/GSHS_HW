#include<stdio.h>
int f(int k)
{
    int i;
    if(k==2)
    {
        return 1;
    }
    else
    {for(i=2;i<k;i++)
    {
        if(k%i==0)
        {
            return -1;
        }
    }
    return 1;
    }
}
int main()
{
    int n,t=0,i,x;
    scanf("%d",&n);
    for(i=2;i<100000;i++)
    {
        if(f(i)==1)
        {
            t++;
            if(t==n)
            {
                x=i;
                break;

            }

        }
    }
    printf("%d",x);
    return 0;
}

#include<stdio.h>
int n,t=0;
int g(int a)
{
    printf("*");
    a--;
    if(a==0)
    {
        return 1;
    }
    else
    {
        g(a);
    }
}
int f(int k)
{  int i;
    g(k);
    printf("\n");
    if(t==0)
    {if(k==n)
    {
        t=-1;
        f(k-1);
    }
    else
    {
        f(k+1);
    }
    }
    else
    {
        if(k==1)
        {
            return 0;
        }
        else
        {
            f(k-1);
        }
    }

}
int main()
{
    scanf("%d",&n);
    f(1);
    return 0;
}

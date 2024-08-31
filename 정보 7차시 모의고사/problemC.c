#include<stdio.h>
int n;
int g(int t)
{
    printf("*");
    if(t==1)
    {
        return 1;
    }
    else
    {
        g(t-1);
    }
}
int f(int k)
{
    int i;
   g(k);
    printf("\n");
    if(k==n)
    {
        return 1;
    }
    else
        {
            f(k+1);
        }
}
int main()
{
    scanf("%d",&n);
    f(1);
    return 0;
}

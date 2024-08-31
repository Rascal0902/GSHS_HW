#include<stdio.h>
int t=1;
int f(int k)
{
    printf("%d ",t);
    t++;
    if(k==1)
    {
        return 1;
    }
    else
    {
        return f(k-1);
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    f(n);
    return 0;
}

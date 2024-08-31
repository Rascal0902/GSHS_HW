#include<stdio.h>
int n;
int f(int k)
{
    if(k==1)
    {
        return 1;
    }
    else if(k==2)
    {
        return 2;
    }
    else if(k==3)
    {
        return 4;
    }
    else
    {
        int s;
        s=f(k-3)+f(k-2)+f(k-1);
        return s;
    }
}
int main()
{
    scanf("%d",&n);
    printf("%d",f(n));
    return 0;
}

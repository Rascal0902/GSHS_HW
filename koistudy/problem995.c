#include<stdio.h>
int f(int k)
{
    if(k==1)
    {
        return 3;
    }
    else
    {
        int s;
        s=f(k-1)+f(k-1)-1;
        return s;
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    printf("%d",f(n)*f(n));
    return 0;
}

#include<stdio.h>
int f(int k)
{
    if(k==1)
    {
        return 1;
    }
    else
    {
        int s;
        s=k+f(k-1);
        return s;
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    printf("%d",f(n));
    return 0;
}

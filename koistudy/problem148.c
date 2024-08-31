#include<stdio.h>
int f(int k)
{
    printf("*");
    if(k==1)
    {
        return 1;
    }
    else
    {
        f(k-1);
        return 1;
    }
}

int main()
{
    int n,i;
    scanf("%d",&n);
    f(2*n-1);
    return 0;
}


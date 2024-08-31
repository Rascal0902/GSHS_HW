#include<stdio.h>
int ht(int n)
{
    if(n==1)
    {
        return 1;
    }
    else if(n==2)
    {
        return 3;

    }
    else
    {
        return 2*ht(n-2)+3;
    }
}
int main()
{
    int n;
    scanf("%d",&n);

    printf("%d",ht(n));
    return 0;
}

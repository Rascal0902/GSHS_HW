#include<stdio.h>
int t=1;
int f(int k)
{
    if(k<10)
    {
        return t;
    }
    else
    {
        k=k/10;
        t++;
        f(k);

    }
}
int main()
{
    int n;
    scanf("%d",&n);
    printf("%d",f(n));
}




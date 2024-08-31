#include<stdio.h>
int t=1;
int f(int k)
{
    if(k==1)
    {
        return 1;
    }
    else
    {  t++;
        if(k%2==1)
        {
            f(3*k+1);
        }
        else
        {
            f(k/2);
        }
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    f(n);
    printf("%d",t);
    return 0;
}

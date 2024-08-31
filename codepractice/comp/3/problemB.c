#include<stdio.h>
int f(int k)
{
    if(k==0)
    {
        return 1;
    }
    else
    {
        if(k%10!=0)
        {
            printf("%d",k%10);
        }
        f(k/10);

    }
}
int main()
{
   int n;
   scanf("%d",&n);
   f(n);
   return 0;
}

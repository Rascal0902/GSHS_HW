#include<stdio.h>
int n,k;
int f(int a,int b)
{
    if(a<0)
    {
        return 0;
    }
    if(a==0)
    {
        return 1;
    }
    if(a==b)
    {
        return 0;
    }
    else
    {
       int s;
       //printf("f(%d %d)+f(%d %d)+f(%d %d)\n",a-1,b,a-2,b,a-3,b);
       s=f(a-1,b)+f(a-2,b)+f(a-3,b);
       return s;
    }
}
int main()
{
    scanf("%d %d",&n,&k);
    printf("%d",f(n,k));
    return 0;
}

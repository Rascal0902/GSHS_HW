#include<stdio.h>
int f(int x,int y)
{
    if(x==y)
    {
        return 1;
    }
    if(y==0)
    {
         return 1;
    }
    else
    {
        int s;
        s=f(x-1,y-1)+f(x-1,y);
        return s;
    }
}
int main()
{
    int n,r;
    scanf("%d %d",&n,&r);
    printf("%d",f(n,r));
    return 0;
}

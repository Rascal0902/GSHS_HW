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
         s=f(k-1)+f(k-2)+f(k-3);
         return s;
    }

}
int sum(int k)
{
    int s,i;
    s=0;
    for(i=1;i<=k;i++)
    {
        s+=f(i)*f(k+1-i);
    }
    return s;
}
int main()
{
    scanf("%d",&n);
    printf("%d",sum(n));
    return 0;
}

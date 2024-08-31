#include<stdio.h>
int n;
int f(int k,int t)
{
    if((k==1)&&(t==1))
    {
        return 1;
    }
    else if((k==2)&&(t==1))
    {
        return 1;
    }
    else if((k==2)&&(t==2))
    {
        return 1;
    }
    else if((k==1)&&(t!=1))
    {
        return 0;
    }
    else if((k==2)&&(t!=1)&&(t!=2))
    {
        return 0;
    }
    else
    {
        int s;
        s=f(k-1,t-1)+f(k-2,t-1);
        return s;
    }
}
int main()
{
    int i,sum=0;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        sum+=f(n,i)*f(n,i);
    }
   printf("%d",sum);
    return 0;
}

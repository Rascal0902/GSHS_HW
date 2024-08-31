#include<stdio.h>
int n,A[30],max=0;
int f(int k,int t,int a)
{
    if(k>n)
    {
        return 1;
    }
    if(k==n)
    {
        if(max<t)
        {
            max=t;
            //printf("%d\n",max);
        }
        return 1;
    }
    else
    {
        if(a==2)
        {
            f(k+1,t,0);
        }
        else
        {
            f(k+1,t+A[k],a+1);
            f(k+1,t,0);
        }
    }
}
int main()
{
    int i;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&A[i]);
    }
    f(0,0,0);
    printf("%d",max);
    return 0;
}

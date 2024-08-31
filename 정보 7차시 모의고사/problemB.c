#include<stdio.h>
int f(int k,int t)
{
    int n;
    if(k>t)
    {
        n=k;
        k=t;
        t=n;
    }
    if(t%k==0)
    {
        return k;
    }
    else
    {
        f(t-k,k);
    }

}
int main()
{
    int a,b;
    scanf("%d %d",&a,&b);
    printf("%d",f(a,b));
    return 0;
}

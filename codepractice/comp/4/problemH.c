
#include<stdio.h>
long long int a[130],b[130],k;//a[]가 3개 짜리
long long int f(long long int n)
{
    long long int i;
    if(n==0)
    {
        return 0;
    }
    if(b[n]!=0)
    {
        return b[n];
    }
    else
    {
        long long int s=10000000000,tempt=0;
        for(i=n/2;i<n;i++)
        {
            tempt+=2*f(i)+a[n-i];
            if(tempt<s)
            {
                s=tempt;
            }
            tempt=0;
        }
        b[n]=s;
        return b[n];
    }
}
int main()
{
    long long int i;
    scanf("%lld",&k);
    a[0]=0;
    for(i=1;i<=k+2;i++)
    {
        a[i]=a[i-1]*2+1;
        //printf("a[%lld]=%lld\n",i,a[i]);
    }
    printf("%lld",f(k));
    /*for(i=1;i<=k;i++)
    {
        printf("\nb[%lld]=%lld",i,b[i]);
    }*/
    return 0;
}

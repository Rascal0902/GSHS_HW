#include<stdio.h>
long long int a[130],b[130],c[130],k,b2[130],c2[130];
long long int f2(long long int n)
{
    long long int i=0;
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
            tempt+=2*f2(i)+a[n-i];
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
long long int f(long long int k)
{
    if(c[k]!=0)
    {
        return c[k];
    }
    else
    {
        if(k==1)
        {
            c[k]=2;
            return 2;
        }
        else
        {
           long long int i=0,min=1000000000,tempt=0;
           for(i=0;i<k;i++)
           {
               if(k-i>=62)
               {
                   continue;
               }
               tempt+=f(i)+c2[k-i]+2*b[i];
               if(tempt<=min)
               {
                   min=tempt;
               }
               tempt=0;
           }
           c[k]=min;
           return c[k];
        }

    }
}

int main()
{
    long long int n,i=0;
    scanf("%lld",&n);
     a[0]=0;
    for(i=1;i<=n+2;i++)
    {
        a[i]=a[i-1]*2+1;
    }
    b2[0]=0;
    c2[0]=0;
    for(i=1;i<=n;i++)
    {
        b2[i]=(c2[i-1]+2*a[i-1]+1);
        c2[i]=(b2[i-1]+1+4*a[i-1]+1);
    }
    f2(n);
    /*f(n);
     for(i=1;i<=n;i++)
    {
        printf("f2(%lld)=%lld c2[%lld]=%lld f(%lld)=%lld \n",i,f2(i),i,c2[i],i,c[i]);
    }*/
    printf("%lld",f(n));
    return 0;
}

#include<stdio.h>
#include<string.h>
char a[200005];
long long int b[200005],M[10000],pow1[200005],i,j,size,count=0;
long long int f(int k)
{
    if(k==size+5)
    {
        return 1;
    }
    pow1[k]=pow1[k-1]*10;
    pow1[k]=pow1[k]-((long long int)(pow1[k]/2019))*2019;
    f(k+1);
}
int main()
{
   long long int t=0;
   scanf("%s",a);
   size=strlen(a);
   for(i=0;i<size;i++)
   {
       b[i]=a[i]-'0';
   }
   pow1[0]=1;
   f(1);
    for(i=size-1; i>=0; i--)
    {
        if(i==size-1)
        {
            //printf("%lld %lld\n",b[i],t);
            t=b[i];
            //printf("%lld\n",t);
            M[t]++;
        }
        else
        {
            t+=b[i]*pow1[size-i-1];
            t=t-((long long int)(t/2019))*2019;
            //printf("%lld\n",t);
            M[t]++;
        }


    }
    count+=M[0]+M[0]*(M[0]-1)/2;
   // printf("%lld",count);
    for(i=1; i<=2018; i++)
    {
        //printf("i=%lld count=%lld\n",M[i],count);
        count+=(long long int)(M[i]*(M[i]-1)/2);
    }
    printf("%lld",count);
    return 0;

}

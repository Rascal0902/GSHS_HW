/*#include<stdio.h>
long long int n,i,sum=0,m;
int min(int x,int y)
{
      if(x>y)
      {
          return y;
      }
      else
      {
          return x;
      }
}
int max(int x,int y)
{
      if(x>y)
      {
          return x;
      }
      else
      {
          return y;
      }
}
int main()
{
    scanf("%lld",&n);
    if(n%2==0)
    {
         m=n/2;
        for(i=1; i<=n/3; i++)
        {
            if(min(m-1,2*m-2*i-1)>=max(m-i+1,i))
           {

           if(m-1>=2*m-2*i-1)
            {
                if(i>=m-i+1)
                {
                    sum=2*m-2*i-1-i+1;
                }
                else
                {
                    sum=2*m-2*i-1-m+i;
                }
            }
            else
            {
                if(i>=m-i+1)
                {
                    sum=m-i;
                }
                else
                {
                    sum=i-1;
                }
            }
           }
        }
        printf("%lld",sum);
        return 0;
    }
    else
    {
        m=n-1/2;
        for(i=1;i<=n/3;i++)
        {
            if(m>=2*m-2*i)
            {
                if(i>=m-i+1)
                {
                    sum=2*m-2*i-i+1;
                }
                else
                {
                    sum=2*m-2*i-m+i;
                }
            }
            else
            {
                 if(i>=m-i+1)
                {
                    sum=m-i+1;
                }
                else
                {
                    sum=i;
                }
            }
        }
        printf("%lld",sum);
        return 0;
    }

}*/
#include <stdio.h>
#include <math.h>
long long int sum,i,N;
long long int max(long long int x,long long int y)
{
    if(x>=y)
    {
        return x;
    }
    else
    {
        return y;
    }
}
int main()
{
    scanf("%lld",&N);
    for(i=1;i<=N/3;i++)
        {
            sum+=(long long int)floor((N-i)/2.0);
            sum-=max((int long long)ceil((N-2*i+1)/2.0), i)-1;
        }
    printf("%lld",sum);
    return 0;
}

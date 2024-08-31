#include<stdio.h>
int main()
{
    long long int a,b,c=0,d=0;
    long long int t=0,k,j;
    scanf("%lld %lld",&a,&b);
    t=b-a+1;
    for(j=(long long int)1;j<=(long long int)100000;j++)
    {
      if(a<=(long long int)j*j)
      {
          c=j;
          break;
      }
    }
    for(j=(long long int)100000;j>=(long long int)1;j--)
    {
      if(b>=(long long int)j*j)
      {
          d=j;
          break;
      }
    }
    t=t-(d-c+1);
     printf("%lld",t);
    return 0;
}


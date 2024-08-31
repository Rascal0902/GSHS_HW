#include<stdio.h>
int main()
{
    long long int n,i,a[10000],b[10000],j=0,k,e=0;
    scanf("%lld",&n);
    while(1)
    {
        if(n==1)
        {
            break;
        }
        else
            for(i=2; i<1100000; i++)
            {
                if(n%i==0)
                {
                    a[j]=i;
                    j++;
                    n/=i;
                    break;
                }
                if(i==1000009)
                {
                    printf("%lld",n-1);
                    return 0;
                }
            }
        }
    for(i=0;i<j;i++)
    {
       b[e]=a[i];
       e++;
       b[e]=1;
       while(1)
       {
           if(a[i+1]==b[e-1])
           {
               b[e]+=1;
               i++;
           }
           else
           {
               break;
           }
       }
       e++;
    }
    for(i=0;i<e;i++)
    {
        printf("%d ",b[i]);
    }
    return 0;
}


#include<stdio.h>
long long int a[100000];
int main()
{
    int i,n,j,k;

    long long int max=(long long int)-100000000,sum=(long long int)0,x=(long long int)0;
    scanf("%d",&n);
    for(i=0; i<n; i++)
    {
        scanf("%lld",&a[i]);
    }

    for(j=0; j<n; j++)
    {
        sum+=a[j];


        if(a[j]>=0)
        {
            x=x+a[j];

        }
        else
        {
            if(sum>=0)
            {
                x=sum;
            }
            else
            {
                if(j==n-1)
                {
                   if(x>a[j])
                   {
                       sum=x;
                   }
                   else
                    {
                        sum=a[j];
                        x=a[j];
                    }

                }
                else
                {
                    sum=0;
                    x=0;
                }
            }
        }



        if(max<=sum)
        {
            max=sum;
        }

    }
    x=a[0];

    for(i=0;i<n;i++)
    {
        if(a[i]>=0)
        {
            break;
        }
        else
            {
                if(a[i]>=x)
                {
                    x=a[i];

                }
            }

        if(i==n-1)
        {
            max=x;
        }
    }

    printf("%lld",max);
    return 0;
}


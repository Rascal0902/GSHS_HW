
#include<stdio.h>

int main()
{
    long long int a,b,i,k;
    int max=0,t=0;
    scanf("%lld %lld",&a,&b);
    if(a>b)
    {
        k=a;
        a=b;
        b=k;
    }
    i=a;
    for(;;)
    {
        if(i==(long long int)1)
        {
            t++;
            if(t>max)
            {
                max=t;
            }
            t=0;
            i=a++;
            if(a>b)
            {
                printf("%d",max);
                return 0;
            }
            else
            {
                continue;
            }
        }
        else
        {
            if(i%(long long int)2==(long long int)1)
            {
                t++;
                i=(long long int)3*i+1;
            }
            else
            {
                t++;
                i=(long long int)i/2;
            }
            continue;
        }
    }
}


/*#include<stdio.h>
int main()
{
    int n,t,a,b,max=0;
    scanf("%d %d",&a,&b);
    for(n=a;n<=b;n++)
    {for(;;)
    {
        if(n==1)
        {
            t++;
            break;
        }
        if((n%2)==0)
        {
            t++;
            n=n/2;
        }
        else if((n%2)!=0)
        {
            t++;
            n=n*3+1;
        }

    }
    if(max<t)
    {
        max=t;
    }
    t=0;
    }
    printf("%d",max);
    return 0;
}
*/





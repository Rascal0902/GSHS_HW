#include<stdio.h>
int main()
{
    long long int a,b;
    scanf("%lld %lld",&a,&b);
    if((a>0)&&(b>0))
    {
        if(a>b)
        {
            printf("%lld",a-b);
        }
        else
        {
            printf("%lld",b-a);
        }
    }
    if((a<0)&&(b<0))
    {
        if(a>b)
        {
            printf("%lld",a-b);
        }
        else
        {
            printf("%lld",b-a);
        }
    }if((a>0)&&(b<0))
    {

            printf("%lld",a-b-1);

    }
    if((a<0)&&(b>0))
    {

            printf("%lld",b-a-1);

    }
    return 0;

}

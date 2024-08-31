#include<stdio.h>
int main()
{
    int i,n,a=1;
    scanf("%d",&n);
    for(i=2;i<=n-1;i++)
    {
        if(n%i==0)
        {
            break;
        }
        else
        a++;
    }
    if(a==n-1)
    {
        printf("prime");
    }
    else printf("not prime");
}


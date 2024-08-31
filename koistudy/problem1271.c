#include<stdio.h>
int main()
{
    int n,i,t=0;
    scanf("%d",&n);
    while(1)
    {
        if(n==1)
        {
            t++;
            break;
        }
        else if(n==0)
        {
            break;
        }
        else
        {
            t+=n%2;
            n=n/2;
        }
    }
    printf("%d",t);
    return 0;
}

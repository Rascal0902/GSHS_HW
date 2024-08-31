#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
    int n,i;
    scanf("%d",&n);
    while(1)
    {
        if(n==1)
        {
            break;
        }
        for(i=2; i<100000; i++)
        {
             if(n%i==0)
             {
                 printf("%d ",i);
                 n/=i;
                 break;
             }
        }
    }
    return 0;
}

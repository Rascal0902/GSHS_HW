#include<stdio.h>
int main()
{
    int a,i,k,sum=0;
    scanf("%d",&a);
    for(i=1;i<=100000;i++)
    {
        sum+=i;
        if(sum>=a)
        {
            break;
        }
    }
    printf("%d",i);
    return 0;

}

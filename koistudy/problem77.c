#include<stdio.h>
int main()
{
    int a,i,sum=0;
    scanf("%d",&a);
    for(i=0;i<=a;i++)
    {
        if(i%2==0)
        {
            sum+=i;
        }
        else continue;
    }
    printf("%d",sum);
    return 0;

}

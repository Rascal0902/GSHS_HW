#include<stdio.h>
int main()
{
    int a,b,c,i,t=1;
    scanf("%d %d %d",&a,&b,&c);
    for(i=1;i<=c;i++)
    {
        if((a%i==0)&&(b%i==0)&&(c%i==0))
        {
            t=i;
        }
    }
    printf("%d",t);
    return 0;
}

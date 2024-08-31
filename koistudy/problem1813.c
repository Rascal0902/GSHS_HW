#include<stdio.h>
int main()
{
    int a,b,c,d,e;
    scanf("%d",&a);
    scanf("%d",&b);
    scanf("%d",&c);
    scanf("%d",&d);
    scanf("%d",&e);
    if(a<0)
    {
        printf("%d",(-1)*c*a+d+b*e);
    }
    else if(a==0)
    {
        printf("%d",d+b*e);
    }
    else
    {
        printf("%d",(b-a)*e);
    }
}

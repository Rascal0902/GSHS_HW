#include<stdio.h>
int main()
{
    int n,a,b,c;
    scanf("%d",&n);
    if(n%10!=0)
    {
        printf("-1");
        return 0;
    }
    else
    {
        a=n/300;
        b=(n-(n/300)*300)/60;
        c=(n-a*300-b*60)/10;
        printf("%d %d %d",a,b,c);
        return 0;
    }
}

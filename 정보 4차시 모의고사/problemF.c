#include<stdio.h>
int main()
{
    int a,b,c=0;
    scanf("%d %d",&a,&b);
    play:
    if(a%2==1)
    {
        c=c+b;
    }
    a=a>>1;
    b=b<<1;
    if(a!=0)
    {
        goto play;
    }
    printf("%d",c);

}

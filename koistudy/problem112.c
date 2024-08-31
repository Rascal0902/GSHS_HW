#include<stdio.h>
int main()
{
    int a,b,c;
    scanf("%d %d %d",&a,&b,&c);
    if(a<b-c)
    {
        printf("advertise");
    }
    else if(a==b-c)
    {
        printf("does not matter");
    }
    else
    {
        printf("do not advertise");
    }
    return 0;
}

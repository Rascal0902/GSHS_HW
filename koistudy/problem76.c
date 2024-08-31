#include<stdio.h>
int main()
{
    int a=0,b;
    scanf("%d",&b);
    while(1)
    {
        printf("%d\n",a);
        if(a==b)
        {return 0;}
        a++;
    }
}

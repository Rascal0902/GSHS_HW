#include<stdio.h>
int printter(char x,int a)
{
    int i;
    for(i=0;i<a;i++)
    {
        printf(" %c",x);
    }
    return 0;
}
int main()
{
    int a;
    char x;
    scanf("%d",&a);
    scanf(" %c",&x);
    printter(x,a);
    return 1;
}

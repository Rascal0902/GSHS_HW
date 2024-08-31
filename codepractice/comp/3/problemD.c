#include<stdio.h>
int s=0;
void f(int a)
{
    if(a==0)
    {
        return;
    }
    f(a-1);
    for(int i=1;i<=a;i++)
    {
        printf("*");
        s++;
    }
    printf("\n");
    f(a-1);
}
int main()
{
    int a;
    scanf("%d",&a);
    f(a);
    printf("%d",s);
    return 0;
}

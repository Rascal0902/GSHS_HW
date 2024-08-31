#include<stdio.h>
#include<stdlib.h>
int main()
{
    char str[32];
    int num;
    scanf("%d",&num);
    itoa(num,str,2);
    printf("%d=%s(2)",num ,str);
}

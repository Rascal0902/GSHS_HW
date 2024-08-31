#include<stdio.h>
int add();
int main()
{
    add();
    add();
    add();
    return 0;
}
int add()
{
    static int a=10;
    a=10;
    printf("a= %d \n",a);
    a++;
}

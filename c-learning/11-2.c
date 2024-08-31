#include<stdio.h>
int main()
{
    int a,b,*pa;
    a=2;
    b=5;
    pa=&a;
    printf("p가 가르키는 값은 %d입니다.",*pa);
    *pa=b;
    printf("p가 가르키는 값은 %d입니다.",*pa);
}

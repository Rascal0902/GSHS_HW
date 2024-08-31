#include<stdio.h>
int main()
{
    int a;
    float b;
    char c;
    printf("문자 하나와 실수 하나 정수 한개를 입력하시오?");
    scanf("%c%f%d", &c,&b,&a);
    printf("출력=%c %1f  %d", c, b, a);
}

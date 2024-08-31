#include<stdio.h>
int main()
{
    int a;
    char k;
    printf("숫자 한개를 입력 하시오:");
    scanf("%d", &a);
    printf("문자 하나를 입력하시오:");
    scanf(" %c",&k);
    printf("결과=%d %c \n", a, k);

}



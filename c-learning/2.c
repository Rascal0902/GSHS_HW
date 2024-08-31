#include<stdio.h>
int main()
{
   int a,b;
   char k;
   printf("연산 할 것을 입력하시오");
   scanf("%d %c %d", &a, &k, &b);
   switch(k)
   {
      case '+' : printf("합=%d",a+b); break;
      case '-': printf("차=%d",a-b); break;
      case '/' : printf("몫=%d",a/b); break;
      case '*' : printf("곱=%d",a*b); break;
      default: printf("사칙 연산자가 아니군요.");

    }
}


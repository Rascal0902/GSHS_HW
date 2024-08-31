#include<stdio.h>
int main()
{
   int a,b;
   char k;
   scanf("%d %c %d", &a, &k, &b);
   switch(k)
   {
      case '+' : printf("%d",a+b); break;
      case '-': printf("%d",a-b); break;
      case '*' : printf("%d",a*b); break;
      case '/' : printf("%d",a/b); break;
      default: printf("사칙 연산자가 아니군요.");

    }
}

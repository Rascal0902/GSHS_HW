#include<stdio.h>
int main()
{
 int num1=10;
 int num2=12;
 int a,b,c;
 a=(num1==10&&num2==12);
 b=(num1<12||num2>12);
 c=!num1;

 printf("%d\n",a);
 printf("%d\n",b);
 printf("%d\n",c);
}

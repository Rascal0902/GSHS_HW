#include<stdio.h>
int main()
{
 int a, b, c=3, d=5, e, f;
 a=c|d;
 b=c&d;
 e=c^d;
 f=~d;
 printf("c|d=%d c&d=%d\n",a,b);
 printf("c^d=%d !d=%d",e,f);

}

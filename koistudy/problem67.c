#include<stdio.h>
int main()
{
   int a;
   scanf("%d",&a);
   if(90<=a)
   {
       printf("A");
   }
   else if((70<=a)&&(a<=89))
   {
        printf("B");
   }
   else if((40<=a)&&(a<=69))
   {
        printf("C");
   }
   else
   {
        printf("D");
   }
   return 0;
}

 //90 ~ 100 : A
 //70 ~  89 : B
// 40 ~  69 : C
 //  0 ~  39 : D

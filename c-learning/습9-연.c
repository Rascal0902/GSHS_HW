#include<stdio.h>
char k='*';
int a=1,b=0;
int stack(int n)
{
    star(a);
    printf("\n");
    a++;
    b=0;
    return((a>n)? 1:stack(n));
}
int star(int a)
{
   printf("%c",k) ;
   b++;
   return ((b>=a)? 1:star(a));


}
int main()
{
    int n;
    scanf("%d",&n);
    printf("%c",stack(n));
    return 0;
}


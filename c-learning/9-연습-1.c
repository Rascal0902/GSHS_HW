#include<stdio.h>
int max(a,b)
{
    return((a>=b)? a:b);
}
int main()
{int a,b;
 scanf("%2d %2d",&a ,&b);
 printf("%2d",max(a,b));
 return 0;
}

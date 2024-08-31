#include<stdio.h>
int main()
{
    char a[5],i,j;
   scanf("%s",a);
   for(i=0;i<=4;i++)
   {
       printf("\[%c",a[i]);
       for(j=0;j<=3-i;j++)
       {
           printf("%d",0);
       }
       printf("\]\n");
   }
   return 0;
}


#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
   int i;
   char a[203];
   fgets(a,203,stdin);
   for(i=0;i<strlen(a);i++)
   {
       if(a[i]==' ')
       {
           printf(" ");
       }
       else
       {
           if(a[i]=='a')
           {
               printf("x");
           }
           else if(a[i]=='b')
           {
               printf("y");
           }
           else if(a[i]=='c')
           {
               printf("z");
           }
           else
           {
               printf("%c",a[i]-3);
           }
       }
   }
   return 0;
}

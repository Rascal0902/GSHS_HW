 #include<stdio.h>
 #include<string.h>
 int main()
 {
   char str1[]= "how long is it.", str2[100];
   int a,b;
   gets(str2);
   a=strlen(str1);
   b=strlen(str2);
   printf("%2d %2d",a,b);


 }

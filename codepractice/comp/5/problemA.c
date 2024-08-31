#include<stdio.h>
#include<string.h>
char stack[10000],a[1000],end=0;
int push(char k)
{
    stack[end]=k;
    end++;
    return 1;
}
int pop()
{
    printf("%c",stack[end-1]);
    stack[end-1]='0';
    end--;
}
int main()
{
    int i=0;
   fgets(a, 100, stdin);
   for(i=0;i<strlen(a);i++)
   {
       push(a[i]);
   }
   i=end;
   for(i=end-1;i>=0;i--)
   {
       pop();
   }
   return 0;

}

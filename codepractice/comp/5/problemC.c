#include<stdio.h>
#include<string.h>
char stack[10000],a[1000];
int end=0;
int push(char k)
{
    stack[end]=k;
    end++;
    return 1;
}
int pop()
{
    stack[end-1]='0';
    end--;
    return 1;
}
int main()
{
   scanf("%s",a);
   int i,j;
   for(i=0;i<strlen(a);i++)
   {
       push(a[i]);
       for(j=0;;j++)
       {

            if(((stack[end-1]==')')&&(stack[end-2]=='('))&&(end>=2))
               {
                   pop();
                   pop();
               }
               else
                {
                    break;
                }
       }
   }
   if(end==0)
   {
       printf("YES");
   }
   else
   {
       printf("NO");
   }
   return 0;

}

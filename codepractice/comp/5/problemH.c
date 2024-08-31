#include<stdio.h>
#include<string.h>
char a[100],s[100];
int end,check=0;
void push(char k)
{
    s[end]=k;
    end++;
}
void pop()
{
    s[end-1]=' ';
    end--;
}
int f(int low,int high)
{
    int temp=0,i,j,A=low-1,B=low-1;
    i=0;
    for(int i=low;i<=high;i++)
    {
        push(a[i]);
        while(check==0)
        {
            if((s[end-2]=='(')&&(s[end-1]==')'))
            {
                pop();
                pop();
            }
            else if((s[end-2]=='[')&&(s[end-1]==']'))
            {
                pop();
                pop();
            }
            else
            {
                check=1;
            }
        }
        check=0;
        if(end==0)
        {

            A=B;
            B=i;

            if(a[A+1]=='(')
         {
             if((a[B]==')')&&(B==A+2))
             {
                 temp+=2;
             }
             else
             {

                 temp+=2*f(A+2,B-1);
             }

         }
         else
         {
            if((a[B]==']')&&(B==A+2))
             {
                 temp+=3;
             }
             else
             {

                 temp+=3*f(A+2,B-1);
             }
         }
        }


    }
    if(end!=0)
    {
        return 0;
    }
    return temp;
}
int main()
{
    scanf("%s",a);
    printf("%d",f(0,strlen(a)-1));
    return 0;
}

#include<stdio.h>
#include<string.h>
char stack1[1000],end1=0,stack2[1000],end2=0,a[1000],size=0;
int push1(char k)
{
    stack1[end1]=k;
    end1++;
    return 1;
}
int pop1()
{
    printf("%c",stack1[end1-1]);
    stack1[end1-1]='0';
    end1--;
}
int push2(char k)
{
    stack2[end2]=k;
    end2++;
    return 1;
}
int pop2()
{
    printf("%c",stack1[end2-1]);
    stack2[end2-1]='0';
    end2--;
}
int main()
{
    scanf("%s",a);
    size=strlen(a);
    for(int i=0;i<size;i++)
    {
        if(i%2==1)
        {
            if((a[i]=='*')||(a[i]=='/'))
            {
                push1(a[i]);
            }
            else
            {
                push2(a[i]);
            }
        }
        else
        {
            printf("%c",a[i]);
        }
    }
    for(int i=end1-1;i>=0;i--)
    {
        pop1();
    }
    for(int i=end2-1;i>=0;i--)
    {
        pop2();
    }
    return 0;
}

#include<stdio.h>
#include<string.h>
int size=-1,t=0,sum=0;
char stack[100000];
char push(char k)
{
    if(k=='(')
    {
        t++;
    }
    else
    {   sum++;
        t--;
    }
    size++;
    stack[size]=k;
    return 1;
}
int main()
{
    int i,j;
    char c[100001];
    c[100000]='0';
    scanf("%s",c);
    for(i=0;i<strlen(c);i++)
    {
        if((c[i]=='(')&&(c[i+1]==')'))
        {
            sum+=t;
            i+=1;
        }
        else{
            push(c[i]);
        }


    }
    printf("%d",sum);
    return 0;
}

/*#include<stdio.h>
int n,t,b=0;
char u[20],x[20];
int f(int k)
{
    if(k%t==1)
    {
        u[b]='1';
        b++;

    }
    else if(k%t==2)
    {
        u[b]='2';
        b++;
    }
    else if(k%t==3)
    {
        u[b]='3';
        b++;
    }
    else if(k%t==4)
    {
        u[b]='4';
        b++;
    }
    else if(k%t==5)
    {
        u[b]='5';
        b++;
    }
    else if(k%t==6)
    {
        u[b]='6';
        b++;
    }
    else if(k%t==7)
    {
        u[b]='7';
        b++;
    }
    else if(k%t==8)
    {
        u[b]='8';
        b++;
    }
    else if(k%t==9)
    {
        u[b]='9';
        b++;
    }
    else if(k%t==10)
    {
         u[b]='A';
        b++;
    }
    else if(k%t==11)
    {
        u[b]='B';
        b++;
    }
    else if(k%t==12)
    {
        u[b]='C';
        b++;
    }
    else if(k%t==13)
    {
       u[b]='D';
        b++;
    }
    else if(k%t==14)
    {
       u[b]='E';
        b++;
    }
    else
    {
        u[b]='F';
        b++;
    }
    if(k/t==0)
    {
        return 1;
    }
    else
    {
        f(k/t);
    }
}

int main()
{
    scanf("%d %d",&n,&t);
    f(n);
    int i;
    for(i=0;i<b-1;i++)
    {
        x[i]=u[b-1-i];
        printf("%c",x[i]);
    }
    return 0;
}*/


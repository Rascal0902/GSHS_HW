#include<stdio.h>
#include<string.h>
char x[10000];
long long int len,end=0,Ans[10000],s[10000],t=0,sta[10000],endsta=0;
void pusha(long long int k)
{
    sta[endsta]=k;
    endsta++;
}
void popa()
{
    sta[endsta-1]=0;
    endsta--;
}
void push(char k)
{
    if(k=='+')
    {
        s[end]=-1;
    }
    if(k=='-')
    {
        s[end]=-2;
    }
    if(k=='*')
    {
        s[end]=-3;
    }
    if(k=='/')
    {
        s[end]=-4;
    }
    if(k=='(')
    {
        s[end]=-5;
    }
    if(k==')')
    {
        s[end]=-6;
    }
    end++;
}
void pop()
{
    s[end-1]=0;
    end--;
}
char change(int k)
{
    if(k==-1)
    {
        return '+';
    }
    else if(k==-2)
    {
        return '-';
    }
    else if(k==-3)
    {
        return '*';
    }
    else if(k==-4)
    {
        return '/';
    }
    else if(k==-5)
    {
        return '(';

    }
    else if(k==-6)
    {
        return ')';
    }
    else
    {
        return -1;
    }
}
long long int prior(char k)
{
    if(k=='(')
    {
        return 1;
    }
    if(k=='+'||k=='-')
    {
        return 2;
    }
    return 3;
}
bool isop(char k)
{
    if(k=='('||k==')')return true;
    if(k=='+'||k=='-'||k=='*'||k=='/')return true;
    return false;
}
int main()
{
    scanf("%s",x);
    len=strlen(x);
    long long int st=-1;
    for(int i=0;i<len;i++)
    {
        if(isop(x[i]))
        {
            if(st!=-1)
            {
               Ans[t]=st;
               st=0;
               t++;
               st=-1;
            }
            if(x[i]=='(')
            {
               push(x[i]);
            }
            else if(x[i]==')')
            {
                while(s[end-1]!=-5)
                {
                    Ans[t]=s[end-1];
                    t++;
                    pop();
                }
                pop();
            }
            else
            {
                while((end!=0)&&prior(change(s[end-1]))>=prior(x[i]))
                {
                    Ans[t]=s[end-1];
                    t++;
                    pop();
                }
                push(x[i]);
            }
        }
        else
        {
            if(st==-1)
            {
                st=0;
            }
           st*=10;
           st+=(long long int)(x[i]-'0');
        }
    }
    if(st!=-1)
            {
               Ans[t]=st;
               st=0;
               t++;
               st=-1;
            }
    while(end!=0)
    {
        if(s[end-1]!=-5)
        {
            Ans[t]=s[end-1];
            t++;
        }
        pop();
    }
    for(int i=0;i<t;i++)
    {
        if(Ans[i]<0)
        {
            long long int n1=0,n2=0;
            n1=sta[endsta-1];
            n2=sta[endsta-2];
            if(Ans[i]==-1)
            {
                popa();
                popa();
                pusha(n1+n2);
            }
            if(Ans[i]==-2)
            {
                popa();
                popa();
                pusha(n2-n1);
            }
            if(Ans[i]==-3)
            {
                popa();
                popa();
                pusha(n1*n2);
            }
            if(Ans[i]==-4)
            {
                popa();
                popa();
                pusha((long long int)(n2/n1));
            }
        }
        else
        {
             pusha(Ans[i]);
        }
    }
    printf("%lld",sta[0]);
    return 0;
}


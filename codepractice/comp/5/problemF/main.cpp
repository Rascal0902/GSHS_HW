/*#include<stdio.h>
#include<string.h>
char stack[1000],a[1000],ans[1000];
int end=0,priorty[1000],endp=0,size,enda=0;
void pusha(char k)
{
    ans[enda]=k;
    enda++;
    return;
}
void popa()
{
    ans[enda-1]='0';
    enda--;
    return;
}
void push(char k)
{
    stack[end]=k;
    end++;
    if((k=='+')||(k=='-'))
    {
        priorty[endp]=1;
        endp++;
    }
    if((k=='*')||(k=='/'))
    {
        priorty[endp]=2;
        endp++;
    }
    if(k=='(')
    {
        priorty[endp]=0;
        endp++;
    }
    return;
}
void pop()
{
    pusha(stack[end-1]);
    stack[end-1]='0';
    end--;
    priorty[endp-1]=-1;
    endp--;
    return;
}
void stackpop(char k)
{
    int pri=0;
    if((k=='+')||(k=='-'))
    {
        pri=1;
    }
    if((k=='*')||(k=='/'))
    {
        pri=2;
    }
    while(1)
    {
        if(priorty[endp-1]<pri)
        {
            break;
        }
        else
        {
            pop();
        }
    }
    return;
}
void stackpopall()
{
    while(1)
    {
        if((end==1)&&(stack[0]=='('))
        {
            stack[end-1]='0';
            end--;
            priorty[endp-1]=-1;
            endp--;
            break;
        }
        if(end==0)
        {
            pop();
            break;
        }
        char k;
        k=stack[end-1];
        stackpop(k);
    }
    return;

}

int main()
{
    scanf("%s",a);
    size=strlen(a);
    for(int i=0; i<size; i++)
    {
        if((a[i]=='+')||(a[i]=='-')||(a[i]=='*')||(a[i]=='/')||(a[i]=='(')||(a[i]==')'))
        {
            if((end==0)&&(a[i]!='('))
            {
                push(a[i]);
            }
            else
            {
                if(a[i]==')')
                {
                    stackpopall();
                }
                else
                {
                    push(a[i]);
                }
            }
        }
        else
        {
            pusha(a[i]);
        }
    }
    if(end!=0)
    {
        stackpopall();
    }
    for(int i=0; i<enda; i++)
    {
        printf("%c",ans[i]);
    }
    return 0;
}
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
stack<char> s;
char x[1000],ans[1000];
ll len,i,t;
ll prior(char k)
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
main()
{
    cin>>x;
    len=strlen(x);
    for(i=0;i<len;i++)
    {
        if(isop(x[i]))
        {
            if(x[i]=='(')
            {
                s.push(x[i]);
            }
            else if(x[i]==')')
            {
                while(s.top()!='(')
                {
                    ans[t]=s.top();
                    t++;
                    s.pop();
                }
                s.pop();
            }
            else
            {
                while(!s.empty()&&prior(s.top())>=prior(x[i]))
                {
                    ans[t]=s.top();
                    t++;
                    s.pop();
                }
                s.push(x[i]);
            }
        }
        else
        {
            ans[t]=x[i];
            t++;
        }
    }
    while(!s.empty())
    {
        if(s.top()!='(')
        {
            ans[t]=s.top();
            t++;
        }
        s.pop();
    }
    cout<<ans;
}

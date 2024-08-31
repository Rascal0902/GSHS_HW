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

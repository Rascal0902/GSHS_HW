/*#include<stdio.h>
int n, maxi=0, cut[1000001], cnt=0;
int main()
{
    scanf("%d",&n);
    for (int i=1; i<= n; i++)
    {
        int x;
        scanf("%d", &x);
        if (maxi<x)
            maxi=x;
        if (maxi==i)
            cut[++cnt] = i;
    }
    printf("%d",cnt);
    int j=1;
    for (int i=1;i<=cnt;i++)
    {
        printf("\n%d ",cut[i]-cut[i - 1]);
        while (j<=cut[i])
            printf("%d ",j++);
    }
    return 0;
}*/
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



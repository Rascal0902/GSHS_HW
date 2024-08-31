#include<stdio.h>
#include<string.h>
long long int len,i,a[51],t=1,ans;
char x[51];
bool isop(char k)
{
    if(k=='+'||k=='-'||k=='*'||k=='/')return true;
    return false;
}
main()
{
    scanf("%s" ,x);
    len = strlen(x);
    for(i=0;i<len;i++)
    {
        if(isop(x[i]))
        {
            a[t]/=10;
            if(x[i]=='+')
            {
                a[t+1]=1;
            }
            if(x[i]=='-')
            {
                a[t+1]=2;
            }
            t+=2;
        }
        else
        {
            a[t]+=(x[i]-'0');
            a[t]*=10;
        }
    }
    a[t]/=10;
    ans=a[1];
    for(i=2;i<=t;i+=2)
    {
        if(a[i]==1)
        {
            ans+=a[i+1];
        }
        else
        {
            ans-=a[i+1];
        }
    }
    printf("%lld",ans);
}

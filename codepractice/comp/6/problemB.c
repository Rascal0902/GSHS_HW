#include<stdio.h>
long long int m,n,a[10010000],q[10001000],st=0,end=0;
void push(long long int k)
{
    q[end]=k;
    end++;
}
void pop()
{
    q[st]=0;
    st++;
}
int main()
{
    scanf("%lld %lld",&m,&n);
    long long int t;
    for(long long int i=0; i<n; i++)
    {
        scanf("%lld",&t);
        a[t]=1;
        push(t);
    }
    while(st!=end)
    {
        if((q[st]+1<=m)&&(a[q[st]+1]==0))
        {
            a[q[st]+1]=a[q[st]]+1;
            push(q[st]+1);
        }
        if((q[st]-1>=1)&&(a[q[st]-1]==0))
        {
            a[q[st]-1]=a[q[st]]+1;
            push(q[st]-1);
        }
        pop();
    }
    for(long long int i=1; i<=m; i++)
    {
        printf("%lld ",a[i]);
    }
}

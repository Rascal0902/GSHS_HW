#include<stdio.h>
long long int m,n,a[1000002],q[1000002],st=0,end=0;
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
    for(long long int i=0;i<n;i++)
    {
        long long int t;
        scanf("%lld",&t);
        a[t]=1;
        push(t);
    }
    while(st!=end)
    {
        if(q[st]==1)
        {
            if(a[2]==0)
            {
               a[2]=a[1]+1;
               push(2);
            }
        }
        if(q[st]==m)
        {
             if(a[m-1]==0)
            {
               a[m-1]=a[m]+1;
               push(m-1);
            }
        }
        else
        {
            if(a[q[st]+1]==0)
            {
                a[q[st]+1]=a[q[st]]+1;
                push(q[st]+1);
            }
            if(a[q[st]-1]==0)
            {
                a[q[st]-1]=a[q[st]]+1;
                push(q[st]-1);
            }
        }
        pop();
    }
    for(long long int i=1;i<=m;i++)
    {
        printf("%lld ",a[i]);
    }
}


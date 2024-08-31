#include<stdio.h>
long long int q[10000000],st=1,end=1,n,m,k,t=1;
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
    scanf("%lld %lld %lld",&n,&m,&k);
    push(n);
    push(m);
    while(t<k)
    {
        long long int c=q[st];
        push(n*c%1000000007);
        push(m*c%1000000007);
        pop();
        t++;
    }
    printf("%lld",q[st]);
    return 0;
}

#include<stdio.h>
int q[100000],A[1000000],st=0,end=0,a,b,enda=0,sta=0;
void pusha(int k)
{
    A[enda]=k;
    enda++;
}
void popa()
{
    A[sta]=0;
    sta++;
}
void push(int k)
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
    scanf("%d %d",&a,&b);
    push(a);
    pusha(0);
    while(st!=end)
    {
        if(q[st]==b)
        {
            printf("%d",A[sta]);
            return 0;
        }
        else
        {
            push(q[st]+1);
            pusha(A[st]+1);
             push(q[st]-1);
            pusha(A[st]+1);
             push(q[st]+5);
            pusha(A[st]+1);
             push(q[st]-5);
            pusha(A[st]+1);
             push(q[st]+10);
            pusha(A[st]+1);
             push(q[st]-10);
            pusha(A[st]+1);
            pop();
            popa();
        }

    }
}

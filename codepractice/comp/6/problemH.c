#include<stdio.h>
int q[1000000],t[1000000],endt=0,stt=0,mod[10005],end=0,st=0,a,b,n;
void pusht(int k)
{
    t[endt]=k;
    endt++;
}
void popt()
{
    t[stt]=0;
    stt++;
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
    scanf("%d",&n);
    int T;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&T);
        mod[T]=1;
    }
    mod[a]=1;
    push(a);
    pusht(0);
    while(st!=end)
    {
        //printf("%d\n\n",q[st]);
        if(q[st]==b)
        {
            printf("%d",t[stt]);
            return 0;
        }
        else
        {
            if(mod[(q[st]+1)%10000]==0)
            {
                mod[(q[st]+1)%10000]=1;
                push((q[st]+1)%10000);
                pusht(t[stt]+1);
            }
             if(mod[(q[st]+9999)%10000]==0)
            {
                mod[(q[st]+9999)%10000]=1;
                push((q[st]+9999)%10000);
                pusht(t[stt]+1);
            }
            if(mod[(q[st]+10)%10000]==0)
            {
                mod[(q[st]+10)%10000]=1;
                push((q[st]+10)%10000);
                pusht(t[stt]+1);
            }
            if(mod[(q[st]+9990)%10000]==0)
            {
                mod[(q[st]+9990)%10000]=1;
                push((q[st]+9990)%10000);
                pusht(t[stt]+1);
            }
            if(mod[(q[st]+100)%10000]==0)
            {
                mod[(q[st]+100)%10000]=1;
                push((q[st]+100)%10000);
                pusht(t[stt]+1);
            }
            if(mod[(q[st]+9900)%10000]==0)
            {
                mod[(q[st]+9900)%10000]=1;
                push((q[st]+9900)%10000);
                pusht(t[stt]+1);
            }
            if(mod[(q[st]+1000)%10000]==0)
            {
                mod[(q[st]+1000)%10000]=1;
                push((q[st]+1000)%10000);
                pusht(t[stt]+1);
            }
            if(mod[(q[st]+9000)%10000]==0)
            {
                mod[(q[st]+9000)%10000]=1;
                push((q[st]+9000)%10000);
                pusht(t[stt]+1);
            }
        }
        pop();
        popt();
    }
    printf("-1");
    return 0;
}

#include<stdio.h>
int stack[100020],end=0,n,a[100020],num1=1,c[2000000],end2=0;
int push(int k)
{
    stack[end]=k;
    end++;
    c[end2]=1;
    end2++;
    return 1;
}
int pop1()
{
    stack[end-1]=0;
    end--;
    c[end2]=2;
    end2++;
    return 1;
}
int check(int k)
{
    for(int i=0;i<end;i++)
    {
        if(stack[i]==k)
        {
            return 1;
        }
    }
        return -1;
}
int pushnum(int k)
{
    int t=0;
    while(1)
    {
        if(num1>n+1)
        {
            return 1;
        }
        if(num1==k)
        {
            push(k);
            pop1();
            num1++;
            return 1;
        }
        else
        {
              push(num1);
              num1++;
        }
        t++;
        if(t>3000000)
        {
            printf("NO");
            return 0;
        }
    }
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(int i=1;i<=n;i++)
    {
        if(check(a[i])==1)
        {
            if(stack[end-1]==a[i])
            {
                pop1();

            }
            else
            {
                printf("NO");
                return 0;
            }
        }
        else
        {
            pushnum(a[i]);
        }
    }
        for(int i=0;i<end2;i++)
        {
            if(c[i]==1)
            {
                printf("+\n");
            }
            else
            {
                printf("-\n");
            }
        }
    return 0;
}

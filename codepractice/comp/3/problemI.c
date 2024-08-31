#include<stdio.h>
int n,a[35],start=0,end=0;
void push(int k)
{
   a[end]=k;
   end++;
}
void pop()
{
    a[end-1]=0;
    end--;
}
int f(int tot,int max)
{
    if(tot>n)
    {
        return 1;
    }
    else if(tot==n)
    {
        int i;
        for(i=0;i<end;i++)
        {
            printf("%d ",a[i]);
        }
        printf("\n");
        return 1;
    }
    else
    {
        int i;
        for(i=max;i>=1;i--)
        {
            push(i);
            f(tot+i,i);
            pop();
        }
        return 1;
    }
}
int main()
{
    scanf("%d",&n);
    f(0,n);
    return 0;
}

#include<stdio.h>
int b[15],end=0,n,a=1,sum=0;
void push(int k)
{
    b[end]=k;
    end++;
}
void pop()
{
    b[end-1]=0;
    end--;
}
void s(int k)
{
    int temp=0;
    int i,j;
    if(k==n)
    {
        sum+=1;
        return;
    }
    else
    {
        for(i=0; i<n; i++)
        {
            a=1;
            for(j=0;j<end;j++)
            {
                if(i==b[j])
                {
                    a=0;
                }
                if(b[j]-i==k-j)
                {
                    a=0;
                }
                if(i-b[j]==k-j)
                {
                    a=0;
                }
            }
            if(a==1)
            {
                push(i);
                s(k+1);
                pop();
            }
            else
            {
                temp++;
            }


        }

    }
}
int main()
{
    int i,j;
    scanf("%d",&n);
    for(i=n-1;i>=0;i--)
    {
        push(i);
        s(1);
        for(j=0; j<=end; j++)
        {
            b[j]=0;
        }
        end=0;
    }
    printf("%d",sum);
    return 0;
}

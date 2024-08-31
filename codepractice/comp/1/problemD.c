#include <stdio.h>
int i,n,s[50],end=1;
void push(int k)
{
    s[end]=k;
    end++;
}
void pop()
{
    end--;
    s[end]=0;
}
void star(int k, int tot)
{
    if(k+tot>n)
    {
        return;
    }
    if(k+tot==n)
    {
        for(int i=1; i<end; i++)
        {
            for(int j=1; j<=s[i]; j++)
            {
                printf("*");
            }
            printf("\n");
        }
        printf("\n");
    }
    else
    {
        for(int i=k; i>=1; i--)
        {
            push(i);
            star(i,tot+k);
            pop();
        }
    }
}
int main()
{
    scanf("%d",&n);
    for(i=n; i>=1; i--)
    {
        push(i);
        star(i,0);
        pop();
    }
}

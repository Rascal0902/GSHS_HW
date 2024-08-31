#include<stdio.h>
void f(int k)
{
    int i,t=0;
    for(i=2;i<=k-1;i++)
    {
        if(k%i==0)
        {
            continue;
        }
        else
            {
                t++;
            }
    }
    if(t==k-2)
    {
        printf("%s\n","prime");
    }
    else
    {
        printf("%s\n","composite");
    }
}

int main()
{
    int n;
    scanf("%d",&n);
    f(n);
    return 0;
}

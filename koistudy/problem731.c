#include<stdio.h>
int f(int k)
{
    int i,t=1;
    for(i=1;i<=k/2+1;i++)
    {
        if(k%i==0)
        {
            t++;
        }
    }
    return t;
}

int main()
{
    int a,b,i,t=0;
    scanf("%d %d",&a,&b);
    for(i=a;i<=b;i++)
    {

        if(f(i)%2==0)
        {
            t++;
        }
    }
    printf("%d",t);
    return 0;
}

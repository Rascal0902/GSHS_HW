#include<stdio.h>
int n,k;
int f(int a,int b)
{
    if(a==0)
    {
        return 1;
    }
    f(a/b,b);
    printf("%X",a%b);
}
int main()
{
    scanf("%d %d",&k,&n);
    f(k,n);
    return 0;
}


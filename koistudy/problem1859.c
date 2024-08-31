#include<stdio.h>
void f(int k)
{
    int i;
    for(i=1;i<=k;i++)
    {
        printf("%c",'*');
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    f(n);
    return 0;
}


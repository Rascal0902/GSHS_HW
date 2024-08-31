#include<stdio.h>
int n;
int pt(int k)
{
    printf("%d*%d=%d\n",n,k,n*k);
    if(k==9)
    {
        return 1;
    }
    else
    {
        pt(k+1);
        return 1;
    }
}
int main()
{
    scanf("%d",&n);
    pt(1);
    return 0;
}

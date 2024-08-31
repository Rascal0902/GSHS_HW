#include<stdio.h>
int f(int k)
{
    int i;
    for(i=1;i<=9;i++)
    {
        printf("%d*%d=%d\n",k,i,k*i);
    }
    return 1;
}
int main()
{
    int n;
    scanf("%d",&n);
    if(n>=2)
    {
        f(n);
        return 0;
    }
    else
    {
        int i,j;
    for(i=1;i<=9;i++)
    {
        for(j=2;j<=9;j++)
        {
             printf("%d*%d=%d ",j,i,j*i);
        }
       printf("\n");
    }
    }
}

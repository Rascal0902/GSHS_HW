#include<stdio.h>
int main()
{
    int m,n,k;
    scanf("%d %d %d",&n,&m,&k);
    if((n-1-k)%(m+1)==0)
    {
        printf("no");
    }
    else
    {
        printf("yes");
    }
    return 0;
}

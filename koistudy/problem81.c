#include<stdio.h>
int main()
{
    int m,i;
    scanf("%X",&m);
    for(i=1;i<=15;i++)
    {
        printf("%X*%X=%X\n",m,i,m*i);
    }
    return 0;
}


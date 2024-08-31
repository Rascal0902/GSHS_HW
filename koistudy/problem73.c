#include<stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    while(1)
    {
        if(n==0)
        {
            break;
        }
        else
        {
            printf("%d\n",n);
            n--;
        }
    }
}

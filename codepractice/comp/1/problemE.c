#include<stdio.h>
int n;
int main()
{
    scanf("%d",&n);
    if(n%4==0)
    {
         printf("%d",(n+1)/2*(n+1)/2);

    }
    else if(n%4==1)
    {
        printf("%d",n*(n+1)/2-(n+1)/2*(n+1)/2);
    }
    else if(n%4==2)
    {
       printf("%d",n*(n+1)/2-(n+1)/2*(n+1)/2);
    }
    else
    {
         printf("%d",(n+1)/2*(n+1)/2);
    }
}

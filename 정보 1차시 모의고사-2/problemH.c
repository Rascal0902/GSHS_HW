#include<stdio.h>
int main()
{
    int n,i,s=0;
    scanf("%d",&n);
    if(n%2==0)
    {
        for(i=0;i<=n/2;i++)
        {
            s+=8*i;
        }
        printf("%d",s+1);
        return 0;
    }
    else
    {
        for(i=0;i<=(n-1)/2;i++)
        {
            s+=4*(2*i+1);
        }
         printf("%d",s);
        return 0;
    }

}

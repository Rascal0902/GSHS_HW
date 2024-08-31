#include<stdio.h>
int main()
{
    int n,s[10000],sum=0,t=100,i;
    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        scanf("%d",&s[i]);
        sum+=s[i];
        if(t>=s[i])
        {
            t=s[i];
        }
    }
    printf("%d",sum-t);
}

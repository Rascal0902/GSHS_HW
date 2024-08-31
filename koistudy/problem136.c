#include<stdio.h>
int main()
{
    int n,a[100000],k,i,t=-2;
    scanf("%d %d",&n,&k);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(i=n-1;i>=0;i--)
    {
        if(k==a[i])
        {
            t=i;
        }
    }
    printf("%d",t+1);
}


#include<stdio.h>
int main()
{
    int a[100000],t,i,n,k;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    scanf("%d",&k);
    t=n+1;
    for(i=0;i<n;i++)
    {
        if(k<a[i])
        {
            t=i+1;
            break;
        }
    }
    printf("%d",t);
    return 0;
}

#include<stdio.h>
int main()
{
    int a[10000],n,i,rev;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    for(i=1;i<n;i++)
    {
        if(a[0]>=a[i])
        {
            a[0]=a[i];
        }
    }
    printf("%d",a[0]);
}

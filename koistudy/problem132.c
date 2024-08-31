#include<stdio.h>
int main()
{
    int a[1000],n,i,sum=0;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        sum+=a[i];
    }
    printf("%d\n%.2f",sum,(float)sum/n);
return 0;
}

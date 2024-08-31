#include<stdio.h>
int main()
{
    int a[4],i,k;
    for(i=0;i<=3;i++)
    {
        scanf("%d",&a[i]);
    }
    k=a[0]+a[1]+a[2]+a[3];
    printf("%d\n%d",k/60,k-(k/60)*60);
    return 0;
}

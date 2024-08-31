#include<stdio.h>
int a[50],b[50],x,y,z,n;
int ap(int z)
{
    a[z]=b[z-1]+a[z-1];
    return 1;
}
int bp(int z)
{
    b[z]=b[z-1]+z-1;
    return 1;
}
    int main()
{
    int i;
    scanf("%d %d %d",&n,&x,&y);
    a[1]=x;
    b[1]=y;
    for(i=2;i<=n;i++)
    {
        ap(i);
        bp(i);
    }
    printf("N   a[]   b[]   c[]\n");
    for(i=1;i<=n;i++)
    {
        printf("%d     %d     %d     %d",i,a[i],b[i],i);
        printf("\n");
    }
    return 0;
}

#include<stdio.h>
int a[20],b[20],c[20];
int main()
{
    int n,i;
    scanf("%d",&n);
    for(i=1;i<n+2;i++)
    {
        a[i]=(1<<i)-1;
    }
    b[0]=0;
    c[0]=0;
    for(i=1;i<=n;i++)
    {
        b[i]=c[i-1]+2*a[i-1]+1;
        c[i]=b[i-1]+1+4*a[i-1]+1;
    }
    printf("%d",c[n]);
    return 0;
}


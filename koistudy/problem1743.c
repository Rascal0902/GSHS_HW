#include<stdio.h>
int main()
{
    long long int n,a[100],i,j,k,b[100][3];

    scanf("%lld %lld",&n,&k);
    for(i=1;i<=n;i++)
    {
        a[i]=0;
    }

    for(i=0;i<k;i++)
    {
        for(j=0;j<3;j++)
        {
            scanf("%lld",&b[i][j]);

        }
        a[b[i][0]]=a[b[i][0]]+b[i][2];
        a[b[i][1]+1]=a[b[i][1]+1]-b[i][2];
    }
    for(i=1;i<=n;i++)
    {
        printf("%lld ",a[i]);
    }
    printf("\n");
    for(i=2;i<=n;i++)

    {
        a[i]=a[i-1]+a[i];
    }
 for(i=1;i<=n;i++)
    {
        printf("%lld ",a[i]);
    }
return 0;
}

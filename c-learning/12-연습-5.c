#include<stdio.h>
int main()
{
    int n,k,i,j=0;
    scanf("%d %d",&n,&k);

    int a[n];
    for(i=1;i<=n;i++)
    {
        if(n%i==0)
        {
            a[j]=i;
            j++;
        }
        else continue;
    }
    printf("%d",a[k-1]);

}

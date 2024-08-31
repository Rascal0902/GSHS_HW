#include<stdio.h>
int main()
{
    int n,k,a[10001]={0,},i,j=1;
    scanf("%d %d",&n,&k);
    for(i=1;i<=n;i++)
    {
        if(n%i==0)
        {
            a[j]=i;
            j++;
        }
    }
    printf("%d",a[k]);
    return 0;

}

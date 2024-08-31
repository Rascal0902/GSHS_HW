#include<stdio.h>
int main()
{
    int a[100],i,n,j,k;
    long long int s=(long long int)0,max=(long long int)-100000;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(i=0;i<n;i++)
    {
        for(j=i;j<n;j++)
        {
            for(k=i;k<=j;k++)
            {
                s+=(long long int)a[k];
            }
            if(max<=s)
            {
                max=s;
            }
            s=(long long int)0;

        }
    }
      printf("%lld",max);
      return 0;
}

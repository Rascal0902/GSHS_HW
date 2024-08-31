#include<stdio.h>
int main()
{
    int n,a[10000],i,min,max,x=0,y=0;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    min=a[0];
    max=a[0];
    for(i=n-1;i>=0;i--)
    {
        if(min>=a[i])
        {
            x=i;
            min=a[i];
        }
        if(max<=a[i])
        {
            y=i;
            max=a[i];
        }
    }
    printf("%d : %d\n",y+1,max);
    printf("%d : %d",x+1,min);
}

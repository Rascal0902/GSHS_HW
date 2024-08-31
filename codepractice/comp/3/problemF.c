#include<stdio.h>
int n,k,a[15];
int main()
{
    scanf("%d %d",&n,&k);
    int i;
    for(i=0; i<k; i++)
    {
        scanf("%d",&a[i]);
    }
    int min=0,max=0;
    for(i=0; i<k; i++)
    {
        if(a[i]>n-a[i])
        {
            if(max<a[i])
            {
                max=a[i];
            }
            if(min<n-a[i])
            {
                min=n-a[i];
            }
        }
        else
        {
            if(max<n-a[i])
            {
                max=n-a[i];
            }
            if(min<a[i])
            {
                min=a[i];
            }

        }
    }
    printf("%d %d",min,max);
}

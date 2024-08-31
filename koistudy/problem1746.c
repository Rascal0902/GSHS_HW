
#include<stdio.h>
int main()
{
    int n,k,a[100],b[100],x,y,i,t=0;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    k=2;
    x=0;
    y=k-1;
    while(1)
    {
        if(y>=n-1)
        {
            b[t]=a[x];
            for(i=x;i<n;i++)
            {
                if(a[i]>=b[t])
                {
                  b[t]=a[i];
                }
            }
            break;
        }
        else
        {
             b[t]=a[x];
            for(i=x;i<=y;i++)
            {
                if(a[i]>=b[t])
                {
                  b[t]=a[i];
                }
            }
          t++;
          x+=k;
          y+=k;
        }
    }
    for(i=0;i<=t;i++)
    {
        printf("%d ",b[i]);
    }
    return 0;
}


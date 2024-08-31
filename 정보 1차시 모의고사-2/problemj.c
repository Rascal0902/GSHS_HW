#include<stdio.h>
int main()
{
    int n,a[102],b[102],i,j,k,x,y;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d %d",&a[i],&b[i]);
    }
    i=1;
    for(i=1;i<n;i++)
    {

        x=a[i]*b[i-1]+a[i-1]*b[i];
        y=b[i]*b[i-1];
        a[i]=x;
        b[i]=y;
        while(1)
        {
            if((x%y==0)||(y%x==0))
            {
                k=(x>=y)? y:x;
                break;

            }
           if(x>y)
           {
               x=x-y;
           }
           else
           {
               y=y-x;
           }
        }
        a[i]=a[i]/k;
        b[i]=b[i]/k;

        k=0;
        j=0;
    }
    printf("%d/%d",a[n-1],b[n-1]);
    return 0;
}

#include<stdio.h>
int main()
{
    int n,a[102],b,c,d,i,j,t=0;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d %d %d",&b,&c,&d);
        for(j=1;j<=b;j++)
        {
            if(c*j%d==0)
            {
                continue;
            }
            else
            {
                t++;
            }
        }
        a[i]=b*c/d+t;
        b=0;
        c=0;
        d=0;
        t=0;
    }
    for(i=0;i<n;i++)
    {
        printf("Case #%d: %d\n",i+1,a[i]);
    }
    return 0;
}

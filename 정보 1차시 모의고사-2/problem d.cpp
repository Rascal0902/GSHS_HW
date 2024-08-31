#include<stdio.h>
int main()
{
    int n,a[12][2],b[12][2],i,j,k[12],m;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d %d",&a[i][0],&a[i][1]);
        a[i][0]=a[i][0]%1440;
        a[i][1]=a[i][1]%1440;
        int t;
        if(a[i][1]>a[i][0])
        {
            t=a[i][1]-a[i][0];
        }
        else
        {
            t=a[i][0]-a[i][1];
        }
        for(j=1;; j++)
        {
            if(t*j%1440==0)
            {
                k[i]=j;
                break;
            }
        }

        b[i][0]=k[i]*a[i][0];
        }
    for(i=0;i<n;i++)
    {
        b[i][1]=(b[i][0]/60+k[i])%24;
        b[i][0]=b[i][0]%60;
        if(b[i][0]<=9)
        {
            if(b[i][1]<=9)
            {
                printf("0%d:0%d\n",b[i][1],b[i][0]);
            }
            else
            {
                printf("%d:0%d\n",b[i][1],b[i][0]);
            }
        }
        else
        {
            if(b[i][1]<=9)
            {
                printf("0%d:%d\n",b[i][1],b[i][0]);
            }
            else
            {
                printf("%d:%d\n",b[i][1],b[i][0]);
            }
        }
    }
    return 0;
}

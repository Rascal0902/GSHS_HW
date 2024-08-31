#include<stdio.h>
int main()
{
    int a[100],b[100],n,i,j,k=0;
    scanf("%d",&n);
    for(i=-100; i<100; i++)
    {
        for(j=-100; j<100; j++)
        {
            if((i!=j)&&(i*i+j*j==n))
            {
                a[k]=i,b[k]=j;
                k++;
            }
        }
    }
    if(a[0]==0)
    {
        printf("impossible");
    }
    else
    {
        printf("possible");
        printf(", %d°¡Áö \n",k);
        printf(" X         Y\n");
        for(i=0; i<k; i++)
        {
            printf("(%d)^2  + (%d)^2\n",a[i],b[i]);
        }
    }
    return 0;
}

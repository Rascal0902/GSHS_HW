#include<stdio.h>
int main()
{
    int n,a[10][4],i,j,s=0;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        for(j=0;j<4;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<4;j++)
        {
            s+=a[i][j];
        }
        if(s==0)
        {
            printf("M ");
        }
        else if(s==1)
        {
            printf("D ");
        }
        else if(s==2)
        {
            printf("K ");
        }
        else if(s==3)
        {
            printf("G ");
        }
        else
        {
            printf("U ");
        }
        s=0;
    }
    return 0;
}

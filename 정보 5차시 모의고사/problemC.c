#include<stdio.h>
int main()
{
    int n,a[100][100],i,j,t=1,x=0,y=-1,z=1,k;
    scanf("%d",&n);
    k=n;
    while(n>0)
{
        for (i = 0; i < n; i++)
        {
            y +=t;
            a[x][y] = z;
            z++;
        }
        n--;

        if (n == 0)
            break;
        for (i = 0; i < n; i++)
        {
            x += t;
            a[x][y] =z;
            z++;
        }
        t*= -1;
    }
    for(i=0; i<k; i++)
    {
        for(j=0; j<k; j++)
        {
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
    return 0;
}

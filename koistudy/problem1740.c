#include<stdio.h>
int main()
{
    int n,m,i,j,x,y,a[100][100],z,w,k,b;
    scanf("%d %d",&n,&m);
    b=n*m+1;
    k=1;
    x=-1;
    y=m-1;
    z=m-1;
    w=n;
    while(1)
    {
        for(i=0; i<w; i++)
        {
            b--;
            x+=k;
            a[x][y]=b;
        }
        if(z==0)
            break;
        for(i=0; i<z; i++)
        {
            b--;
            y-=k;
            a[x][y]=b;
        }
        z-=1;

        if(w==1)


            break;
        k*=-1;
        w-=1;
    }
    for(i=n-1;i>=0;i--)
    {
        for(j=m-1;j>=0;j--)
        {
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
    return 0;
}




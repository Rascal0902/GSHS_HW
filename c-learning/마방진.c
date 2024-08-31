#include<stdio.h>
int main()
{
    int a[100][100]= {0},i,j,n,x,y;
    scanf("%d",&n);
    a[0][(n-1)/2]=1;
    x=0;
    y=(n-1)/2;
    for(i=2; i<=n*n; i++)
    {
        if(x-1>=0)
        {
            if(y+1<=n-1)
            {
                if(a[x-1][y+1]!=0)
                {
                    a[x+n-2][y]=i;
                    x+=n-2;
                }
                else
                {
                    a[x-1][y+1]=i;
                    x-=1,y+=1;
                }
            }
            else
            {
                a[x-1][y-n+1]=i;
                x-=1,y-=n-1;
            }
        }
        else
        {
            if(y+1<=n-1)
            {
                a[x+n-1][y+1]=i;
                x+=n-1,y+=1;
            }
            else
            {
                a[x+n-2][y]=i;
                x+=n-2;
            }
        }

    }
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            printf("%d",a[i][j]);
        }
        printf("\n");
    }
    return 0;
}

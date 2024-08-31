#include<stdio.h>
int n,a[1030][1030];
int f(int lowx,int lowy,int dx,int dy)
{

    int x0=0,x1=0,i,j;
    for(i=lowx;i<lowx+dx;i++)
    {
        for(j=lowy;j<lowy+dy;j++)
        {
            if(a[i][j]==0)
            {
                x0=1;
            }
            else
            {
                x1=1;
            }
        }
    }
    if((x1==1)&&(x0==1))
    {
       printf("X");
       f(lowx,lowy,dx/2,dy/2);
       f(lowx,lowy+dy/2,dx/2,dy/2);
       f(lowx+dx/2,lowy,dx/2,dy/2);
       f(lowx+dx/2,lowy+dy/2,dx/2,dy/2);
    }
    else
    {

        if(x1==1)
        {
            printf("1");
        }
        else
        {
            printf("0");
        }
        return 1;
    }
}
int main()
{
    int i,j;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    f(0,0,n,n);
    return 0;
}

/*#include<stdio.h>
int n,a[1030][1030];
int f(int lowx,int lowy,int dx,int dy)
{
   // printf("\n%d %d %d %d\n",lowx,lowy,dx,dy);
    printf("X");
    int x0=0,x1=0,i,j,A[4];
    x0=0;
    x1=0;
    for(i=lowx; i<lowx+dx/2; i++)
    {
        for(j=lowy; j<lowy+dy/2; j++)
        {
            if(a[i][j]==0)
            {
                x0=1;
            }
            else
            {
                x1=1;
            }
        }
    }
    if((x1==0)||(x0==0))
    {
        //printf("111111\n");
        A[0]=1;
        if(x1==1)
        {
            printf("1");
        }
        else
        {
            printf("0");
        }
    }
    else
    {
        A[0]=0;
    }
    x0=0;
    x1=0;
    for(i=lowx; i<lowx+dx/2; i++)
    {
        for(j=lowy+dy/2; j<lowy+dy; j++)
        {
            if(a[i][j]==0)
            {
                x0=1;
            }
            else
            {
                x1=1;
            }
        }
    }
    if((x1==0)||(x0==0))
    {
        A[1]=1;
        if(x1==1)
        {
            printf("1");
        }
        else
        {
            printf("0");
        }
    }
    else
    {
        A[1]=0;
    }
    x0=0;
    x1=0;
    for(i=lowx+dx/2; i<lowx+dx; i++)
    {
        for(j=lowy; j<lowy+dy/2; j++)
        {
            if(a[i][j]==0)
            {
                x0=1;
            }
            else
            {
                x1=1;
            }
        }
    }
    if((x1==0)||(x0==0))
    {
        A[2]=1;
        if(x1==1)
        {
            printf("1");
        }
        else
        {
            printf("0");
        }
    }
    else
    {
        A[2]=0;
    }
    x0=0;
    x1=0;
    for(i=lowx+dx/2; i<lowx+dx; i++)
    {
        for(j=lowy+dy/2; j<lowy+dy; j++)
        {
            if(a[i][j]==0)
            {
                x0=1;
            }
            else
            {
                x1=1;
            }
        }
    }
    if((x1==0)||(x0==0))
    {
        A[3]=1;
        if(x1==1)
        {
            printf("1");
        }
        else
        {
            printf("0");
        }
    }
    else
    {
        A[3]=0;
    }
    if(dx!=1)
    {
        if(A[0]==0)
        {
            f(lowx,lowy,dx/2,dy/2);
        }
        if(A[2]==0)
        {

            f(lowx+dx/2,lowy,dx/2,dy/2);
        }
         if(A[1]==0)
        {
            f(lowx,lowy+dy/2,dx/2,dy/2);
        }

        if(A[3]==0)
        {
            f(lowx+dx/2,lowy+dy/2,dx/2,dy/2);
        }
    }
    else
    {
        return 1;
    }

}
int main()
{
    int i,j;
    scanf("%d",&n);
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    f(0,0,n,n);
    return 0;
}*/

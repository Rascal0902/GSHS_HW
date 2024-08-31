#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int n,C[1030][1030],s=0,size;
char a[2000010];
int f(int lowx,int lowy,int dx,int dy)
{
    //printf("lowx=%d lowy=%d dx=%d dy=%d s=%d\n",lowx,lowy,dx,dy,s);
    int i,j;
    if(s>=size)
    {
        return 1;
    }
    else
    {
        if(a[s]!='X')
        {
            int t;
            t=a[s]-'0';
            for(i=lowx; i<lowx+dx; i++)
            {
                for(j=lowy; j<lowy+dy; j++)
                {
                    C[i][j]=t;
                }
            }
            s++;
        }
        else
        {
            s++;
            if(dx>=2)
            {
                f(lowx,lowy,dx/2,dy/2);
                f(lowx,lowy+dy/2,dx/2,dy/2);
                f(lowx+dx/2,lowy,dx/2,dy/2);
                f(lowx+dx/2,lowy+dy/2,dx/2,dy/2);
            }
            return 1;
        }
        return 1;
    }

}
int main()
{
    int i,j;
    scanf("%d",&n);
    scanf("%s",a);
    size=strlen(a);
    f(0,0,n,n);
    for(i=0; i<n; i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%d ",C[i][j]);
        }
        printf("\n");
    }
    return 0;
}

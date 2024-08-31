#include<stdio.h>
int main()
{
    int i,j,k,m,n,l;
    scanf("%d %d %d",&m,&n,&l);
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            for(k=0;k<l;k++)
            {
                printf("%d %d %d\n",i,j,k);
            }
        }
    }
    printf("%d",m*n*l);
    return 0;
}

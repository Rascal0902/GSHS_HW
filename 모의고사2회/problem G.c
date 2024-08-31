#include<stdio.h>
int main()
{
    int a[100][100]= {0,},i,j,k,n,b[101][2],sum=0;
    scanf("%d",&n);
    for(i=1; i<=n; i++)
    {
        scanf("%d %d",&b[i][0],&b[i][1]);
    }
    for(i=1; i<=n; i++)
    {
        for(j=0; j<10; j++)
        {
            for(k=0; k<10; k++)
            {
               a[b[i][0]+j][b[i][1]+k]++;
            }
        }
    }
    for(i=0;i<100;i++)
    {
        for(j=0;j<100;j++)
        {
            if(a[i][j]!=0)
            {
                sum++;
            }
        }
    }
   printf("%d",sum);
   return 0;
}

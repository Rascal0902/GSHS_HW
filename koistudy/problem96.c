#include<stdio.h>
int main()
{
    int n,i,j,x,y;
    int a[20][20]={0};
for(i=1;i<=19;i++)
  {
    for(j=1;j<=19;j++)
    {
        scanf("%d",&a[i][j]);
    }
  }
scanf("%d",&n);
for(i=1;i<=n;i++)
  {
   scanf("%d %d",&x,&y);
   for(j=1;j<=19;j++)
   {
    a[x][j]=1-a[x][j];
   }
   for(j=1;j<=19;j++)
   {
    a[j][y]=1-a[j][y];
   }

  }
for(i=1;i<=19;i++)
  {
      for(j=1;j<=19;j++)
      {
        printf("%d ",a[i][j]);
      }
    printf("\n");
  }
}

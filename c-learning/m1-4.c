#include<stdio.h>
int main()
{
  int n,m,x,y,i,j,a[50][50];
  scanf("%d %d",&n,&m);
  y=m-n;
  x=m-n;
  for(i=0;i<=2*(m-n);i++)
  {
   for(j=x;j<=y;j++)
  {
      a[i][j]=n;
  }
  if(i<=n-m+1)
  {x--,y++;}
  else
  {
      x++,y--;
  }
}

  for(i=0;i<=2*(m-n);i++)
  {
      for(j=0;j<=2*(m-n);j++)
      {
          printf("%2d",a[i][j]);
      }
      printf("\n");
  }
 return 0;
  }

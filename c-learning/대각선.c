#include<stdio.h>
int main()
{
    int arr[5][5],a,i,j,k;
    k=0,a=0;
    for(a=0;a<5;a++)
    {
      for(i=0;i<=a;i++)
    {
        arr[i][a-i]=++k;
        }
    }
   for(a=5;a<=8;a++)
   {
    for(i=0;i<=a;i++)
    {
        if(i<=4&&a-i<=4)
        arr[i][a-i]=++k;
    }
   }

    for(i=0;i<5;i++)
    {
        for(j=0;j<5;j++)
        {
            printf("%3d",arr[i][j]);
        }
        printf("\n");
    }

}

#include<stdio.h>
int main()
{
    int arr[5][5]={0,} ;
    int i,j,k,m,n;
    char x=' ';
    k=0;
    for(i=0;i<5;i++)
    {

         for(j=0;j<5;j++)
         {
             if(j>=i)
             arr[i][j]=++k;


         }
    }
 for(j=0;j<5;j++)
    {

         for(i=0;i<5;i++)
         {
             if(j>=i)
             printf("%3d",arr[i][j]);
             if(arr[i][j]==0)
            printf("   ");
         }
         printf("\n");
    }


}




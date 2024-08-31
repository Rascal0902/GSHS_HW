#include<stdio.h>
int main()
{
      int arr[5],i,j,imsi;
      printf("5prime numbers");
      for(i=0;i<5;i++)
        scanf("%d",&arr[i]);
      for(i=0;i<5;i++)
      {
          for(j=i+1;j<5;j++)
          {
              if(arr[i]>arr[j])
                {imsi=arr[i];
                arr[i]=arr[j];
                arr[j]=imsi;
                }
          }
      }
      for(i=0;i<5;i++)
        printf("%3d",arr[i]);
}

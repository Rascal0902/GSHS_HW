/*#include<stdio.h>
int arr[10]={3,6,5,8,7,4,1,2,0,9};
int main()
{
  int i,high=9,max,t;
  while(1)
  {
      max=0;
      for(i=0;i<=high;i++)
      {
          if(arr[max]<=arr[i])
          {
              t=i;
              i=max;
              max=t;
          }
      }
      while(1)
      {
          t=arr[max];
          arr[max]=arr[(max-1)/2];
          arr[(max-1)/2]=t;
          max=(max-1)/2;
          if(max==0)
          {
              break;
          }
      }
      t=arr[0];
      arr[0]=arr[high];
      arr[high]=t;
      high-=1;
      if(high==0)
      {
          break;
      }
   }
  for(i=0;i<=9;i++)
  {
      printf("%d",arr[i]);
  }
  return 0;
}*/
#include<stdio.h>
#include<iostream>
#include<string.h>
using namespace std;
char x[25];
int n;
void dfs(int k)
{
    printf("%c ",x[k-1]);
    if(2*k<=n)
    {
        dfs(2*k);
    }
    if(2*k+1<=n)
    {
        dfs(2*k+1);
    }
}
int main()
{
    scanf("%d",&n);
    scanf("%s",&x);
    dfs(1);
    return 0;
}

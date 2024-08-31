//º´ÇÕ Àý·Ä
/*include<stdio.h>
int arr[20]= {5,2,4,9,8,1,7,15,10,19,17,16,13,14,12,3,6,11,18},brr[20],i,j,l;
int merge(int low,int high)

{
    int mid;
    mid=(low+high)/2;
    if(low<high)
    {
        merge(low,mid);
        merge(mid+1,high);
        mergesort(low,mid,high);
    }
}
void mergesort(int low,int mid,int high)
{
    i=low;
    j=mid+1;
    int k=low;


    while((i<=mid)&&(j<=high))
    {

        if(arr[i]>arr[j])
        {
            brr[k]=arr[j];
            k++;
            j++;
        }
        else
        {
            brr[k]=arr[i];
            k++;
            i++;
        }
        if(j>high)
        {
            for(l=i; l<=mid; l++)
            {
                brr[k++]=arr[l];
            }
            break;
        }
        if(i>mid)
        {
            for(l=j; l<=high; l++)
            {
                brr[k++]=arr[l];
            }
            break;
        }
    }

    for(l=low; l<=high; l++)
    {
        arr[l]=brr[l];
    }
    for(l=low; l<=high; l++)
    {
        brr[l]=0;
    }
    i=0;
    j=0;
}
int main()
{
    int low=0,high=19;
    merge(low,high);
    for(i=0; i<20; i++)
    {
        printf("%d ",arr[i]);
    }
    return 0;
}*/
//ÄüÁ¤·Ä
/*#include<stdio.h>
int a[7]= {4,6,8,1,3,5,2},b[7],c[7];
int pick(int low,int high)
{
    if(high<=low)
    {
        return 1;
    }
    else
    {
        int i,pivot=low,x=0,y=0;
        for(i=low+1; i<=high; i++)
        {
            if(a[i]<=a[pivot])
            {
                b[x]=a[i];
                x++;
            }
            else
            {
                c[y]=a[i];
                y++;
            }
        }
        a[low+x]=a[pivot];
        for(i=low; i<low+x; i++)
        {
            a[i]=b[i-low];
        }
        if(low+x==high)
        {
            pick(low,low+x-1);

        }
        else
        {
            for(i=low+x+1; i<=high; i++)
            {
                a[i]=c[i-(low+1+x)];
            }
            pick(low,low+x-1);
            pick(low+x+1,high);
        }

    }
}
int main()
{
    int i,low=0,high=6;
    pick(low,high);
    for(i=0; i<7; i++)
    {
        printf("%d",a[i]);
    }
    return 0;
}*/
//ÈüÁ¤·Ä

#include<stdio.h>
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
}


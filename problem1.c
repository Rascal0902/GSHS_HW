#include<stdio.h>
int a[101],b[101],n;
int f(int k,int t,int x)
{
    if(k==n)
    {
        a[n-1]=t;
        b[n-1]=x;
        return 1;
    }
    else
    {
        int y;
         y=t;
      t=a[k]*t-b[k]*x;
      x=x*a[k]+y*b[k];
      f(k+1,t,x);
    }
}
int main()
{
    int i;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d %d",&a[i],&b[i]);
    }
    f(1,a[0],b[0]);
    printf("%d %d",a[n-1],b[n-1]);
    return 0;
}


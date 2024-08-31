#include<stdio.h>
int n,a=1;
int pt(int t)
{
    printf("%d ",a);
    a++;
    if(t==1)
    {
        a=1;
        return 1;
    }
    else
    {
        pt(t-1);
    }
}
int f(int k)
{
   pt(k);
   if(k==n)
   {
       return 0;
   }
   else
   {   printf("\n");
       f(k+1);
   }
}
int main()
{

    scanf("%d",&n);
    f(1);
    return 0;
}

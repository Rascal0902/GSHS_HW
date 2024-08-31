#include<stdio.h>
int f(int k,int t)
{
    //printf("%d %d\n",k,t);
    if(k==0)
    {
        return t;
    }
    else
    {
       return f(k/10,t*10+k%10);
    }
}
int main()
{
   int a,i=0;
   scanf("%d",&a);
  // printf("%d",f(a,0));
   while(a!=f(a,0))
   {
       a+=f(a,0);
       i++;
   }
   printf("%d %d",i,a);
   return 0;
}

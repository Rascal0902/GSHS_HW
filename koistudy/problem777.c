#include<stdio.h>
#include<string.h>
int cache[21];
int f(int n)
{
   if(n!=0)
    {int i;
    if(n>1)
    {
       f(n-1);
       printf("\n");
    }
    for(i=0; i<n; i++)
    {
        printf("*");
    }
    if(n>1)
    {printf("\n");
        f(n-1);
    }
    return 1;}
    else{
        return 1;
    }
}
int fc(int n)
{
    cache[0]=0;
    cache[1]=1;
    if(cache[n]!=-1)
    {
        return cache[n];
    }
    else{
      return  cache[n]=2*fc(n-1)+n;
    }

}
int main()
{
    memset(cache,-1,sizeof(cache));
    int n;
    scanf("%d",&n);
    f(n);
    printf("\n%d",fc(n));
    return 0;

}

#include<stdio.h>
int stair(int k)
{
    int s;
    if(k==1)
    {
      return 1;
    }
    else if(k==2)
    {
        return 2;
    }
    else if(k==3)
    {
        return 4;
    }
    else
    {
        s=stair(k-1)+stair(k-2)+stair(k-3);
        return s;
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    printf("%d",stair(n));
    return 0;
}

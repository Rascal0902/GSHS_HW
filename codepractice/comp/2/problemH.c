#include<stdio.h>
int n,k;
int f(int a,int b)
{
    int i;
    if(a==b)
    {
        return 1;
    }
    else if(b==0)
    {
        return 1;
    }
    else
    {
        int s=0;
        for(i=b-1;i<=b;i++)
        {
            s+=f(a-1,i);
        }
        return s;
    }
}
int main()
{
    scanf("%d %d",&n,&k);
    printf("%d",f(n,k));
        return 0;
}

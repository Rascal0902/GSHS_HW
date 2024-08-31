#include<stdio.h>
int n,k;
int f(int s/*위치 */,int k/* 지금 몇개인지*/,int t/* 바로 전게 차있는지*/,int want,int wants)
{
    if(want==0)
    {
        return 1;
    }
    //printf("       %d %d %d %d\n",s,k,t,want);
    if(wants<s)
    {
        return 0;
    }
    if(wants==s)
    {
        if(want<k)
        {
            return 0;
        }
        if(want==k)
        {
            //printf("       %d %d %d %d\n 111111",s,k,t,want);
            return 1;
        }
        if(want>k)
        {
            return 0;
        }
    }

    if(t==1)
    {
        int sum=0;
        sum+=f(s+1,k,0,want,wants);
        return sum;
    }
    else
    {
        int sum=0;
        sum+=f(s+1,k+1,1,want,wants);
        sum+=f(s+1,k,0,want,wants);
        return sum;
    }
}
int main()
{
    scanf("%d %d",&n,&k);
    printf("%d",f(0,0,0,k,n)-f(0,0,0,k-2,n-4));
    return 0;
}

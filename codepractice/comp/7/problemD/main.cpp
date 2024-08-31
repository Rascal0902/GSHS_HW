#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;
int sum=0,n,dp[30];
int dfs(int k)
{
    if(k==0)
    {
        return 1;
    }
    if(k==1)
    {
        dp[1]=1;
        return 1;
    }
    if(k==2)
    {
        dp[2]=2;
        return 2;
    }
    if(dp[k]!=0)
    {
        return dp[k];
    }
    else
    {
        int s=0;
        for(int i=0;i<=k-1;i++)
        {
            s+=dfs(i)*dfs(k-1-i);
        }
        dp[k]=s;
        return s;
    }
}
int main()
{
    scanf("%d",&n);
    printf("%d",dfs(n));
    return 0;
}

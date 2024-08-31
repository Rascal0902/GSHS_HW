/*#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;
int sum=0,dp[205][105],p2[105];
int dfs(int k,int d)
{
    if(d<0)
    {
        return 0;
    }
    if(d==1)
    {
        if(k==1)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    //printf("%d %d\n",k,d);
    if(d*2-1>k)
    {
        dp[k][d]=0;
        return 0;
    }
    if(k>p2[d]-1)
    {
        dp[k][d]=0;
        return 0;
    }
    if(k==p2[d]-1)
    {
        dp[k][d]=1;
        return 1;
    }
    if(d*2-1==k)
    {
        dp[k][d]=p2[d-2];
        return dp[k][d];
    }
    if(dp[k][d]!=0)
    {
        return dp[k][d]%9901;
    }
    else
    {
        int s=0;
        for(int i=1;i<k-1;i++)
        {
            for(int j=1;j<d;j++)
            {
                s+=dfs(i,d-1)*dfs(k-1-i,j)*2%9901;
            }
            s-=dfs(i,d-1)*dfs(k-1-i,d-1)%9901;
            s=s%9901;
        }
        if(s<0)
        {
            s+=9901;
        }
        dp[k][d]=s%9901;
        return s%9901;
    }
}
int main()
{
    int d,n;
    scanf("%d %d",&n,&d);
    p2[0]=1;
    for(int i=1;i<103;i++)
    {
        p2[i]=p2[i-1]*2%9901;
    }
    printf("%d",dfs(n,d)%9901);
    return 0;
}
*/
#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;
int dp[205][105];
int main()
{
    int dt,n;
    scanf("%d %d",&n,&dt);
    for(int k=1; k<=n; k++)
    {
        for(int d=1; d<=dt; d++)
        {
            if(d==1)
            {
                if(k==1)
                {
                    dp[k][d]=1;
                    continue;
                }
                else
                {
                    dp[k][d]=0;
                    continue;
                }
            }
            else
            {
                int s=0;
                for(int i=1; i<k-1; i++)
                {
                    for(int j=1; j<d; j++)
                    {
                        s+=dp[i][d-1]*dp[k-1-i][j]*2%9901;
                    }
                    s-=dp[i][d-1]*dp[k-1-i][d-1]%9901;
                    s=s%9901;
                }
                if(s<0)
                {
                    s+=9901;
                }
                dp[k][d]=s;
            }
        }
    }
    printf("%d",dp[n][dt]%9901);
    return 0;
}

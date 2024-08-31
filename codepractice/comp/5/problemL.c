#include<stdio.h>
long long int n,h[10000000];
long long int max1(long long int a,long long b)
{
    if(a<=b)
    {
        return b;
    }
    else
    {
        return a;
    }
    return 1;
}
long long int min1(long long int a,long long b)
{
    if(a<=b)
    {
        return a;
    }
    else
    {
        return b;
    }
    return 1;
}
long long int histo(long long int low,long long int high)
{
    if(low==high)
    {
        return h[low];
    }
    long long int mid;
    mid=(low+high)/2;
    long long int ans,x,y,height;
    x=mid;
    y=mid+1;
    height=min1(h[x],h[y]);
    ans=max1(histo(low,mid),histo(mid+1,high));
    ans=max1(ans,2*height);
    while((low<x)||(y<high))
    {
        if((y<high)&&((low==x)||(h[x-1]<h[y+1])))
        {
            y++;
            height=min1(height,h[y]);
        }
        else
        {
            x--;
            height=min1(height,h[x]);
        }
        ans=max1(ans,height*(y-x+1));
    }
    return ans;
}
int main()
{
    scanf("%lld",&n);
    for(int i=0;i<=n-1;i++)
    {
        scanf("%lld",&h[i]);
    }
    printf("%lld",histo(0,n-1));
    return 0;
}


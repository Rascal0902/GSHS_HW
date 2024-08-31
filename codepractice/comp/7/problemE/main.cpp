#include<stdio.h>
#include<iostream>
#include<string.h>
using namespace std;
int a[105],n,t=0,ans[105];
void store(int k)
{
    if(2*k<=n)
    {
        store(2*k);
    }
    ans[t]=a[k];
    t++;
    if(2*k+1<=n)
    {
        store(2*k+1);
    }
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    store(1);
    for(int i=0;i<n;i++)
    {
       printf("%d ",ans[i]);
    }
    return 0;
}

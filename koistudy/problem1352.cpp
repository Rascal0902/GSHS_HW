#include<stdio.h>
#include<stdbool.h>
#include<algorithm>
using namespace std;
long long int a[100002];
bool comp(int a,int b)
{
    return a>b;
}
int main()
{
    long long int n,i;
    scanf("%lld",&n);
    for(i=0;i<n;i++)
    {
        scanf("%lld",&a[i]);
    }
    sort(a,a+n,comp);
    for(i=0;i<n;i++)
    {
        printf("%lld ",a[i]);
    }
    return 0;
}

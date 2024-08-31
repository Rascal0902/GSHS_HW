#include<stdio.h>
#include<iostream>
#include<string.h>
using namespace std;
char x[25];
int n;
void dfs(int k)
{
    if(2*k<=n)
    {
        dfs(2*k);
    }
    printf("%c ",x[k-1]);
    if(2*k+1<=n)
    {
        dfs(2*k+1);
    }
}
int main()
{
    scanf("%d",&n);
    scanf("%s",&x);
    dfs(1);
    return 0;
}


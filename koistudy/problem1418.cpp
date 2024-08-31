#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;
int a[30];
int main()
{
    int i,t=1;
    for(i=0;i<28;i++)
    {
        scanf("%d",&a[i]);
    }
        sort(a,a+28);
    for(i=0;i<28;i++)
    {
        if(t!=a[i])
        {
            printf("%d\n",t);
            t++;
        }
        t++;
    }
    if(t==28)
    {
        printf("%d\n%d",28,29);
    }
    if(t==29)
    {
        printf("%d",30);
    }
    return 0;
}

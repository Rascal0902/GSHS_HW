#include<stdio.h>
int n, maxi=0, cut[1000001], cnt=0;
int main()
{
    scanf("%d",&n);
    for (int i=1; i<= n; i++)
    {
        int x;
        scanf("%d", &x);
        if (maxi<x)
            maxi=x;
        if (maxi==i)
            cut[++cnt] = i;
    }
    printf("%d",cnt);
    int j=1;
    for (int i=1;i<=cnt;i++)
    {
        printf("\n%d ",cut[i]-cut[i - 1]);
        while (j<=cut[i])
            printf("%d ",j++);
    }
    return 0;
}

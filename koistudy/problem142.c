#include<stdio.h>
int main()
{
    int n,k,i,a[1000000];
    scanf("%d %d",&n,&k);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(i=0;i<n;i++)
    {
        if(a[i]==k)
        {
            printf("%d",i+1);
            return 0;
        }
        if(a[i]>k)
        {
             printf("-1");
             return 0;
        }
    }

}

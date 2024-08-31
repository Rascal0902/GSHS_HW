#include<stdio.h>
int main()
{
    int k,i;
    char a[8];
    scanf("%d",&k);
    scanf("%s",a);
    for(i=0;i<8;i++)
    {
        a[i]+=k;
    }
    printf("%s",a);
    return 0;
}

#include<stdio.h>
int main()
{
    int n,i;
    char str[80];
    scanf("%d",&n);
    scanf("%s",str);
    for(i=0;i<8;i++)
    {
        str[i]=str[i]+n;
    }
    printf("%s",str);
    return 0;
}

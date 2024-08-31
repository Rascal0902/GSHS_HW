#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    int i,j,a[10002];
    char b[10002];
    for(i=0;~scanf("%d%c",&a[i],&b[i]);i++);
    for(i=0;i<strlen(b);i++)
    {
        for(j=1;j<=a[i];j++)
        {
            printf("%c",b[i]);
        }
    }
    return 0;
}

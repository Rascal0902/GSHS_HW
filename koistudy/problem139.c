#include<stdio.h>
#include<string.h>
int main()
{
    char s[50],i,a[50];
    fgets(s, 50, stdin);
    for(i=0;i<strlen(s);i++)
    {
        a[i]=s[strlen(s)-1-i];
        printf("%c",a[i]);
    }
    return 0;
}

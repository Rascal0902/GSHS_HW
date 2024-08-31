#include<stdio.h>
int main()
{
    char str[5],i;
    scanf("%s",str);
    for(i=0;i<=4;i++)
    {
        str[i]=str[i]-32;
        printf("%c",str[i]);
    }

}

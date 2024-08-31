#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    int i;
    char s[10003];
    scanf("%s",s);
    for(i=0;i<strlen(s);i++)
    {
        if(s[i]=='A')
        {
            printf("A.B");
        }
        else if(s[i]=='B')
        {
            printf("A.B");
        }
        else
        {
            printf("%c",s[i]);
        }
    }
        return 0;
}

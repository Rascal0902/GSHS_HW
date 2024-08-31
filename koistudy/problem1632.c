#include<stdio.h>
#include<string.h>
int main()
{
    int x=0,y=0,i;
    char a[100];
    scanf("%s",a);
    for(i=0;i<strlen(a);i++)
    {
        if(a[i]=='(')
        {
            x++;
        }
        else
        {
            y++;
        }
    }
    if(x==y)
    {
        printf("YES");
    }
    else
    {
        printf("NO");
    }
    return 0;
}

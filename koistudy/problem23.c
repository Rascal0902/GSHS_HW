#include<stdio.h>
int main()
{
    char a[21];
    int i;
    scanf("%s", a);
    for(i=0;a[i]!='\0';i++)
    {

        printf("\'%c\'",a[i]);
        printf("\n");
    }
    return 0;
}

#include<stdio.h>
#include<string.h>
int main()
{
    char a[20]="first",b[20]="second",c[20]="third";
    strcat(a,b);
    strcat(a,c);
    printf("%s",a);
}

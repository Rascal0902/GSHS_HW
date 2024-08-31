#include<stdio.h>
#include<string.h>
int main()
{
    char data[2001];
fgets(data, 2000, stdin);
printf("%s", data);
}

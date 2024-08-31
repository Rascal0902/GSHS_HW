#include<stdio.h>
#include<string.h>
int main()
{
    int i;
    char arr[5];

    scanf("%s",arr);
    for(i=0;i<5;i++)
    {
        arr[i]=arr[i]-32;
    }
    printf("%s",arr);
    return 0;
}


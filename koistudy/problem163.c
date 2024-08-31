#define _CRT_SECURE_NO_WARNINGS // scanf 보안 경고로 인한 컴파일 에러 방지

#include<stdio.h>
#include<string.h>
int main()
{
    int n,i;
    char arr[8];
    scanf("%d",&n);
    scanf("%s",arr);
    for(i=0;i<8;i++)
    {
        arr[i]=arr[i]+n;
    }
    printf("%s",arr);
    return 0;
}

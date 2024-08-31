#include<stdio.h>
int main()
{
    char k=' ';
    int a,b,i,j,cnt=0;
    printf("1일은 무슨 요일 입니까?(0~6)");
    scanf("%d",&a);
    printf("총 몇일입니까?");
    scanf("%d",&b);
    printf("\n\n");
    printf(" 일 월 화 수 목 금 토\n");
    for(i=1;i<=a;i++)
    {
        printf("%3c",k);
        cnt++;
    }

    for(j=1;j<=b;j++)
    {
         printf("%3d",j);
         cnt++;

    if(cnt%7==0)
    {
        printf("\n");
    }
    }
}

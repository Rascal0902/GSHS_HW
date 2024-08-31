#include<stdio.h>
int main()
{
    int a;
    scanf("%d",&a);
    if(a>0)
    {
        if(a<100)
            printf("100보다 작은 수 입니다.");
        else
            printf("100보다 큰 수 입니다.");
    }
}

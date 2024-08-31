#include<stdio.h>
int main()
{
    int n,k;
    char a[100]={0,},b[100];
    while(1)
    {
        printf("현재 문자열:%s \n 1.복사 2.부분복사 3.추가 4.부분추가 5.종료 \n\n 번호를 입력하시요?",a);
        scanf("%d",&n);
        if(n==1)
        {printf("\n문자열 ?");
        scanf("%s",&b);
        strcpy(a,b);
        }
        if(n==2)
        {
          printf("\n문자열 ?");
          scanf("%s",&b);
          printf("수?");
          scanf("%d",&k);
          strncpy(a,b,k);
          }
        if(n==3)
        {printf("\n문자열 ?");
         scanf("%s",&b);
         strcat(a,b);
         }
        if(n==4)
        {printf("\n문자열 ?");
        scanf("%s",b);
        printf("수?");
        scanf("%d",k);
        strncat(a,b,k);
        }
        if(n==5)
            break;
    }
    printf("%s",a);
}

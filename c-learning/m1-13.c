#include<stdio.h>
int main()
{
    int a,n;
    char k;
    while(1){
    printf("\n앞면은 1\n뒷면은 2\n시작하려면 d,종료를 할려면 f을 입력하시오.");
    scanf(" %c",&k);
    if(k=='f'){
        break;
    }
       n=rand()%2+1;
        printf("\n\n동전을 던졌습니다.앞면? 뒷면?  :");
         scanf("%d",&a);
         printf("\n\n사용자 :%d  동전 :%d",a,n);
    if(a==n)
    {
        printf("\n맞추셨습니다.");
    }
    else{
        printf("\n응 아니야 ㅋ");
    }
    printf("\n");
    }
    return 0;
}

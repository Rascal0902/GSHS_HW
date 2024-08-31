#include<stdio.h>
int main()
{
    int score;
    printf("성적을 입력하시오.");
    scanf("%d",&score);

    if(score>90)
      printf("A+");
    else if(score>80)
     printf("B+");
    else if(score>70)
     printf("c+");
    else
        printf("조금더 노력하세요.");

}

#include <stdio.h>
#include<string.h>
int main()
{
    char str[16],str2[16];
    printf("암호를 입력하시오.");
    scanf("%s", str);
    printf("다시 입력하시오");
    scanf("%s", str2);
    if(strcmp(str,str2)==0)
    {
        if(strcmp(str,"abcd")==0)
            printf("환영합니다\n");
        else
            printf("암호가 잘못되었습니다\n");

    }
    else
        printf("두암호가 다릅니다.");


}

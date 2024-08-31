#include<stdio.h>
int main()
{
    int a,n,cnt=0;
    printf("원하는 수를 입력하시오\n");
    scanf("%d\n",&a);
    while(1)
    {
        cnt++;
        scanf("%d",&n);
        if(a==n)
        {
            printf(" h\n");
            break;
        }
        else{
            if(a>n){
                printf(" l\n");
            }
            else{
                printf(" h\n");
            }
        }
    }
    printf("%d번만에 맞추셨군요.",cnt);
    return 0;
}

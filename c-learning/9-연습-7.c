#include<stdio.h>

#include<time.h>
int main()
{
    int i,n;
    printf("\n 난수 발생 srand(100) 사용후 \n");
    srand(1);
    for(i=0;i<=10;i++)
    {
        printf("%7d",rand());
    }
    printf("\n난수발생 srand(time) 사용후 \n");
    srand((unsigned)time(NULL));
    for(i=0;i<=10;i++)
    {
        printf("%7d",rand());
    }

}

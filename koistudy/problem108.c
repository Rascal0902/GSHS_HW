#include<stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    if(n%400==0)
    {
        printf("Leap");
    }
    else
    {
        if(n%4==0)
        {
            if(n%100==0)
            {
               printf("Normal");
            }
            else
            {
                printf("Leap");
            }
        }
        else
        {
            printf("Normal");
        }
    }
    return 0;
}

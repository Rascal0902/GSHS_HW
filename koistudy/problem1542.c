#include<stdio.h>
int main()
{
    int a,b;
    scanf("%d %d",&a,&b);
    if(a==b)
    {
        printf("Draw");
    }
    else
    {
        if(a==0)
        {
            if(b==1)
            {
                printf("Win");
            }
            else
            {
                printf("Lose");
            }
        }
        else if(a==1)
        {
            if(b==2)
            {

               printf("Win");
            }
            else
            {
                 printf("Lose");
            }
        }
        else
        {
            if(b==0)
            {
                printf("Win");
            }
            else
            {
                 printf("Lose");
            }
        }
    }
    return 0;
}

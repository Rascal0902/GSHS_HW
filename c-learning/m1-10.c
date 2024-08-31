#include<stdio.h>
int main()
{
    int a,b,c,cnt=0;
    for(a=1;a<=4;a++)
        printf("   A  B  C  ");
    printf("\n");
    for(a=1;a<=50;a++)
    {
        for(b=1;b<=50;b++)
        {
            for(c=1;c<=50;c++)
            {
                if(a*a+b*b==c*c)
                {
                    cnt++;
                    printf("  %2d %2d %2d  ",a,b,c);
                    if(cnt%4==0) printf("\n");
                }
            }
        }
    }
    printf("\n");
    printf("   total = %d",cnt);
    return 0;
}

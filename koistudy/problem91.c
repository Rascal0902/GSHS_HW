#include<stdio.h>
int main()
{
    int a,b,c,day;
    scanf("%d %d %d",&a,&b,&c);
    for(day=1;day<1000000;day++)
    {
        if(day%a==0)
        {
            if(day%b==0)
            {
                if(day%c==0)
                {
                    printf("%d",day);
                    break;
                }
            }
        }
    }
    return 0;


}

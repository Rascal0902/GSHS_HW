#include<stdio.h>
int main()
{
    int a,b,c,d,i;
    scanf("%d %d\n%d",&a,&b,&c);
    d=b+c;
    for(i=0;; i++)
    {
        if(d>=60)
        {
            a+=1;
            d-=60;
            if(a==24)
            {
                a=0;
            }
        }
            else
            {
                break;
            }
        }
    printf("%d %d",a,d);
    return 0;
}

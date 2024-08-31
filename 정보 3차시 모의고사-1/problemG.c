#include<stdio.h>
int main()
{
    int a,b,c,d,e,f,g,h;
    scanf("%d %d %d %d %d %d %d %d",&a,&b,&c,&d,&e,&f,&g,&h);
    if(((c==e)&&(d==f))||((c==e)&&(b==h))||((a==g)&&(d==f))||((g==a)&&(h==b)))
        {
            printf("point");
        return 0;
        }
        else if((c==e)||(d==f)||(a==g)||(b==h))
                {
                        printf("line");
                        return 0;
                }
                else if((c<e)||(d<f)||(g<a)||(h<b))
                {
                    printf("none");
                    return 0;
                }
                else
                {
                    printf("rectangle");
                    return 0;
                }
}

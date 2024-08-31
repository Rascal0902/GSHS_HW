#include<stdio.h>
int main()
{
    int d,b,c,i,j,a[3],t;
    scanf("%d %d %d",&d,&b,&c);
    a[0]=d;
    a[1]=b;
    a[2]=c;
    for(i=0;i<3;i++)
    {
        for(j=0;j<i;j++)
        {
            if(a[i]<a[j])
            {
                t=a[i];
                a[i]=a[j];
                a[j]=t;
            }
        }
    }

    if(a[0]+a[1]<=a[2])
        {
            printf("Not");
        }
    else
    {
        if((b==c)&&(c==d))
        {
            printf("Regular");
        }
        else
        {
            if((d==b)||(b==c)||(c==d))
            {
                printf("Isosceles");
            }
            else if((b*b+c*c==d*d)||(d*d+c*c==b*b)||(b*b+d*d==c*c))
            {
                printf("Right");
            }

            else
            {
                printf("Normal");
            }
        }
    }

    return 0;

}

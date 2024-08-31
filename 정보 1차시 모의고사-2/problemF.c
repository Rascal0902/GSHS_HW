#include<stdio.h>
int main()
{
    int a,b,c,t,arr[15]={0,31,28,31,30,31,30,31,31,30,31,30,31,31,28},i;
    scanf("%d %d %d",&a,&b,&c);
    if(((a%400)==0)||((a%4==0)&&(a%100!=0)))
    {
        t=1;
    }
    else
    {
        t=0;
    }
    if((b==1)||(b==2))
    {
        for(i=0;; i++)
        {
            if(c>arr[b]+arr[b+1]+t)
            {
                break;
            }
            c+=7;
        }
        c=c-arr[b]-arr[b+1]-t;
        b+=2;
        printf("%d %d %d",a,b,c);
        return 0;
    }
    else
    {
         for(i=0;; i++)
        {
            if(c>arr[b]+arr[b+1]+t)
            {
                break;
            }
            c+=7;
        }
        c=c-arr[b]-arr[b+1];
        if(b==11)
        {
            b=1;
            a+=1;
        }
        else if(b==12)
        {
            b=2;
            a+=1;
        }
        else
        {
            b+=2;
        }
          printf("%d %d %d",a,b,c);
        return 0;
    }

}

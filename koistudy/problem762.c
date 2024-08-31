#include<stdio.h>
int main()
{
    int n,i,m,t=0;
    scanf("%d %d",&i,&m);
    for(n=i;n<=m;n++)
    {
         if(n%400==0)
    {
        t++;
    }
    else
    {
        if(n%4==0)
        {
            if(n%100==0)
            {

            }
            else
            {
                t++;

            }
        }
        else
        {

        }
    }

    }


   printf("%d",t);
   return 0;
}


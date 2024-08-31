#include<stdio.h>
int main()
{
    int i,x,y,z;
    for(i=1;i<=2000;i++)
    {
       x=i/1000 ;
       y=i/100-10*i/1000;
       z=i/1-10*i/10;
            if(i==x*x*x+y*y*y+z*z*z)
        {
            printf("%d\n",i);
        }
    }
    return 0;
}

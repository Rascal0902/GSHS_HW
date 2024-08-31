#include<stdio.h>
int main()
{
    int a[10],i;
    for(i=0;i<10;i++)
        {scanf("%2d",&a[i]);}
    for(i=9;i>=0;i--)
       {
           printf("%2d",a[i]);
       }
    printf(" \n\n\n\n %2d %2d",a[0],   a[9]);
}

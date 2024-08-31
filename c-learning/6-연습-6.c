#include<stdio.h>
int main()
{
       int i;
       scanf("%2d",&i);
       int a[i],j,k,m,n,o;


       for(j=0;j<10;j++)
       {
           scanf("%2d",&a[j]);
       }

       scanf("%2d",&k);
       for(m=0;m<10;m++)
       {
           for(n=m+1;n<10;n++)
           {
               if(a[m]<=a[n])
               {
                   o=a[m];
               a[m]=a[n];
               a[n]=o;
               }
           }
       }
       printf("%2d",a[k-1]);


}

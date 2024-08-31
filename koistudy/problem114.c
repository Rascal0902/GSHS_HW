#include<stdio.h>
int main()
{
    int a[2],b[2],c[4],i,j,t;
    scanf("%d %d",&a[0],&a[1]);
    scanf("%d %d",&b[0],&b[1]);
    if(a[0]>a[1])
    {
        t=a[0];
        a[0]=a[1];
        a[1]=t;
    }
    if(b[0]>b[1])
    {
        t=b[0];
        b[0]=b[1];
        b[1]=t;
    }
    c[0]=a[0];
    c[1]=a[1];
    c[2]=b[0];
    c[3]=b[1];
   for(i=0;i<4;i++)
   {
       for(j=0;j<i;j++)
       {
           if(c[j]>c[i])
           {
               t=c[i];
               c[i]=c[j];
               c[j]=t;
           }
       }
   }

   if(c[0]==a[0])
   {
       if((c[1]==b[0])&&(c[2]==a[1])&&(c[3]==b[1]))
       {
           printf("cross");
       }
       else
       {
           printf("not cross");
       }
   }
   else
   {
       if((c[1]==a[0])&&(c[2]==b[1])&&(c[3]==a[1]))
       {
           printf("cross");
       }
       else
       {
           printf("not cross");
       }
   }
   return 0;
}

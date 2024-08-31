#include<stdio.h>
int n,a[6][2]={0,},i,j,b[6],c[6],sum=0;
int main()
{
    scanf("%d",&n);
    for(i=0;i<6;i++)
    {
        scanf("%d %d",&b[i],&c[i]);
    }
for(i=0;i<5;i++)
   {
       if((b[i]==1)||(b[i]==2))
    {
        if(b[i]==1)
        {a[i+1][0]=a[i][0]+c[i];
        }
        if(b[i]==2)
        {a[i+1][0]=a[i][0]-c[i];
        }
    }
    if((b[i]==3)||(b[i]==4))
    {
         if(b[i]==3)
         {a[i+1][1]=a[i][1]+c[i];}
         if(b[i]==4)
            {a[i+1][1]=a[i][1]-c[i];}
    }
   }
   for(i=0;i<6;i++)
   {
       for(j=0)
   }

}

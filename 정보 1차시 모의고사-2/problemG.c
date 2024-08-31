/*#include<math.h>
#include<stdio.h>
int main()
{
    double a,b,c,d,t;
    long long int k=0;
    scanf("%lf %lf %lf %lf",&a,&b,&c,&d);

    if(c<a)
    {
        t=c;
        c=a;
        a=t;
    }
    if(d<b)
    {
        t=d;
        d=b;
        b=t;
    }
    k+=(long long int)((floor(c)-ceil(a)+1)*(floor(d)-ceil(b)+1));
    printf("%lld",k);
    return 0;
}*/
#include <stdio.h>
void f(double a,double b)
{
   if(a>b)
   {
      double t=a;
      a=b;
      b=t;
   }
}
int h(double a)
{
   int k=(int)a;
   if(k-a==0)return k;
   else if(a>0) return k+1;
   else return k;
}

int u(double a)
{
   int k=(int)a;
   if(k-a==0)return k;
   else if(a>0) return k;
   else return k-1;
}


int main()
{
   double x1,x2,y1,y2;
   int a,b,c,d;
   scanf("%lf %lf %lf %lf",&x1,&y1,&x2,&y2);
   f(x1,x2);
   f(y1,y2);
   printf("%lf %lf %lf %lf\n",x1,y1,x2,y2);
   a=h(x1);
   b=h(y1);
   c=u(x2);
   d=u(y2);
   printf("%d %d %d %d\n",a,b,c,d);
   long long int s=0;
   s=(c-a+1)*(d-b+1);
   printf("%lld",s);
   return 0;
}

/*#include<stdio.h>
#include<iostream>
#include<math.h>
using namespace std;
long long int p,q,w,h,t,x,y;
int main()
{
    scanf("%lld %lld",&w,&h);
    scanf("%lld %lld",&p,&q);
    scanf("%lld",&t);
    x=(p+t)%(2*w);
    y=(q+t)%(2*h);
    printf("%lld %lld",w-abs(w-x),h-abs(h-y));
    return 0;
}*/
/*
#include<stdio.h>
#include<iostream>
using namespace std;
int a[11][11],x=1,y=1;
int main()
{
    for(int i=0;i<10;i++)
    {
        for(int j=0;j<10;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    while(1)
    {
        if(x==9 && y==9)
        {
            a[x][y]=9;
            break;
        }
        if(a[x][y]==0)
        {
            a[x][y]=9;
            if(a[x][y+1]==0|| a[x+1][y]==2)
            {
                ++y;
            }
            else
            {
                if(a[x+1][y]==0 || a[x+1][y]==2 )
                {
                     ++x;
                }
               else
               {
                   break;
               }
            }
        }
        else if(a[x][y]==2)
        {
            a[x][y]=9;
            break;
        }
        else
        {
            break;
        }
    }
    for(int i=0;i<10;i++)
    {
        for(int j=0;j<10;j++)
        {
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
    return 0;
}*/
/*#include<stdio.h>
#include<iostream>
using namespace std;
int a[10],max1=0,max2=0;
int main()
{
    for(int i=0;i<7;i++)
    {
        scanf("%d",&a[i]);
        if(a[i]%2==1 && max1<a[i])
        {
            max1=a[i];
        }
        if(a[i]%2==0 && max2<a[i])
        {
            max2=a[i];
        }
    }
    printf("%d",max1+max2);
    return 0;

}*/
/*#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;
int a,b;
int main()
{
    scanf("%d\n%d",&a,&b);
    for(int i=1;i<=100;i++)
    {
        if( i> abs(a-b) && i < a+b)
        {
            printf("%d",i);
            return 0;
        }
    }
}
#include<stdio.h>
int n;
int main()
{
    scanf("%d",&n);
    printf("%d",(1+n)/2);
}*/
/*#include<stdio.h>
#include<iostream>
using namespace std;
int a,b;
int main()
{
    scanf("%d %d",&a,&b);
    printf("%d",(a*b+1)/2);
}*/



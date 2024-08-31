#include<stdio.h>
int main()
{
    int n,c,x,y,a[20000][2],i,b[100000],t;
    scanf("%d",&n);
    scanf("%d",&c);
    for(i=0;i<c;i++)
    {
        scanf("%d %d",&x,&y);
       if(x==y)
       {
           b[i]=1;
       }
       else if(x>y)
       {
                if(y+n>=2*x-2)
          {
              b[i]=1;
          }
          else
          {
              b[i]=0;
          }
           }

       else
        {


               if(x+n+1>=2*y)
          {
              b[i]=1;
          }
          else
          {
              b[i]=0;
          }

        }

    }
    for(i=0;i<c;i++)
    {
        printf("%d\n",b[i]);
    }
    return 0;
}

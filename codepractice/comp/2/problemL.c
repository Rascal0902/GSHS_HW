#include<stdio.h>
int n,k;
int f(int s1,int s,int x,int y)
{
    //printf("%d %d %d %d\n",s1,s,x,y);
    if(y>n)
    {
       return 0;
    }
    else if(y==n)
    {
        if((x==k)&&((s==0)||(s1==0)))
        {
            return 1;
        }
        else
        {
            return 0;
        }

    }
    else
    {
        int sum=0;
        if(s==0)
        {
            sum+=f(0,1,x+1,y+1);
            sum+=f(0,0,x,y+1);
        }
        else
        {
           if(s1==0)
           {
               sum+=f(1,1,x+1,y+1);
               sum+=f(1,0,x,y+1);
           }
           else
           {
               sum+=f(1,0,x,y+1);
           }
        }
        return sum;
    }
}
int main()
{
    scanf("%d %d",&n,&k);
    printf("%d",f(1,1,1,1)+f(1,0,0,1));
    return 0;
}

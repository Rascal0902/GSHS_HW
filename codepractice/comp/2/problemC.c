#include<stdio.h>
int n;
int f(int k,int a,int b,int c)
{
    if(k==n)
    {
        return 1;
    }
    else if(k>n)
    {
        return 0;
    }
    else
    {
        int i,sum=0;
        for(i=1;i<3;i++)
        {
            if((a==b)&&(b==c)&&(c==i))
            {
                continue;
            }
            else
            {
                sum+=f(k+i,b,c,i);
            }
        }
        return sum;
    }
}
int main()
{
    scanf("%d",&n);
    printf("%d",f(0,0,0,0));
    return 0;
}

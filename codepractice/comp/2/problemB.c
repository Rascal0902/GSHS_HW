#include<stdio.h>
int n;
int check(int k)
{
    if(k==1)
    {
        return -1;
    }
    else
    {
        int i;
        for(i=2; i<k; i++)
        {
            if(k%i==0)
            {
                return -1;
            }
        }
        return 1;
    }

}
int f(int a,int b)
{
    int i;
    if((a==n)&&(b!=0))
    {
        return 1;
    }
    else if((a>n)||((a==n)&&(b==0)))
    {
        return 0;
    }
    else
    {
        int sum=0;
        for(i=1; i<4; i++)
        {
            if(b==0)
            {
                if(check(a+i)==-1)
                { //printf("f(%d,0)\n",a+i,0);
                    sum+=f(a+i,b);

                }
                else
                { //printf("f(%d,%d)\n",a+i,a+i);
                    sum+=f(a+i,a+i);
                }
            }
            if(b!=0)
            {
                 if(check(a+i)==-1)
                { //printf("f(%d,0)\n",a+i,0);
                    sum+=f(a+i,b);
                }
            }
        }
        return sum;
    }

}
int main()
{
    scanf("%d",&n);
    printf("%d",f(0,0));
    return 0;
}


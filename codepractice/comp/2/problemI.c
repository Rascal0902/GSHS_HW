#include<stdio.h>
int m,n;
// k 연속해서 얼마 t 지금 몇개 앉았는지 a 지금 몇번쨰 자리인지
int f(int k,int t,int a)
{
    //printf("%d %d %d\n",k,t,a);
    if(a>m)
    {
       return 0;
    }
    else if(a==m)
    {
        if(t==n)
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
        if(a<m)
        {
            if(t==n)
            {
                return 1;
            }
        }
        int s=0;
        if(k>=2)
        {
            s+=f(1,t+1,a+2);
            s+=f(0,t,a+2);
        }
        else if(k==1)
        {
            s+=f(2,t+1,a+1);
            s+=f(1,t+1,a+2);
            s+=f(0,t,a+2);
        }
        else
        {
            s+=f(1,t+1,a+2);
            s+=f(1,t+1,a+1);
            s+=f(0,t,a+2);
        }
        return s;
    }


}
int main()
{
     scanf("%d %d",&m,&n);
     printf("%d",f(0,0,0));
     return 0;
}

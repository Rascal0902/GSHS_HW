/*#include<stdio.h>
int n;
int a(int k);
int b(int k);
int c(int k);
int main()
{
    scanf("%d",&n);
    printf("%d",a(n));
    return 0;
}
int a(int k)
{
    if(k<=0)
    {
        return 0;
    }
    else if(k==1)
    {
        return 2;
    }
    else if(k==2)
    {
        return 7;
    }
    else
    {
        int s=0;
        s=b(k-1)+c(k-2)+a(k-1)+c(k-3)+b(k-3)+a(k-3);
        return s;
    }

}
int b(int k)
{
    if(k<0)
    {
        return 0;
    }
    else if(k==0)
    {
        return 1;
    }
    else if(k==1)
    {
        return 3;
    }
    else
    {
        int s=0;
        s=a(k)+b(k-1)+c(k-2);
        return s;
    }

}
int c(int k)
{
    if(k<0)
    {
        return 0;
    }
    else if(k==0)
    {
        return 2;
    }
    else if(k==1)
    {
        return 6;
    }
    else
    {
        int s;
        s=b(k)+a(k)+b(k-1);
        return s;
    }

}*/
#include<stdio.h>
long long int M[20],n;
long long int f(long long int a,long long int b,long long int c)
{
    if(a>n+1)
    {
        return 0;
    }
    if(a==n+1)
    {
        return b*M[c];
    }
    long long int s=0;
    s+=f(a+1,b,c+1);
    s+=f(a+2,b,c+2);
    s+=f(a+3,b,c+3);
    s+=f(a+1,M[c]*b,0);
    return s;

}
int main()
{
    long long int i;
    scanf("%lld",&n);
    M[0]=1;
    M[1]=1;
    M[2]=2;
    M[3]=4;
    for(i=4; i<=n; i++)
    {
        M[i]=M[i-1]+M[i-2]+M[i-3];
    }
    printf("%lld",f(1,1,0));
    return 0;
}

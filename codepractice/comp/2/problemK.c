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
        return b*M[c]*M[c];
    }
    long long int s=0;
    s+=f(a+1,b,c+1);
    s+=f(a+3,b,c+3);
    s+=f(a+1,M[c]*M[c]*b,0);
    return s;

}
int main()
{
    long long int i;
    scanf("%lld",&n);
    M[0]=1;
    M[1]=1;
    M[2]=1;
    M[3]=2;
    for(i=4; i<=n; i++)
    {
        M[i]=M[i-1]+M[i-3];
    }
    printf("%lld",f(1,1,0));
    return 0;
}



#include<stdio.h>
long long int cache[1000002], fib[1000002];
long long int fibo(int k)
{
    if(k<0)
    {
        return 0;
    }
   if(cache[k]==(long long int)1)
   {
       return fib[k];
   }
    else
    {
        long long int s;
        s=(fibo(k-1)+fibo(k-2)+fibo(k-3))%1000000007;
        cache[k]=(long long int)1;
        fib[k]=s;
        return s;
    }

}
int main()
{
    int n,k;
    fib[0]=(long long int)1;
    fib[1]=(long long int)1;
    fib[2]=(long long int)2;
    cache[0]=(long long int)1;
    cache[1]=(long long int)1;
    cache[2]=(long long int)1;
    scanf("%d %d",&n,&k);
    printf("%lld",(fibo(k-1)*fibo(n-k-1)+fibo(k-2)*fibo(n-k-1)+fibo(k-1)*fibo(n-k-2))%1000000007);
}

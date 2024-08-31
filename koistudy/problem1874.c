#include <stdio.h>

long long int n;

long long int f(long long int k);

int main()
{
  scanf("%lld", &n);
  printf("%lld\n", f(n));
}
long long int f(long long int k)
{
    int a[100],i,t=0;
    long long int s=0;
    for(i=0;i<100;i++)
    {
        if(k<10)
        {
            a[t]=k;
            break;
        }
        else
        {
            a[t]=k%10;
            t++;
            k=k/10;
        }
    }

    for(i=0;i<=t;i++)
    {
        s=s*10;
        s+=a[i];
    }
    return s;

}

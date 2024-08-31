#include <stdio.h>

int n;

long long int f(int);

int main()
{
  scanf("%d", &n);
  printf("%lld\n", f(n));
}
long long int f(int k)
{
    long long int s,a;
    a=(long long int)k;
    s=(long long int)(a*(a+1))/2;

    return s;

}

#include <stdio.h>

double x;

long long int f(double);

int main()
{
  scanf("%lf", &x);
  printf("%lld\n", f(x));
}
long long int f(double x)
{
  long long int t=(long long int)x;
if(x>=0)
  {if(t<x)
    return t;
  else
    return t;
  }
  else
  {
      if(t>x)
    return t-1;
  else
    return t;
  }
}

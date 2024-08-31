#include <stdio.h>

long long int n, d[110];

long long int f()
{
    int i,t=1;
    long long int sum=d[1];
    for(i=1;i<=n;i++)
    {
        if(d[i]<sum)
        {
            t=i;
            sum=d[i];
        }
    }
    return d[t];
}

int main()
{
  scanf("%d", &n);

  for(int i=1; i<=n; i++)
    scanf("%lld", &d[i]);

  printf("%lld\n", f());
  return 0;
}


#include <stdio.h>

int n, a, b, d[1010];

long long int subsetsum(int c, int e);

int main()
{
  scanf("%d", &n);

  for(int i=1; i<=n; i++)
   {
       scanf("%d", &d[i]);
   }

  scanf("%d%d", &a, &b);

  printf("%lld\n", subsetsum(a, b));
}
long long int subsetsum(int c, int e)
{
    long long int s=0;
    int i;
    for(i=c;i<=e;i++)
    {
        s+=(long long int)d[i];
    }

    return s;
}

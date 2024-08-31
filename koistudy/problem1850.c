#include <stdio.h>

int n, d[110];

int f()
{
    int i,t=0,sum=d[0];
    for(i=0;i<=n;i++)
    {
        if(d[i]>sum)
        {
            t=i;
            sum=d[i];
        }
    }
    return t+1;
}

int main()
{
  scanf("%d", &n);

  for(int i=0; i<n; i++)
    scanf("%d", &d[i]);

  printf("%d\n", f());
  return 0;
}

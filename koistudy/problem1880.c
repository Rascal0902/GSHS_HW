#include <stdio.h>

int a, b;

int gcd(int c, int d);

int main()
{
  scanf("%d %d", &a, &b);
  printf("%d\n", gcd(a, b));
}
int gcd(int c, int d)
{
    int i,k=1;
    for(i=1;i<d;i++)
    {
        if((c%i==0)&&(d%i==0))
        {
            k=i;
        }
    }
    return k;

}

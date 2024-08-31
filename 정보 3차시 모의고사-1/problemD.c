
#include <stdio.h>
int main()
{
    int i,b,a,k=1;
    scanf("%d %d", &a, &b);
    for(i=1;i<=a;i++)
    {
        if((a%i==0)&&(b%i==0))
        {
            k=i;
        }
    }

  printf("%d", k);
}

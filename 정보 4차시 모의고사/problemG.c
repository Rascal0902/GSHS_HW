
#include <stdio.h>

int n;

int f(int k);

int main()
{
  scanf("%d", &n);
  printf("%d\n", f(n));
}
int f(int k)
{
    int a[100],i,t=0;
    int s=0;
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

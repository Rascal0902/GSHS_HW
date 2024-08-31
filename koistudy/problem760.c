#include <stdio.h>
int f(int k);
int main()
{
    int n,a[100],i,j,d[100],t=0,x=0,y=0,z;
    scanf("%d",&n);
  for(i=0;i<n;i++)
  {
      scanf("%d",&a[i]);

  }
  for(j=0;j<n;j++)
  {
      z=a[j]+f(a[j]);

      for(i=0;i<100;i++)
    {
        if(z<10)
        {
            d[t]=z;
            break;
        }
        else
        {
            d[t]=z%10;
            t++;
            z=z/10;
        }
}
x=0;
y=t;
    while(1)
    {
        if(y-x<=0)
        {
            printf("YES\n");
            break;
        }
        else
        {
                if(d[x]==d[y])
                {

                    x++;
                    y--;
                    continue;

            }
            else
                {
                    printf("NO\n");
                    break;
                }
            }
        }
        t=0;
        z=0;
    }
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


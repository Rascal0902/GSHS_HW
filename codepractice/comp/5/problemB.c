#include<stdio.h>
long long int a[1000000],t,i,j,sum=0,end=0,k=0,s[1000000];
void push(long long int k)
{
    s[end]=k;
    end++;
}
void pop()
{
    s[end-1]=0;
    end--;
}
int main()
{
    scanf("%lld",&t);
    for(i=0;i<t;i++)
    {
        scanf("%lld",&a[i]);
    }
   while(1)
    {
        if(end==0)
        {
            push(a[k]);
            k++;
        }
        else if(s[end-1]<=a[k])
        {
            pop();
        }
        else
        {
            sum+=end;
            push(a[k]);
            k++;
        }
        if(k>=t)
        {
            break;
        }

    }
    printf("%lld",sum);
  return 0;
}


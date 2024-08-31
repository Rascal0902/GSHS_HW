#include<stdio.h>
long long int t=0,k,a[10000005];
long long int p(long long int n,long long int st,long long int mi,long long int ed)
{
    if(!n) return 1;
    p(n-1,st,mi,ed);
    if(t<100)
    {
        printf("%lld : %c->%c \n",n,(char)((long long int)('A'-1+st)),(char)('A'+mi-1));
        t++;
    }
    else
    {
        return 1;
    }
    p(n-1,ed,mi,st);
    if(t<100)
    {
        printf("%lld : %c->%c \n",n,(char)('A'-1+mi),(char)('A'+ed-1));
        t++;
    }
    else
    {
        return 1;
    }
    p(n-1,st,mi,ed);
}
int main()
{
    long long int i;
    scanf("%lld", &k);
    if(k<=5)
    {
         p(k,1,3,2);
    }
   else
   {
       p(5,1,3,2);
   }
   a[0]=0;
   for(i=1;i<=k;i++)
   {
        a[i]=(3*a[i-1]+2)%1000000007;
   }
    printf("%lld",a[k]);
    return 0;
}

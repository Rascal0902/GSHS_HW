#include<stdio.h>
#include<string.h>
#include<math.h>
int main()
{
    char s[12];
    int r[12],k,t,j;
    long long int sum=0,m=0,n,i;
    scanf("%s",s);
    k=strlen(s);
    for(i=0;i<(long long int)k;i++)
    {
        r[i]=(int)(s[i]-'0');
    }
    t=(long long int)pow(2,k-1);
    for(i=0;i<t;i++)
    {
        n=(long long int)i;
         m=r[0];
       for(j=1;j<k;j++)
       {
           if(n%2==0)
           {
              m*=10;
              m+=(long long int)r[j];
              //printf("%d\n",m);
              n/=2;

           }
           else
            {
                sum+=m;
                m=0;
                m+=(long long int)r[j];
               // printf("%d %d\n",sum,m);
                n=(n-1)/2;
            }

       }
       sum+=m;
       m=(long long int)0;
    }
    printf("%lld",sum);


}

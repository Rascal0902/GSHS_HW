/*<time limit>
#include<stdio.h>
#include<string.h>
int t,c[100000000]= {0,};
int cache[100000000];
int cyc(int k,int x)
{
    if(cache[k]!=-1)
    {

        c[x]+=c[k];
        return 1;
    }
    else
    {
        if(k==1)
        {cache[x]=1;
            c[x]++;
            return 1;
        }
        else
        {
            if(k%2==1)
            {

                c[x]++;
                return cyc(3*k+1,x);
            }
            else
            {

                c[x]++;
                return cyc(k/2,x);
            }
        }
    }
}
int main()
{
    int a,b,i,j,imsi;
    memset(cache,-1,sizeof(cache));
    scanf("%d %d",&a,&b);
    for(i=a; i<=b; i++)
    {
        cyc(i,i);
    }
    for(i=a; i<=b; i++)
    {
        for(j=a; j<i; j++)
        {
            if(c[i]>=c[j])
            {
                imsi=c[i];
                c[i]=c[j];
                c[j]=imsi;
            }
        }
    }
    printf("%d",c[a]);
    return 0;
}
#include<stdio.h>
int main()
{
    int i,j,a,b,c[100000],imsi;
    scanf("%d %d",&a,&b);
    c[1]=1;
    for(i=a;i<=b;i++)
    {
        if(i%2==1)
        {
            c[i]=c[(i-1)/3]+1;
        }
        else
        {
            c[i]=c[i/2]+1;
        }
    }
    for(i=a; i<=b; i++)
    {
        for(j=a; j<i; j++)
        {
            if(c[i]>=c[j])
            {
                imsi=c[i];
                c[i]=c[j];
                c[j]=imsi;
            }
        }
    }
    printf("%d",c[a]);
    return 0;
}
*/
#include<stdio.h>
long long int c[100000000];
int cyc(int k,int x)
{
    if(c[k]!=0)
    {
       c[x]+=c[k];
        return 1;
    }
    else
    {
        if(k==1)
        {
            c[x]++;
            return 1;
        }
        else
        {
            if(k%2==1)
            {
                c[x]++;
                return cyc(3*k+1,x);
            }
            else
            {

                c[x]++;
                return cyc(k/2,x);
            }
        }
    }
}
int main()
{
    int a,b,i,j;
    long long int max;
    scanf("%d %d",&a,&b);
    for(i=a; i<=b; i++)
    {
        cyc(i,i);
        if(i==a)
        {
            max=c[a];
        }
        if((i>a)&&(c[i]>max))
        {
            max=c[i];
        }
    }
    printf("%lld",max);
    return 0;
}








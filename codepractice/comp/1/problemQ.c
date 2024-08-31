#include<stdio.h>
long long int map[15][15],a,d,c,m,n,s,money=100000000,b[20],end=0,max=0,v[15];
void push(long long int k)
{
    b[end]=k;
    end++;
}
void pop()
{
    b[end-1]=0;
    end--;
}
long long int dfs(long long int k)
{
    long long int i;
    if(k==m)
    {
        long long int sum=0;
        for(i=0; i<end; i++)
        {
            if(i==k)
            {
                continue;
            }
            sum+=b[i];
            if(max<=b[i])
            {
                max=b[i];
            }
            //printf("%d ",b[i]);
        }
        //printf("\n");
       // printf("money=%d max=%d",(int)(sum-max/2.0),max);
        if((long long int)(sum-max/2.0)<=money)
        {
            money=(long long int)(sum-max/2.0);
            max=0;
        }
         max=0;
    }
    else
    {
        for(i=1; i<=m; i++)
        {
            //printf("   %d %d %d %d\n",k,i,map[k][i],v[i]);
            if((map[k][i]!=0)&&(v[i]==0))
            {
                push(map[k][i]);
                v[i]=1;
                dfs(i);
                v[i]=0;
                pop();
            }
        }
    }

}
int main()
{
    long long int i;
    scanf("%lld %lld",&m,&n);
    for(i=0;i<n;i++)
    {
        scanf("%lld %lld %lld",&a,&d,&c);
        if((map[a][d]!=0)||(map[d][a]!=0))
        {
            continue;
        }
        else
        {
              map[a][d]=c;
        map[d][a]=c;
        }

    }
    v[1]=1;
    dfs(1);
    if(money==100000000)
    {
        printf("-1");

    }
    else
    {
         printf("%lld",money);
    }

    return 0;
}

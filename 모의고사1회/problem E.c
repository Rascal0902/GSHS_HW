#include <stdio.h>
#include<string.h>
int n,k,i,j,cache[31];
int fibo(int k)
{

    if(cache[k]!= -1)
    {
        return cache[k];
    }

    return cache[k]=(fibo(k-2)+fibo(k-1));
}
int main()
{
    scanf("%d %d",&k,&n);
    memset(cache,-1,sizeof(cache));
    cache[1]=1;
    cache[2]=1;
    for(i=1;fibo(k-2)*i<=n;i++)
    {
        for(j=1;fibo(k-1)*j<=n;j++)
        {
            if(fibo(k-1)*j+fibo(k-2)*i==n)
            {
                printf("%d\n%d \n\n",i,j);
                return 0;
            }
        }
    }
}


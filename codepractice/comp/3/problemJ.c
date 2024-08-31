/*#include<stdio.h>
long long int N,K,end=0,a[10000],v1[10000],v2[10000],f[10000];
void push(int k)
{
    a[end]=k;
    end++;
}
void pop()
{
    a[end-1]=0;
    end--;
}
long long int check(long long int X,long long int Y,long long int first)
{
    printf("X=%lld Y=%lld",X,Y);
    printf("\n\n");
    if((X==K)&&(Y==0)&&(first!=0))
    {
        return 1;
    }
    long long int i=0,stopx=0,stopy=0,stopi=0,go=0;
    for(i=X-1;i>=1;i--)
    {
        if(v1[i]==1)
        {
            stopi=i;
            stopx=stopi;
            stopy=X-stopi-1;
            go=1;
            break;
        }
    }
    printf("i=%d\n",i);
    if(i==0)
    {
        stopi=0;
        stopx=0;
        stopy=X;
    }
    f[stopx+stopy]=1;
    push(X-stopi);
    printf("stopx=%lld stopy=%lld push=%lld\n",stopx,stopy,X-stopi);
    if(go==1)
    {
        goto one;
    }
    long long int s=stopx+stopy;
    for(i=s+1;i<=N-1;i++)
    {
        if(f[i]==1)
        {
            stopi=i;
            stopx=i-s+stopx;
            break;
        }
    }
    printf("i=%d\n",i);
    if(i==N)
    {
        stopi=N;
        stopx=N-stopy;
    }
    v2[stopy]=1;
    push(stopi-s);
    one:
    printf("stopx=%lld stopy=%lld push=%lld\n",stopx,stopy,stopi-s);
     long long int s2=stopy;
    for(i=stopy-1;i>=1;i--)
    {
        if(v1[i]==1)
        {
            stopi=i;
            stopy=stopi;
        }
    }
    printf("i=%d\n",i);
     if(i==0)
    {
        stopi=0;
        stopy=0;
    }
    v1[stopx]=1;
    push(s2-stopy);
    printf("stopx=%lld stopy=%lld push=%lld\n",stopx,stopy,s2-stopy);
    check(stopx,stopy,1);

}
int main()
{
    scanf("%lld %lld",&N,&K);
    check(K,0,0);
    long long int i,sum=0;
    for(i=0;i<end;i++)
    {
        sum+=a[i];
    }
    printf("%lld",sum);
    return 0;
}*/
/*#include<stdio.h>
long long int N,K,end=0,a[10000],v1[10000],v2[10000],f[10000],stopx,stopy,go;
void push(int k)
{
    a[end]=k;
    end++;
}
void pop()
{
    a[end-1]=0;
    end--;
}
void v1(long long int X,long long int Y)
{
    long long int i=0,stopx=0,stopy=0,stopi=0,go=0;
    for(i=X-1;i>=1;i--)
    {
        if(v1[i]==1)
        {
            stopi=i;
            stopx=stopi;
            stopy=X-stopi-1;
            go=1;
            break;
        }
    }
    printf("i=%d\n",i);
    if(i==0)
    {
        stopi=0;
        stopx=0;
        stopy=X;
    }
    f[stopx+stopy]=1;
    push(X-stopi);
}
void v2(long long int X,long long int Y,long long int stopx,long long int stopy,long long int go)
{

}
void v1(long long int X,long long int Y,long long int stopx,long long int stopy,long long int go)
{

}
long long int check(long long int X,long long int Y,long long int first)
{
    printf("X=%lld Y=%lld",X,Y);
    printf("\n\n");
    if((X==K)&&(Y==0)&&(first!=0))
    {
        return 1;
    }
}
int main()
{
    scanf("%lld %lld",&N,&K);
    check(K,0,0);
    long long int i,sum=0;
    for(i=0;i<end;i++)
    {
        sum+=a[i];
    }
    printf("%lld",sum);
    return 0;
}*/
#include<stdio.h>
long long int N,X;
long long int f(long long int X,long long int Y)
{
    if(X>Y)
    {
        long long int temp;
        temp=X;
        X=Y;
        Y=temp;

    }
    if((X==0)||(Y==0))
    {
        return -Y;
    }
    else
    {
        long long int sum=0;
        sum=(Y/X)*2*X;
        sum+=f(Y%X,X);
        return sum;
    }
}
int main()
{
    scanf("%lld %lld",&N,&X);
    printf("%lld",f(X,N-X)+N);
    return 0;
}

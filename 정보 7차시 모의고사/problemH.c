 #include<stdio.h>
long long int cache[1001][1001];
long long int s(int x,int y)
{
    if(x<y)
    {
        cache[x][y]=0;
        return 0;
    }
    if(x==y)
    {
        cache[x][y]=1;
        return cache[x][y];
    }
    if(y==1)
    {
        cache[x][y]=1;
        return cache[x][y];
    }
    if(cache[x][y]!=0)
    {
        return cache[x][y];
    }
    else
    {
        cache[x][y]=(s(x-1,y-1)+y*s(x-1,y))%1000000007;
        return cache[x][y];
    }
}
int main()
{
    int n,r;
    scanf("%d %d",&n,&r);
    printf("%lld",s(n,r));
    return 0;
}

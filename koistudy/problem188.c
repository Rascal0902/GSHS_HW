

    #include<stdio.h>
int main()
{

    long long int i,n,s=0;
    scanf("%lld",&n);

    for(i=1;i<=n/6;i++)
    {

        if(n%i==0)
        {
            s+=i;

        }
    }
    s+=n;
    if(n%2==0)
    {
        s+=n/2;
       if(n%4==0)
    {
        s+=n/4;
    }
    }if(n%3==0)
    {
        s+=n/3;
    }
    if(n%5==0)
    {
        s+=n/5;
    }

      printf("%lld",s);
}



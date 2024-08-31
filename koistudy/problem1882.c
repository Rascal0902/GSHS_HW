/*theory
#include<stdio.h>
long long int k=1;
long long int pow(int a,int n);
int main()
{
    int a, n;
    long long int pow(int a, int n);
    scanf("%d %d", &a,&n);
    printf("%lld\n", pow(a, n));

    return 0;

}
long long int pow(int a,int n)
{
    long long int k=1;
    k*=a;
    n--;
    if(n==0)
        return k;
    else
        return pow(a,n);
}*/
//answer
long long int pow(int a,int n)
{
    long long int i,k=1;
    if(n%2==0)
    {
        for(i=1; i<=n/2; i++)
        {
            k*=a*a;
        }
    }
    if(n%2==1)
    {
        k*=a;
        for(i=1; i<=(n-1)/2; i++)
        {
            k*=a*a;
        }
    }

    return k;
}

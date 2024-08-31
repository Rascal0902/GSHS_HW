#include<stdio.h>
double arcfs(int k)
{
    int i,fac=1;
    double arcf;
    for(i=1; i<=k; i++)
    {
        fac*=i;
    }
    arcf=(double)1/fac;
         return arcf;
}
int main()
{
    int i;
    double e=1;
    for(i=1; i<=10; i++)
    {
        e+=arcfs(i);
    }
    printf("%lf",e);
    return 0;
}

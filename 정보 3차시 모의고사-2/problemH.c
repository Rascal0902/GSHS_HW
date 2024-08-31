#include<stdio.h>
long long int power(int k,int a)
{
    long long int sum=1,i;
    for(i=0;i<a;i++)
    {
        sum*=k;
    }
    return sum;

}
int main()
{
    int k,i,j;
    double t;
    scanf("%d",&k);
    if(((k%2)==0)||((k%5)==0))
    {
        printf("-1");
        return 0;
    }
    else
    {

        for(i=1;;i++)
        {
            if((power(10,i)-1)%(9*k)==0)
            {
                for(j=1;j<=i;j++)
                {
                    printf("1");
                }
                break;
            }

        }
    }
}

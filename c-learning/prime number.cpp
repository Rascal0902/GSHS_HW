#include<stdio.h>
#include<iostream>
using namespace std;
int main()
{
    int n,i,j,sum=0,k=0,a;
    cin >> n;
    printf("\n\n");
    for(j=1; j<=n; j++)
    {
        for(i=2; i<=j; i++)
        {
            if(j%i==0)
            {
                a=i;
                break;
            }
        }
        if(a==j)
        {
            sum++;
            k=j;
        }
    }
    printf("sum=%d\n",sum);
    if(k==0)
    {
        printf("1부터 %d까지 소수가 없습니다.",n);
    }
    else
    {
        printf("k=%d",k);
    }
}

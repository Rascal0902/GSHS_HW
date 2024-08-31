#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
int chk1(long long int k)
{
    int sum=0,i;
    for(i=0;i<23;i++)
    {
        sum+=k%2;
        k=k/2;
    }
     return sum;
}
int main()
{
    int m,n,t,chk,ch, arr[24];
    long long int i,k,j,w;
    char str[23];
    scanf("%d %d",&m,&n);
    scanf("%s",str);
    t=strlen(str);
    k=(long long int)pow(2,t);
    for(i=k-1;i>=0;i--)
    {
        w=i;
        ch=chk1(i);
        if(ch!=t-n)
        {
            continue;
        }
        else
        {
            for(j=t-1; j>=0; j--)
            {
                arr[j]=w%2;
                w=w/2;
            }
            for(j=0; j<t; j++)
            {
                if(arr[j]%2==1)
                {
                    printf("%c",str[j]);

                }
            }
            printf("\n");
        }
    }
    return 0;


}

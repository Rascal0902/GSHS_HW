#include<stdio.h>
int main()
{
    int n,i,k;
    char z[10004];
    scanf("%d",&n);
    scanf("%s",z);
    for(i=0;i<n;i++)
    {
        k=1;
        while(1)
        {
            if((z[i]==z[i+1])&&(i+1<n))
            {
                k+=1;
                i+=1;
            }
            else
            {
                break;
            }
        }
        printf("%d%c",k,z[i]);
    }
    return 0;
}



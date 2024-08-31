#include<stdio.h>
int main()
{
    int n,i,k,t=0,w,j;
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
        for(j=1;j<6;j++)
        {
            if(k/10==0)
            {
                t+=j+1;
                break;
            }
            else
            {
                k=k/10;
                continue;
            }
        }

    }
    for(i=n;i>=1;i--)
    {
        if((n%i==0)&&(t%i==0))
           {
               w=i;
               break;
           }
    }
    printf("%d/%d",t/w,n/w);
    return 0;
}




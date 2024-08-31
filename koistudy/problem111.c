#include<stdio.h>
int main()
{
    int a,b,c,d[3],i,j,t;
    scanf("%d %d %d",&a,&b,&c);
    if((a==b)||(b==c)||(c==a))
    {
        printf("Impossible");
    }
    else
    {
        d[0]=a;
        d[1]=b;
        d[2]=c;
        for(i=0;i<3;i++)
        {
            for(j=0;j<=i;j++)
            {
                if(d[i]<d[j])
                {
                    t=d[i];
                    d[i]=d[j];
                    d[j]=t;
                }
            }
        }
        printf("%d %d %d",d[0],d[1],d[2]);
        return 0;
    }
}

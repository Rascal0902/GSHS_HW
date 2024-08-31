#include<stdio.h>
int main()
{
    int M,N,i,j,a[1000],k=0,x=0,cnt=0;
    char c;
    while(1)
    {
        printf("M,N ? ");
        scanf("%d %d",&M,&N);
        for(i=M; i<=N; i++)
        {
            for(j=2; j<i; j++)
            {
                if(i%j!=0)
                {
                    x++;
                }

            }
            if(x==i-2)
            {
                a[k]=i;
                k++;
            }
            x=0;
        }
        for(i=0; i<k; i++)
        {
            printf("%d ",a[i]);
            cnt++;
            if(cnt%5==0)
            {
                printf("\n");
            }
        }
        printf("\n");
        printf("계속할까요?(Y/N) ");
        scanf(" %c",&c);
        if(c=='N')
        {
            break;
        }
        printf("\n\n");
    }
    return 0;
}

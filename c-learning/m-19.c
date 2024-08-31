#include<stdio.h>
int main()
{
    int N,i,j,a[1000],k=0,x=0,w=0;
    char c;
    printf("N ? ");
    scanf("%d",&N);
    for(i=2; i<=N; i++)
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
    for(i=1; i<k; i++)
    {
        if(a[i]-a[i-1]==2)
        {
            printf("%3d %3d\n",a[i-1],a[i]);
            w++;
        }

    }
    printf("½ÖµÕÀÌ ¼Ò¼ö´Â %d½Ö ÀÔ´Ï´Ù.",w);
    return 0;
}

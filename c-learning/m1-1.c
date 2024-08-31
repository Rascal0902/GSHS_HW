#include<stdio.h>
int main()
{
    int i,j,a[5][9]={0,},k=1;
    char x=' ';
    for(j=0;j<=4;j++)
    {
        for(i=j;i<=8-j;i++)
        {
          a[j][i]=k;
          k++;
        }
    }
    for(j=0;j<=4;j++)
    {
        for(i=0;i<=8;i++)
        {
            if(a[j][i]==0)
                printf("   ");
            else
          printf("%3d",a[j][i]);
        }
        printf("\n");
    }
    return 0;
}

#include<stdio.h>
int main()
{
    int a[4][8],i;
    for(i=0;i<4;i++)
    {
        scanf("%d %d %d %d %d %d %d %d",&a[i][0],&a[i][1],&a[i][2],&a[i][3],&a[i][4],&a[i][5],&a[i][6],&a[i][7]);
    }

    for(i=0;i<4;i++)
    {
       if((a[i][2]<a[i][4])||(a[i][3]<a[i][5]))
        {
              printf("d");
        }
        else
            {
                if((a[i][2]==a[i][4])&&(a[i][3]==a[i][5]))
                {
                    printf("c");
                }
                else
                    {
                        if((a[i][2]==a[i][4])||(a[i][3]==a[i][5]))
                        {
                            printf("b");
                        }
                        else
                            {
                                printf("a");
                            }

                    }
            }
            printf("\n");
    }
     return 0;
}

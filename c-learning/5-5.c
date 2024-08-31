#include<stdio.h>
int main()
{
    int i,cnt=0;
    for( i='A';i<='Z';i++)
    {
        cnt++;
        printf("%c",i);

        if(cnt%5==0)
            printf("\n");
    }
}

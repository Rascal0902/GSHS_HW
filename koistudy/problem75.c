#include<stdio.h>
int main()
{
    char a,k='a';
    scanf("%c",&a);
    while(1)
    {
        printf("%c ",k);
        if(k==a)
          {
               break;
          }
        k++;

    }
    return 0;
}

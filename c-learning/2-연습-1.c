#include<stdio.h>
int main()
{
    int i=3, j=5, k=10, m, n;
    m= i * j;
    n= k * m;

    printf("%d * %d = %05d \n", i, j,m);
    printf("%d * %d = %d", k, m, n);
}

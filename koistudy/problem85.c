#include<stdio.h>
int main()
{
    int h,b,c;
    float mb;
    scanf("%d %d %d",&h,&b,&c);
    mb=(float)h*b*c/(8*1024*1024);
    printf("%.2f MB",mb);
    return 0;
}


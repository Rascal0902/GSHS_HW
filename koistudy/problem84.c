#include<stdio.h>
int main()
{
    int h,b,c,s;
    float mb;
    scanf("%d %d %d %d",&h,&b,&c,&s);
    mb=(float)h*b*c*s/(8*1024*1024);
    printf("%.1f MB",mb);
    return 0;
}

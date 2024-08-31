#include<stdio.h>
int sw(int a,int b)
{
    int temp;
    temp=a; a=b; b=temp;

}
int main()
{
    int a=10,b=20;
    printf("호출전: a=%d",a);
    sw(a,b);
    printf("호출루: a=%d",a);
}

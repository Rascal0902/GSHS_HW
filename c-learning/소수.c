#include<stdio.h>
int main()
{
    int a,i,j,k,cnt1=0;
    printf("정수 하나를 입력하시오");
    scanf("%d", &a);
    j=a,k=a+1;
    printf("\n\n 약수");
    printf("\n%3d\n",1);
     for(i=2;i<a;i++)
    {
        if(a%i==0)
        {printf("%3d\n",i);
        cnt1++;
        j*=i;
        k+=i;
        }
    }
    printf("%3d \n",a);
    if(cnt1!=0)
    {
       printf("\n 약수의 개수=%d",cnt1+2);
       printf("\n\n 약수의 합=%d",k);
       printf("\n\n 약수의 곱=%d",j);
       printf("\n\n 소수가 아닙니다.");
    }
    if(cnt1==0)
    {
       printf("\n 약수의 개수=%d",2);
       printf("\n 약수의 합=%d",k);
       printf("\n 약수의 곱=%d",j);
       printf("\n it's prime number.");
    }
    printf("\n\n\n\n 약수인 수들의 배열");
    int y,cnt2=0;
    char x=' ';
    printf("\n");
    for(y=1;y<=a;y++)
    {
        if(a%y==0)
        {
          printf("%10d",y);
          cnt2+=10;
        }
        if(a%y!=0)
        {
          printf("%10c",x);
          cnt2+=10;
        }
        if(cnt2%100==0)
        {
            printf("\n");
        }
    }
   printf("\n\n\n\n 서로소인 수들의 배열 ");
    int z,cnt3=0;
    char w=' ';
    printf("\n");
    for(z=1;z<=a;z++)
    {
        if(a%z==0)
        {
          printf("%10c",w);
          cnt3+=10;
        }
        if(a%z!=0)
        {
          printf("%10d",z);
          cnt3+=10;
        }
        if(cnt3%100==0)
        {
            printf("\n");
        }
    }
    printf("\n\n\n");

}

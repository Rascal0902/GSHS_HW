//버블정렬
//앞뒤 바꿔 다시 스켄
/*#include<stdio.h>
int main()
{
    int i,j,t,a[10]={ 2, 10, 9, 5, 6, 3, 4, 1, 7, 8};
    for(j=0; j<10; j++)
    {
        for(i=0; i<9; i++)
        {
            if(a[i+1]>a[i])
            {
                t=a[i+1];
                a[i+1]=a[i];
                a[i]=t;

            }
        }

    }

}*/
//삽입정렬
//크기 순에 모순되면 그곳에서 거꾸로 가 삽입
/*#include<stdio.h>
int main()
{
    int i,j,t,a[10]={ 2, 10, 9, 5, 6, 3, 4, 1, 7, 8};
    for(i=0; i<10; i++)
    {
        if(a[i]<a[i+1])
        {
            for(j=i+1; j>=1; j--)
            {
                if(a[j-1]<a[j])
                {
                    t=a[j];
                    a[j]=a[j-1];
                    a[j-1]=t;
                }
                else
                {
                    break;
                }

            }
        }
    }
    for(i=0; i<10; i++)
    {
        printf(" %d",a[i]);
    }
    return 0;
}*/
//선택정렬
//작은거 부터 차례로
/*#include<stdio.h>
int main()
{
     int i,j,max=10,a[10]={ 2, 10, 9, 5, 6, 3, 4, 1, 7, 8};
     for(i=0;i<10;i++)
     {
       for(j=i;j<10;j++)
       {
          if(a[j]>=max)
          {
              max=a[j];
              a[j]=a[i];
              a[i]=max;
          }
       }
       max=0;
    }
      for(i=0; i<10; i++)
    {
        printf(" %d",a[i]);
    }
    return 0;
}*/

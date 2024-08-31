//주사위 게임
#include<stdio.h>
int main()
{
    int a[3],i,j,k;
    scanf("%d %d %d",&a[0],&a[1],&a[2]);
    for(i=0;i<3;i++)
    {
        for(j=0;j<i;j++)
        {
            if(a[i]<=a[j])
            {
                k=a[i],a[i]=a[j],a[j]=k;
            }
        }
    }
    if(a[0]==a[1])
    {
         if(a[1]==a[2])
    {
        printf("%d",10000+a[0]*1000);
    }
    else
    {
        printf("%d",1000+a[0]*100);
    }
    }
    else
    {
      if(a[1]==a[2])
    {
         printf("%d",1000+a[1]*100);
    }
    else
    {
        printf("%d",a[2]*100);
    }

    }
    return 0;

}

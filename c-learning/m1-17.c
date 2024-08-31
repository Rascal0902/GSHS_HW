#include<stdio.h>
int main()
{
    int a[100],b[100],c[100],d[100],i,k=0,j=0;
    printf("Data of Set A :\n");
    for(i=1;i<100;i++){
       scanf("%d",&a[i]);
       if(a[i]==-1){
        break;
       }
       k++;
    }
     printf("Data of Set B :\n");
    for(i=1;i<100;i++){
       scanf("%d",&b[i]);
        if(b[i]==-1){
        break;
       }
       j++;
    }

return 0;
}

#include<stdio.h>
int main()
{
    int a[9],b[9],n,k;
    for(int i=0;i<10;i++){
        printf("Enter..: ");
        scanf("%d",&a[i]);
    }
    for(int i=0;i<10;i++){
        b[i]=i;
        for(int j=0;j<i;j++){
            if(a[j]<=a[i])
            {
                k=b[i];
                b[i]=b[j];
                b[j]=k;
            }
        }
    }
    printf("배열의 내용 :");
    for(int i=0;i<10;i++){
        printf("%d",a[i]);
        if(i!=9){
                printf(", ");
        }
        else{
            break;
        }
    }
    printf("\n");
    for(int i=0;i<10;i++){
        printf("%d(%d)",a[i],b[i]);
        if(i!=9){
                printf(", ");
        }
        else{
            break;
        }
    }
    return 0;
}

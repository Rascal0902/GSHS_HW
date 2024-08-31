#include<stdio.h>
int main()
{
    int i,j,n,k=1,a[100][100];
    scanf("%d",&n);
    for(i=0;i<n;i++){
       if(i%2==1){
        for(j=0;j<n;j++){
            a[i][j]=k;
            k++;
        }
       }
       else{
        for(j=n-1;j>=0;j--){
            a[i][j]=k;
            k++;
        }
       }
    }
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
    return 0;
}

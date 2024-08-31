#include<stdio.h>
int main()
{
    int i,j,n,k=1,a[100][100]={0};
    scanf("%d",&n);
    for(j=0;j<n;j++){
       if(j%2==1){
        for(i=n-1;i>=0;i--){
            a[i][j]=k;
            k++;
        }
       }
       else{
        for(i=0;i<n;i++){
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

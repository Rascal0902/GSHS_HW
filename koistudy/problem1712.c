#include<stdio.h>
int main()
{
    int n,a[100][100],i,j,k=1;
    scanf("%d",&n);
    for(j=0;j<n;j++){
        for(i=n-1;i>=0;i--){
            a[i][j]=k++;
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

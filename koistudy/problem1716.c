#include<stdio.h>
int main()
{
    int n,m,a[100][100],i,j,k=1;
    scanf("%d %d",&n,&m);
    for(j=m-1;j>=0;j--){
        for(i=0;i<n;i++){
            a[i][j]=k++;
        }
    }
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
    return 0;
}

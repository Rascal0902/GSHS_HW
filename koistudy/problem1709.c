#include<stdio.h>
int main()
{
    int n,a[100][100],k=1;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            a[i][j]=k++;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf(" %d",a[i][j]);
        }
        printf("\n");
    }
    return 0;
}

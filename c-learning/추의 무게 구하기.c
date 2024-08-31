#include<stdio.h>
int main()
{
    int a[100],b[100],c[100],i,j,k,n,o=0;
    scanf("%d",&n);
    for(i=0;i<=100;i++){
        for(j=0;j<=100;j++){
            for(k=0;k<=100;k++){
                if(2*i+3*j+5*k==n){
                    a[o]=i,b[o]=j,c[o]=k;
                    o++;
                }
            }
        }
    }
    printf("2g   3g   5g\n");
    for(i=0;i<=o;i++){
        printf("%d   %d   %d\n",a[i],b[i],c[i]);
    }
    return 0;
}

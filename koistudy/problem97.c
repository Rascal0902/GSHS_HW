#include<stdio.h>
int main()
{
    int m[1000][1000],n,l,i,j,d,x,y,h,w;
    scanf("%d %d",&h,&w);
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d %d %d %d",&l,&d,&x,&y);
        if(d==0){
            for(j=0;j<l;j++){
                m[x][y+j]=1;
            }
        }
        else{
            for(j=0;j<l;j++)
            {
                m[x+j][y]=1;
            }
        }
    }
    for(i=1;i<=h;i++){
        for(j=1;j<=w;j++){
            printf("%d ",m[i][j]);
        }
        printf("\n");
    }

}

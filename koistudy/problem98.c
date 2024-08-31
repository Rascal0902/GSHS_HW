#include<stdio.h>
int m[9][9],x,y,i,j;
int main()
{
    for(i=0;i<10;i++){
        for(j=0;j<10;j++){
            scanf("%d",&m[i][j]);

        }
    }
     x=1;
     y=1;
    while(1){
      if((x==9)||(y==9)==1)
            break;
      else{ if(m[x][y]==2){
            m[x][y]=9;
           break;
        }
       if(m[x][y+1]!=1){
            m[x][y]=9;
          y++;
       }
        else if(m[x+1][y]!=1){
           m[x][y]=9;
            x++; }
        else{
           m[x][y]=9;
       break;}}
   }

    for(i=0;i<10;i++){
        for(j=0;j<10;j++){
            printf("%d ",m[i][j]);
        }
        printf("\n");
    }
}

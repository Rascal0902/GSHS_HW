#include<stdio.h>
int n,m,map[101][101],v[101],a,b,i;
void dfs(int k){
   printf("%d ",k);
   v[k]=1;
   for(int i=1;i<=n;i++){
      if(map[i][k]==1&&!v[i]){
         dfs(i);
      }
   }
}
main(){
   scanf("%d%d",&n,&m);
   while(m--){
      scanf("%d%d",&a,&b);
      map[a][b]=map[b][a]=1;
   }
   dfs(1);
}

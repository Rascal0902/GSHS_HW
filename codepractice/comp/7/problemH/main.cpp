#include<stdio.h>
int p,n,t,A[5001],i,a,b,c;
void f(int k,int e){
   if(k==1){
      printf("%d\n1\n",e);
   }
   else{
      f(A[k],e+1);
      printf("%d\n",k);
   }
}
int main(){
   scanf("%d %d %d",&p,&n,&t);
   for(i=1;i<=n;i++){
      scanf("%d %d %d",&a,&b,&c);
      A[b]=a;
      A[c]=a;
   }
   f(t,1);
   return 0;
}

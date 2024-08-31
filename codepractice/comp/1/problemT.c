/*#include<stdio.h>
int n,m,c,seg[1<<18][4],i,tmp,x,y,z;
void f(int x,int y,int z,int tgt){
   int s=seg[tgt][1];
   int e=seg[tgt][3];
   if(e<x||y<s)return;
   if(x<=s&&e<=y){
      seg[tgt][2]=z;
      return;
   }
   if(seg[tgt][2]){
      seg[tgt*2][2]=seg[tgt*2+1][2]=seg[tgt][2];
      seg[tgt][2]=0;
   }
   f(x,y,z,tgt*2);
   f(x,y,z,tgt*2+1);
}
void print(int x,int y,int tgt){
   int s=seg[tgt][1],e=seg[tgt][3];
   if(e<x||y<s)return;
   if(seg[tgt][2]){
      for(int i=seg[tgt][1];i<=seg[tgt][3];i++)printf("%d ",seg[tgt][2]);
      return;
   }
   if(seg[tgt][1]==seg[tgt][3]){
      printf("%d ",seg[tgt][2]);
      return;
   }
   print(x,y,tgt*2);
   print(x,y,tgt*2+1);
}
main(){
   scanf("%d%d",&n,&m);
   for(i=(1<<17);i<(1<<18);i++){
      seg[i][1]=seg[i][3]=i-(1<<17);
   }
   for(i=(1<<17)-1;i;i--){
      seg[i][1]=seg[i*2][1];
      seg[i][3]=seg[i*2+1][3];
   }
   while(m--){
      scanf("%d%d%d",&x,&y,&z);
      f(x-1,y-1,z,1);
   }
   print(0,n-1,1);
}*/
#include<stdio.h>
int t[1000000][4],i,j,a,b,c,x,y,z;
int f(int x,int y,int z,int k)
{
    int s=t[k][1], e=t[k][3];
    if((e<x)||(y<s))
      {
          return 1;
      }
    if((x<=s)&&(e<=y))
    {
        t[k][2]=z;
        return 1;
    }
    if(t[k][2]!=0)
    {
        t[k*2][2]=t[k*2+1][2]=t[k][2];
        t[k][2]=0;
    }
    f(x,y,z,k*2);
    f(x,y,z,k*2+1);
}
int p(int x,int y,int k)
{
    int s=t[k][1],e=t[k][3];
    if((e<x)||(y<s))
    {
        return 1;
    }
    if(t[k][2]!=0)
    {
        for(int i=t[k][1];i<=t[k][3];i++)
        {
            printf("%d ",t[k][2]);
        }
        return 1;
    }
    if(t[k][1]==t[k][3])
    {
        printf("%d ",t[k][2]);
        return 1;
    }
    p(x,y,k*2);
    p(x,y,k*2+1);
}
int main()
{
    scanf("%d %d",&a,&b);
    for(i=(1<<17);i<(1<<18);i++)
    {
        t[i][1]=t[i][3]=i-(1<<17);
    }
    for(i=(1<<17)-1;i>=0;i--)
    {
        t[i][1]=t[i*2][1];
        t[i][3]=t[i*2+1][3];
    }
    for(i=b;i>=1;i--)
    {
        scanf("%d %d %d",&x,&y,&z);
        f(x-1,y-1,z,1);
    }
    p(0,a-1,1);
    return 0;
}


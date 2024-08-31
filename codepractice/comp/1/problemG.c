
#include <stdio.h>
int R, C;
int arr[51][51];
bool chk[2500][2500];
void input(){
    scanf("%d %d",&R,&C);
    for(int i=0;i<R;i++){
        char Temp[51];
        scanf("%s",Temp);
        for(int j=0;j<C;j++){
            arr[i][j]=(Temp[j]=='*');
        }
    }

}
int cnt=2;
void Count(){
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            if(arr[i][j]==1){
                int I=i;
                while(arr[I][j]==1){
                    arr[I][j]=cnt;
                    I++;
                }
                cnt++;
            }
        }
    }

    /*for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }*/
}
int index,colmax;
void Fill(){
    Count();
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            if(arr[i][j]){
                while(arr[i][j]){
                    chk[index+1][arr[i][j]-1]=true;
                    colmax=colmax>arr[i][j]-1?colmax:arr[i][j]-1;
                    j++;
                }
                index++;
            }
        }
    }
}
int connect[2500];
bool used[2500];
int network(int s){
    if(s==0) return 0;
    for(int e=1;e<=colmax;e++){
        if(!chk[s][e]) continue;
        if(used[e]) continue;
        used[e]=true;
        if(!connect[e]||network(connect[e])){
            connect[e]=s;
            return 1;
        }
    }
    return 0;
}
int ans;
void solve(){
    Fill();
    for(int i=1;i<=index;i++){
        for(int j=1;j<=colmax;j++){
            used[j]=false;
        }
            ans+=network(i);
    }
    printf("%d",ans);
}
int main(){
    input();
    solve();
}

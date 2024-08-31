#include <stdio.h>
#include <queue>
#include <algorithm>
#define INF 922337203685
using namespace std;
int N,W[31][31],s,e,start;
long long int cost[27000];
struct disk{
    int d[3];
    disk(){d[0]=0;d[1]=0;d[2]=0;}
    disk(int A,int B,int C){
        d[0]=A;d[1]=B;d[2]=C;
    }
    disk(int* D){
        for(int i=0;i<3;i++){
            d[i]=D[i];
        }
    }
    int size(){
        return N*N*d[2]+N*d[1]+d[0];
    }
    bool operator==(disk X){
        return (d[0]==X.d[0])&&(d[1]==X.d[1])&&(d[2]==X.d[2]);
    }
    void operator=(disk K){
        for(int i=0;i<3;i++){
            d[i]=K.d[i];
        }
    }
};
disk S,E;
bool operator<(const disk A,const disk B){
    if(cost[N*N*A.d[2]+N*A.d[1]+A.d[0]]>cost[N*N*B.d[2]+N*B.d[1]+B.d[0]]) return true;
    return false;
}
//A<B <-> cost[A]>cost[B]
priority_queue<disk> Q;
bool check[27000];
void input(){
    scanf("%d", &N);
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            scanf("%d", &W[i][j]);
        }
    }
    scanf("%d %d",&s,&e);
    S=disk(s-1,s-1,s-1);
    E=disk(e-1,e-1,e-1);
    for(int i=0;i<N*N*N;i++){
        cost[i]=INF;
    }
}
disk inttod(int k){
    int d[3];
    for(int i=0;i<3;i++){
        d[i]=k%N;
        k/=N;
    }
    return disk(d);
}
bool use(int i,int j,int* D){
    for(int k=0;k<i;k++){
        if(D[i]==D[k]||j==D[k]){
            return false;// 위에 판 아니면 갔을때 안되거나
        }
    }
    return true;
}
void chk(disk T){
    int* D=T.d;
    for(int i=0;i<3;i++){
        for(int j=0;j<N;j++){
            if(use(i,j,D)&&W[D[i]][j]){
                disk K = T;
                K.d[i]=j;
                //if(check[K.size()]) continue;
                if(cost[K.size()]<=cost[T.size()]+W[D[i]][j]){
                    continue;
                }
                else{
                    cost[K.size()]=cost[T.size()]+W[D[i]][j];
                    if(cost[K.size()]==INF) Q.push(K);
                }
            }
        }
    }
}
void solve(){
    cost[S.size()]=0;
    Q.push(S);
    while(!Q.empty()){
        disk T = Q.top();
        check[T.size()]=true;
        Q.pop();
        if(T==E){
            printf("%lld",cost[E.size()]);
            return;
        }
        chk(T);
    }
}
int main(){
    input();
    solve();
}

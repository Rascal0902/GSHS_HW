#include<stdio.h>
long long int map1[15][15],a,d,c,m,n,s,money=100000000,st[20],end1=0,max1=0,v[15];
void push(long long int k){
    st[end1]=k;
    end1++;}
void pop(){
    st[end1-1]=0;
    end1--;}
void dfs(long long int k){
    long long int i;
    if(k==m)
    {
        long long int sum=0;
        for(i=0; i<end1; i++)
        {
            if(i==k)
            {
                continue;
            }
            sum+=st[i];
            if(max1<=st[i])
            {
                max1=st[i];
            }
        }
        if((long long int)(sum-max1/2.0)<=money){
            money=(long long int)(sum-max1/2.0);
            max1=0;}max1=0;
    }
    else{
        for(i=1; i<=m; i++){
            if((map1[k][i]!=0)&&(v[i]==0))
            {
                push(map1[k][i]);
                v[i]=1;
                dfs(i);
                v[i]=0;
                pop();
            }
        }
    }

}
int main()
{
    long long int i;
    scanf("%lld %lld",&m,&n);
    for(i=0;i<n;i++)
    {
        scanf("%lld %lld %lld",&a,&d,&c);
        if((map1[a][d]!=0)||(map1[d][a]!=0)){
            continue;}
        else{map1[a][d]=c;map1[d][a]=c;}}
    v[1]=1;
    dfs(1);
    if(money==100000000){ printf("-1");}
    else{ printf("%lld",money);}
    return 0;
}


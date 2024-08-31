#include<stdio.h>
#include<iostream>
#include<queue>
using namespace std;
queue <int> Q;
int n,map[30][30],v[30],tree[10000],node=1;
char ans[100][100];
int main()
{
    scanf("%d",&n);
    char a,b;
    for(int i=0;i<n-1;i++)
    {
        scanf(" %c %c",&a,&b);
        map[(int)(a-'a')][(int)(b-'a')]=1;
        map[(int)(b-'a')][(int)(a-'a')]=1;
    }
    v[0]=1;
    tree[1]=0;
    node++;
    Q.push(0);
    int k;
    while(!Q.empty())
    {
        k=Q.front();
        Q.pop();
        for(int i=0;i<=28;i++)
        {
            if((v[i]==0)&&(i!=k)&&(map[i][k]==1))
            {
                v[i]=1;
                tree[node]=i;
                node++;
                Q.push(i);
            }
        }
    }
    for(int i=1;i<node;i++)
    {
        printf("%d ",tree[i]);
    }

    return 0;
}
/*
6
a b
c b
d c
e d
d f

9
a b
a c
b f
b g
c d
c e
d h
d i*/

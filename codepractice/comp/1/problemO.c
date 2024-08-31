#include<stdio.h>
#include<stdbool.h>
int n,m,x,y,q[100000000][3],visit[1005][1005],st=1,end=1,b[1005][1005],i,j;
void push(int k,int t)
{
    q[end][1]=k;
    q[end][2]=t;
    end++;
    visit[k][t]=1;
}
void pop()
{
    st++;
}
bool check(int x, int y, int z, int w)
{
    if(x+z>n||x+z<1)
    {
        return false;
    }
    if(y+w>m||y+w<1)
    {
        return false;
    }

    return true;
}
int main()
{
    scanf("%d %d %d %d",&n,&m,&x,&y);
    push(x,y);
    while(st!=end)
    {
        int u=q[st][1],v=q[st][2];
        if(check(u,v,-2,-1))
        {
            if(visit[u-2][v-1]==0)
            {
                push(u-2,v-1);
                b[u-2][v-1]=b[u][v]+1;
            }
        }
        if(check(u,v,-1,-2))
        {
            if(visit[u-1][v-2]==0)
            {
                push(u-1,v-2);
                b[u-1][v-2]=b[u][v]+1;
            }
        }
        if(check(u,v,1,-2))
        {
            if(visit[u+1][v-2]==0)
            {
                push(u+1,v-2);
                b[u+1][v-2]=b[u][v]+1;
            }
        }
        if(check(u,v,2,-1))
        {
            if(visit[u+2][v-1]==0)
            {
                push(u+2,v-1);
                b[u+2][v-1]=b[u][v]+1;
            }
        }
        if(check(u,v,-2,1))
        {
            if(visit[u-2][v+1]==0)
            {
                push(u-2,v+1);
                b[u-2][v+1]=b[u][v]+1;
            }
        }
        if(check(u,v,-1,2))
        {
            if(visit[u-1][v+2]==0)
            {
                push(u-1,v+2);
                b[u-1][v+2]=b[u][v]+1;
            }
        }
        if(check(u,v,2,1))
        {
            if(visit[u+2][v+1]==0)
            {
                push(u+2,v+1);
                b[u+2][v+1]=b[u][v]+1;
            }
        }
        if(check(u,v,1,2))
        {
            if(visit[u+1][v+2]==0)
            {
                push(u+1,v+2);
                b[u+1][v+2]=b[u][v]+1;
            }
        }
        pop();
    }
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=m; j++)
        {
            if(b[i][j]!=0)
            {
                printf("%d ",b[i][j]);
            }
            else
            {
                if((j==y)&&(i==x))
                {
                    printf("0 ");
                }
                else
                {
                    printf("-1 ");
                }

            }
        }
        printf("\n");
    }
    return 0;
}

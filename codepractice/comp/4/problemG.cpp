#include<stdio.h>
int n,m,a[7];
long long int s=0;
int dfs(int time)
{
    int s;
    if(time>m)
    {
        return 1;
    }
    if(time==m)
    {
        int i=0;
        for(i=1;i<=n;i++)
        {
            printf("%d ",a[i]);
            /*if(a[i]!=2)
            {
                return 1;
            }*/
        }
        printf("\n\n\n");
        s++;
        s=s%1000000007;
        return 1;
    }
    else
    {
        int amin=100,bmin=100,cmin=100,i;
        i=0;
        for(i=1;i<=n;i++)
        {
            if(a[i]==0)
            {
                if(amin>i)
                {
                    amin=i;
                }
            }
             if(a[i]==1)
            {
                if(bmin>i)
                {
                    bmin=i;
                }
            }
             if(a[i]==2)
            {
                if(cmin>i)
                {
                    cmin=i;
                }
            }
        }
        if((amin>=bmin)&&(bmin>=cmin))
        {
            a[cmin]=0;
            dfs(time+1);
            a[cmin]=2;
            a[cmin]=1;
            dfs(time+1);
            a[cmin]=2;
            a[bmin]=0;
            dfs(time+1);
            a[bmin]=1;
        }
        else if((amin>=cmin)&&(cmin>=bmin))
        {
            a[bmin]=0;
            dfs(time+1);
            a[bmin]=1;
            a[bmin]=2;
            dfs(time+1);
            a[bmin]=1;
            a[cmin]=0;
            dfs(time+1);
            a[cmin]=2;
        }
        else if((bmin>=amin)&&(amin>=cmin))
        {
             a[cmin]=1;
            dfs(time+1);
            a[cmin]=2;
            a[cmin]=0;
            dfs(time+1);
            a[cmin]=2;
            a[amin]=1;
            dfs(time+1);
            a[amin]=0;
        }
         else if((bmin>=cmin)&&(cmin>=amin))
        {
             a[amin]=1;
            dfs(time+1);
            a[amin]=0;
            a[amin]=2;
            dfs(time+1);
            a[amin]=0;
            a[cmin]=1;
            dfs(time+1);
            a[cmin]=2;
        }
         else if((cmin>=amin)&&(amin>=bmin))
        {
             a[bmin]=2;
            dfs(time+1);
            a[bmin]=1;
            a[bmin]=0;
            dfs(time+1);
            a[bmin]=1;
            a[amin]=2;
            dfs(time+1);
            a[amin]=0;
        }
         else if((cmin>=bmin)&&(bmin>=amin))
        {
             a[amin]=2;
            dfs(time+1);
            a[amin]=0;
            a[amin]=1;
            dfs(time+1);
            a[amin]=0;
            a[bmin]=2;
            dfs(time+1);
            a[bmin]=1;
        }
        else
        {

        }

    }
}
int main()
{
    scanf("%d %d",&n,&m);
    int i=0;
    for(i=1;i<=n;i++)
    {
        a[i]=0;
    }
    dfs(0);
    printf("\n\n%lld",s);
    return 0;
}

/*#include <stdio.h>
int tr1[50],tr2[50],b[15][15],n,max=0,i;
int f(int k,int t,int low)
{
    if(k==n)
    {
        if(max<=t)
        {
            max=t;

        }
        else
        {
            return 1;
        }
    }
    else
    {
        for(i=low; i<n; i++)
        {
            if((tr1[i+k]==1)||(tr2[n+i-k]==1)||(b[k][i]==0))
            {
                continue;
            }
            tr1[i+k]=tr2[n+i-k]=1;
            f(k,t+1,i+1);
            f(k+1,t+1,0);
            tr1[i+k]=tr2[n+i-k]=0;

        }
        f(k+1,t,0);
    }

}
int main()
{
    int i,j;
    scanf("%d",&n);
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            scanf("%d",&b[i][j]);
        }
    }
    f(0,0,0);
    printf("%d",max);
    return 0;
}
*/
/*#include <stdio.h>
int tr1[50],tr2[50],b[15][15],n,max1=0,max2=0,i;
int f1(int k,int t,int low)
{
    if(k==n)
    {
        if(max1<=t)
        {
            max1=t;

        }
        else
        {
            return 1;
        }
    }
    else
    {
        if(k%2==0)
        {
            for(i=low; i<n; i+=2)
            {
                if((tr1[i+k]==1)||(tr2[n+i-k]==1)||(b[k][i]==0))
                {
                    continue;
                }
                tr1[i+k]=tr2[n+i-k]=1;
                f1(k,t+1,i+2);
                f1(k+1,t+1,1);
                tr1[i+k]=tr2[n+i-k]=0;

            }
            f1(k+1,t,1);
        }
        else
        {
             for(i=low; i<n; i+=2)
            {
                if((tr1[i+k]==1)||(tr2[n+i-k]==1)||(b[k][i]==0))
                {
                    continue;
                }
                tr1[i+k]=tr2[n+i-k]=1;
                f1(k,t+1,i+2);
                f1(k+1,t+1,0);
                tr1[i+k]=tr2[n+i-k]=0;

            }
            f1(k+1,t,0);
        }


    }

}
int f2(int k,int t,int low)
{
    if(k==n)
    {
        if(max2<=t)
        {
            max2=t;

        }
        else
        {
            return 1;
        }
    }
    else
    {
        if(k%2==0)
        {
            for(i=low; i<n; i+=2)
            {
                if((tr1[i+k]==1)||(tr2[n+i-k]==1)||(b[k][i]==0))
                {
                    continue;
                }
                tr1[i+k]=tr2[n+i-k]=1;
                f2(k,t+1,i+2);
                f2(k+1,t+1,0);
                tr1[i+k]=tr2[n+i-k]=0;

            }
            f2(k+1,t,0);
        }
        else
        {
             for(i=low; i<n; i+=2)
            {
                if((tr1[i+k]==1)||(tr2[n+i-k]==1)||(b[k][i]==0))
                {
                    continue;
                }
                tr1[i+k]=tr2[n+i-k]=1;
                f2(k,t+1,i+2);
                f2(k+1,t+1,1);
                tr1[i+k]=tr2[n+i-k]=0;

            }
            f2(k+1,t,1);
        }


    }

}
int main()
{
    int i,j;
    scanf("%d",&n);
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            scanf("%d",&b[i][j]);
        }
    }
    f1(0,0,0);
    f2(0,0,1);
    printf("%d",max1+max2);
    return 0;
}*/
#include<stdio.h>
int b[30],a[15][15],n,s;
long long int sum;
int max(int x,int y)
{
    if(x>y)
    {
        return x;
    }
    else
    {
        return y;
    }
}
int min(int x,int y)
{
    if(x>y)
    {
        return y;
    }
    else
    {
        return x;
    }
}
void f(int k,int t)
{
    if(k>=2*n)
    {
        s=max(s,t);
    }
    else
    {
        int x,y;
        x=min(n,k);
        y=max(0,k-n);
        while((x>=0)&&(y<n))
        {
            if((b[n-x+y]==0)&&(a[x][y]==1))
            {
                b[n-x+y]=1;
                f(k+2,t+1);
                b[n-x+y]=0;
            }
            x--;
            y++;
        }
        f(k+2,t);
    }
}
int main()
{
    int i,j;
    scanf("%d",&n);
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    f(0,0);
    sum=s;
    s=0;
    f(1,0);
    sum+=s;
    printf("%lld",sum);
    return 0;
}

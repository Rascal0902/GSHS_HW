/*#include<stdio.h>
int a[10004],d[10004],i,n,b[5][5],c[5][5],s[10003],end=0,t1=0,t2=0;
void push(int k)
{
    s[end]=k;
    end++;

}
void pop()
{
    s[end-1]=0;
    end--;

}
int change1(int low,int high)
{
    int t;
    i=0;
    for(i=low;i<=high;i++)
    {
        push(a[i]);
    }
    for(i=low;i<=high;i++)
    {
        t=s[end-1];
        a[i]=t;
        pop();
    }
    return 1;
}
int change2(int low,int high)
{
    int t;
    i=0;
    for(i=low;i<=high;i++)
    {
        push(d[i]);
    }
    for(i=low;i<=high;i++)
    {
        t=s[end-1];
        d[i]=t;
        pop();
    }
    return 1;
}
int f2(int k)
{
    if(k==-1)
    {
        if(t2==1)
        {
            c[1][0]=c[0][0];
            c[1][1]=c[0][1];
            c[0][0]=1;
            c[0][1]=1;
        }
        i=0;
        for(i=0;i<=1;i++)
        {
            printf("%d %d\n",c[i][1],c[i][0]);
        }
        return 1;
    }
    if(d[k]==k)
    {
        f2(k-1);
    }
    else
    {

        int t=0;
        for(i=k;i>=0;i--)
        {
            if(d[i]==k)
            {
                t=i;
                break;
            }
        }
        i=0;
        c[t2][0]=k;
        c[t2][1]=t;
        t2++;
        change2(t,k);
        f2(k-1);
    }
}
int f(int k)
{
    if(k==n+1)
    {
        if(t1==0)
        {
            b[0][0]=1;
            b[0][1]=1;
            b[1][0]=1;
            b[1][1]=1;
        }
        if(t1==1)
        {
            b[1][0]=b[0][0];
            b[1][1]=b[0][1];
            b[0][0]=1;
            b[0][1]=1;
        }
        if(t1>=3)
        {
            f2(n-1);
            return 0;
        }
        i=0;
        for(i=0;i<=1;i++)
        {
            printf("%d %d\n",b[i][0],b[i][1]);
        }
        return 1;
    }
    if(a[k]==k)
    {
        f(k+1);
    }
    else
    {

        int t=0;
        for(i=k;i<=n;i++)
        {
            if(a[i]==k)
            {
                t=i;
                break;
            }
        }
        i=0;
        b[t1][0]=k;
        b[t1][1]=t;
        t1++;
        change1(k,t);
        f(k+1);
    }
}
int main()
{
    scanf("%d", &n);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        d[i]=a[i];
    }
    f(1);
    return 0;
}
*/
#include <stdio.h>
#include<stdbool.h>
int n, a[10000],i,b[2][2];
bool check()
{
    for(i=0; i<n; i++)
    {
        if(a[i]!=i+1)
            return false;
    }
    return true;
}
int find(int k)
{
    for(i=0; i<n; i++)
    {
        if(a[i]==k)
        {
            return i;
        }
    }
}
void change(int low, int high)
{
    for(i=low; i<=(low+high)/2; i++)
    {
        int t;
        t=a[i];
        a[i]=a[low+high-i];
        a[low+high-i]=t;
    }
}

int start(int k)
{
    if(k==0)
    {
        for(i=0; i<n; i++)
        {
            if(a[i]!=i+1)
                return i;
        }
        return n;
    }
    for(i=n-1; i>=0; i--)
    {
        if(a[i]!=i+1)
            return i;
    }
    return -1;
}
int f()
{
    int k;
    if(check())
    {
        printf("1 1");
        printf("\n1 1");
        return 1;
    }
    for(k=0; k<2; k++)
    {
        b[0][k]=start(k);
        b[0][1-k]=find(b[0][k]+1);
        change(b[0][0],b[0][1]);

        if(check())
        {
            printf("%d %d\n1 1",b[0][0]+1,b[0][1]+1);
            return 1;
        }
        b[1][k]=start(k);
        b[1][1-k]=find(b[1][k]+1);
        change(b[1][0],b[1][1]);
        if(check())
        {
            for(i=0; i<2; i++)
            {
                for(int j=0; j<2; j++)
                {
                    printf("%d ",b[i][j]+1);
                }
                printf("\n");
            }
            return 1;
        }
        change(b[1][0],b[1][1]);
        change(b[0][0],b[0][1]);
    }
}
int main()
{
    scanf("%d", &n);
    for(i=0; i<n; i++)
    {
        scanf("%d", &a[i]);
    }
    f();
    return 0;
}

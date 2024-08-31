#include <stdio.h>
int n,work,mini=1000000000;
int x[15]={0,};
int y[15]={0,};
int cha(int a,int b)
{
    if(a>b) return a-b;
    return b-a;
}
void babo(int walk,int did,int car1x,int car1y,int car2x,int car2y)
{
    if(did==work)
    {
        if(walk<mini)
            mini=walk;
        return;
    }
    babo(walk+cha(x[did],car1x)+cha(y[did],car1y),did+1,x[did],y[did],car2x,car2y);
    babo(walk+cha(x[did],car2x)+cha(y[did],car2y),did+1,car1x,car1y,x[did],y[did]);
}
int main()
{

    scanf("%d %d",&n,&work);
    for(int i=0;i<work;i++)
    {
        scanf("%d %d",&x[i],&y[i]);
    }
    babo(0,0,1,1,n,n);
    printf("%d",mini);
}

/*#include <stdio.h>
int n,k,m=1000000000;
int x[15]={0,};
int y[15]={0,};
int c(int a,int b)
{
    if(a>b) return a-b;
    return b-a;
}
void wo(int t,int cas,int x1,int y1,int x2,int y2)
{
    if(cas==k)
    {
        if(t<m)
            m=t;
        return;
    }
    wo(t+c(x[cas],x1)+c(y[cas],y1),cas+1,x[cas],y[cas],x2,x2);
    wo(t+c(x[cas],x2)+c(y[cas],y2),cas+1,x1,y1,x[cas],y[cas]);
}
int main()
{

    scanf("%d %d",&n,&k);
    for(int i=0;i<k;i++)
    {
        scanf("%d %d",&x[i],&y[i]);
    }
    wo(0,0,1,1,n,n);
    printf("%d",m);
    return 0;
}*/

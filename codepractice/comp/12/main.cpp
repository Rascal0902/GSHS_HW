/*#include<stdio.h>
#include<iostream>
using namespace std;
long long int n,t=0;
int main()
{
    scanf("%lld",&n);
    if(n==0)
    {
        printf("1");
        return 0;
    }
    while(1)
    {
        n=n>>1;
        t++;
        if(n==0)
        {
            break;
        }
    }
    printf("%d",t);
    return 0;
}
*/
/*#include<stdio.h>
#include<iostream>
using namespace std;
long long int n,t=0;
int main()
{
    scanf("%lld",&n);
    while(1)
    {
        if(n%2==1)
        {
            t++;
        }
        n=n>>1;
        if(n==0)
        {
            break;
        }
    }
    printf("%d",t);
    return 0;
}*/
/*#include<stdio.h>
#include<iostream>
using namespace std;
long long int n,t=1;
int main()
{
    scanf("%lld",&n);
    while(1)
    {
        if(n%2==1 || n==0)
        {
            break;
        }
        n=n>>1;
        t*=2;
    }
    printf("%lld",t);
    return 0;
}*/
/*#include<stdio.h>
#include<iostream>
using namespace std;
long long int n,m,t=0;
int main()
{
    scanf("%lld %lld",&n,&m);
    while(1)
    {
        if(n%2  !=   m%2)
        {
            t++;
        }
        n=n>>1;
        m=m>>1;
        if(n==0 && m==0)
        {
            break;
        }
    }
    printf("%lld",t);
    return 0;
}
*/
/*#include<stdio.h>
#include<iostream>
#include<stack>
#include<string.h>
#include<algorithm>
using namespace std;
long long int n,m,up=0,maxi;
char xr[10000],yr[10000],x[10000],y[10000],ans[10000];
int main()
{
    scanf("%s",xr);
    scanf("%s",yr);
    for(int i=0;i<strlen(xr);i++)
    {
        x[strlen(xr)-1-i]=xr[i];
    }
     for(int i=0;i<strlen(yr);i++)
    {
        y[strlen(yr)-1-i]=yr[i];
    }
    maxi=max(strlen(xr),strlen(yr));
    for(int i=strlen(xr);i<10000;i++)
    {
        x[i]='0';
    }
    for(int i=strlen(yr);i<10000;i++)
    {
        y[i]='0';
    }
    for(int i=0;i<maxi;i++)
    {
        ans[i]=(char)('0'+((long long int)(x[i]-'0')+(long long int)(y[i]-'0')+up)%10);
        up=((long long int)(x[i]-'0')+(long long int)(y[i]-'0')+up)/10;
    }
    if(up!=0)
    {
        ans[maxi]=(char)(up+'0');
        maxi++;
    }
    for(int i=maxi-1;i>=0;i--)
    {
        printf("%c",ans[i]);
    }
    return 0;
}*/
/*#include<stdio.h>
#include<iostream>
#include<stack>
#include<string.h>
#include<algorithm>
using namespace std;
long long int n,m,up=0,maxi;
char xr[10000],yr[10000],x[10000],y[10000];
long long int ansm[10000];
int main()
{
    scanf("%s",xr);
    scanf("%s",yr);
    for(int i=0;i<strlen(xr);i++)
    {
        x[strlen(xr)-1-i]=xr[i];
    }
     for(int i=0;i<strlen(yr);i++)
    {
        y[strlen(yr)-1-i]=yr[i];
    }
    for(int j=0;j<strlen(yr);j++)
    {
        for(int i=0;i<strlen(xr);i++)
        {
        ansm[i+j]+=((long long int)(x[i]-'0')*(long long int)(y[j]-'0')+up)%10;
        up=((long long int)(x[i]-'0')*(long long int)(y[j]-'0')+up)/10;
        }
        if(up!=0)
        {
        ansm[strlen(xr)+j]=up;
        }
        up=0;
    }
    up=0; long long int up2;
    long long int str=0;
    for(int i=0;i<10000;i++)
    {
        if((ansm[i]+up)%10!=0  && str<i+1)
        {
            str=i+1;
        }
        up2=(ansm[i]+up)/10;
        ansm[i]=(ansm[i]+up)%10;
        up=up2;
    }
    for(int i=min(str-1,(long long int)17);i>=0;i--)
    {
        printf("%lld",ansm[i]);
    }
    return 0;
}*/
/*#include<stdio.h>
#include<iostream>
using namespace std;
long long int siz,a[100010];
long long int f(long long int n,long long int m)
{
    long long int t=0;
    while(1)
    {
        if(n%2  !=   m%2)
        {
            t++;
        }
        n=n>>1;
        m=m>>1;
        if(n==0 && m==0)
        {
            break;
        }
    }
    return t;
}
int main()
{
    long long int sum=0,x;
    scanf("%lld",&siz);
    for(int i=0;i<siz;i++)
    {
        scanf("%lld",&a[i]);
    }
    for(int i=0;i<siz;i++)
    {
        for(int j=i+1;j<siz;j++)
        {
            x=f(a[i],a[j]);
            sum+=x;
            sum%=1000000007;
            sum+=x;
            sum%=1000000007;
        }
    }
    printf("%lld",sum);
}*/
/*#include<stdio.h>
#include<iostream>
#include<queue>
#include<utility>
using namespace std;
queue <pair <int , int> > q;
long long int n,x=0,y=0,a[100100],b[100100],v[100100];
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%1d",&a[i]);
    }
    for(int i=0;i<n;i++)
    {
        scanf("%1d",&b[i]);
    }
    for(int i=0;i<n;i++)
    {
        x*=2;
        y*=2;
        x+=a[i];
        y+=b[i];
    }
        q.push({x,0});
        while(!q.empty())
        {
            int now=(q.front()).first;
            int time=(q.front()).second;
            q.pop();
            if(now==y)
            {
                printf("%d",time);
            }
            for(int i=0;i<n;i++)
            {
                if(i==0)
                {
                    long long int mod2;
                    mod2=now%2;
                    now=(now/2)*2+~now;
                    if(now==y)
                    {

                    }
                }
                else if(i==n-1)
                {

                }
                else
                {

                }
            }

        }
    printf("-1");
    return 0;
}
*/
/*#include<stdio.h>
#include<iostream>
using namespace std;
long long int siz,a[100000],b[100000];
int main()
{
    long long int sum=0,x;
    scanf("%lld",&siz);
    for(int i=0;i<siz;i++)
    {
        scanf("%lld",&a[i]);
        int j=0;
        while(a[i]>0)
        {
            if(a[i]%2==1)
            { b[j]++;}
            a[i]=a[i]/2;
            j++;
        }
    }
    for(int i=0;i<100000;i++)
    {
       sum+=2*b[i]*(siz-b[i]);
       sum%=1000000007;
    }
    printf("%lld",sum);
    return 0;
}*/
/*#include<stdio.h>
#include<iostream>
#include<queue>
#include<utility>
using namespace std;
queue <pair <int , int> > q;
long long int n,a[100100],b[100100],cnt=0;
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%1d",&a[i]);
    }
    for(int i=0;i<n;i++)
    {
        scanf("%1d",&b[i]);
    }
    if(a[0]==b[0]){}
    else {a[0]=b[0];a[1]=~a[1];cnt=1;}
    for(int i=1;i<n-2;i++)
    {
        if(a[i]!=b[i])
        {
            cnt++;
            a[i]=b[i];
            a[i+1]=~a[i+1];
            a[i+2]=~a[i+2];
        }
    }
    if(a[n-2]==b[n-2] && a[n-1]==b[n-1])
    {
        printf("%d",cnt);
        return 0;
    }
    else if(a[n-2]==b[n-2] && a[n-1]!=b[n-1])
    {
        printf("-1");
        return 0;
    }
    else if(a[n-2]!=b[n-2] && a[n-1]==b[n-1])
    {
        printf("-1");
        return 0;
    }
    else
    {
        printf("%d",cnt+1);
        return 0;
    }
    return 0;
}
*/
/*#include<stdio.h>
#include<iostream>
using namespace std;
long long int n,m,a[10000][10000];
int main()
{
    long long int sum=0;
    scanf("%lld %lld",&n,&m);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            scanf("%lld",&a[i][j]);
            a[i][j]=a[i][j]+a[i-1][j]+a[i][j-1]-a[i-1][j-1];
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            printf("%lld ",a[i][j]);
        }
        printf("\n");
    }
    return 0;
}*/
/*#include<stdio.h>
#include<iostream>
using namespace std;
long long int n,m,a[1000005],b[1000005];
int main()
{
    long long int sum=0;
    scanf("%lld %lld",&n,&m);
    for(int i=1;i<=n;i++)
    {
       scanf("%lld",&a[i]);
       b[i]=b[i-1]+a[i];
    }
    long long int p,q,r;
    for(int i=1;i<=m;i++)
    {
        scanf("%lld %lld %lld",&p,&q,&r);
        if(p==1)
        {
            printf("%lld\n",b[r]-b[q-1]);
        }
        else
        {
            a[q]=r;
            for(int j=q;j<=n;j++)
            {
                    b[j]=b[j-1]+a[j];
            }
        }
    }
    return 0;
}*/
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
#include<iostream>
#include<deque>
using namespace std;
deque <int> s[205];
long long int n,m=0,cnt=0;
long long int f(int a,int b)
{

}
int main()
{
    scanf("%lld",&n);
    int t;
    for(long long int i=0;i<n;i++)
    {
        scanf("%d",&t);
        s[t].push_back(i);
    }
    for(int i=1;i<=200;i++)
    {
        if(s[i].size()>=2)
        {
            while(1)
            {
                if(s[i].size()<2)
                {
                    break;
                }
                cnt+=2;
                (m < f(s[i].front(),s[i].back())+cnt)? m=f(s[i].front(),s[i].back())+cnt: m=m;
                s[i].pop_front();
                s[i].pop_back();
            }
        }
        cnt=0;
    }
    printf("%lld",m);
}

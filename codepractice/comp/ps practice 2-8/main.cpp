//2-1 상태 정의 1
/*#include<iostream>
#include<stdio.h>
using namespace std;
int n;
int f(int m,int k)
{
    if(m==n){return 1;}
    else if(m>n){return 0;}
    else
    {   int s;
        if(k==1)
        {
           s=f(m+2,2)+f(m+3,3);
           return s;
        }
        if(k==2)
        {
           s=f(m+1,1)+f(m+3,3);
           return s;
        }
        if(k==3)
        {
           s=f(m+2,2)+f(m+1,1);
           return s;
        }
    }

}
int main()
{
    scanf("%d",&n);
    printf("%d",f(1,1)+f(2,2)+f(3,3));
    return 0;
}*/
//2-2 상태정의 2
/*#include<stdio.h>
#include<iostream>
using namespace std;
int n;
bool isprime(int k)
{
    if(k==1){return 0;}
    if(k==2){return 1;}
    for(int i=2;i<k;i++)
    {
        if(k%i==0)
        {
            return 0;
        }
    }
    return 1;
}
int f(int m,int k){
    if(m==n)
    {if(k==1){ return 1;}
     if((k==0)||(k>=2)){return 0;}
    }
    else if(m>n){return 0;}
    else
    {
        int sum=0;
        for(int i=1;i<4;i++)
        {
            if(isprime(m+i))
            { //printf("%d %d\n",m+i,k+1);
                sum+=f(m+i,k+1);

            }
            else
            {// printf("%d %d\n",m+i,k);
                sum+=f(m+i,k);

            }
        }
        return sum;
    }
}
int main()
{
    scanf("%d",&n);
    printf("%d",f(0,0));
}*/
//2-3 상태 정의 3
/*#include<stdio.h>
#include<iostream>
using namespace std;
int n;
int f(int m,int k,int t)
{
    if(k>3){return 0;}
    if(n==m)
    {if(k<=3){return 1;}
     if(k>3){return 0;}
    }
    else if(m>n)
    {
       return 0;
    }
    else{
        int s=0;
        for(int i=1;i<=2;i++)
        {

            if(i==t)
            {
                s+=f(m+i,k+1,t);
                //printf("%d %d %d\n",m+i,k+1,t);
            }
            else
            {
                s+=f(m+i,1,i);
                //printf("%d %d %d\n",m+i,1,i);
            }
        }
        return s;
    }
}

int main()
{
    scanf("%d",&n);
    printf("%d",f(1,1,1)+f(2,1,2));
}*/
//2-4 상태정의 4
/*#include<stdio.h>
#include<iostream>
using namespace std;
int n;
int f(int m)
{
    if(m==1)
    {
        return 1;
    }
    if(m==2)
    {
        return 2;
    }
    if(m==3)
    {
        return 4;
    }
    else
    {
        int s=0;
        for(int i=1;i<=3;i++)
        {
            s+=f(m-i);
        }
        return s;
    }
}
int main()
{
    scanf("%d",&n);
    int sum=0;
    for(int i=1;i<=n;i++)
    {
        sum+=f(i)*f(n+1-i);
    }
    printf("%d",sum);
    return 0;
}
*/
//2-5 상태정의 5
/*#include<stdio.h>
#include<iostream>
using namespace std;
int n;
int f(int m,int k)
{
    if(m==0){
        if(k==0){return 1;}
        else{return 0;}}
    else if(m<0){return 0;}
    else
    {
        int s;
        s=f(m-1,k-1)+f(m-2,k-1);
        return s;
    }
}
int main()
{
    scanf("%d",&n);
    int sum=0;
    for(int i=1;i<=n;i++)
    {
        sum+=f(n,i)*f(n,i);
    }
    printf("%d",sum);
    return 0;
}*/
//2-6 계단 오르기
/*#include<stdio.h>
#include<iostream>
using namespace std;
int n,k;
int f(int m,int no)
{
    if(no==m)
        {
            return 0;
        }
    if(m>n)
    {
        return 0;
    }
    else if(m==n)
       {

            return 1;
        }
    else
    {
        int s=0;
        for(int i=1;i<=3;i++)
        {
            s+=f(m+i,no);
        }
        return s;
    }
}
int main()
{
    scanf("%d %d",&n,&k);
    printf("%d",f(0,k));
    return 0;
}*/
//2-7 계단 뛰어오르기
/*#include<stdio.h>
#include<iostream>
using namespace std;
int n;
int f(int m)
{
    if(n==m)
    {
        return 1;
    }
    else if(n<m)
    {
        return 0;
    }
    else
    {
        int sum;
        sum=f(m+1)+f(m+2)+f(m+3);
        return sum;
    }
}
int main()
{
    scanf("%d",&n);
    printf("%d",f(0));
    return 0;
}*/
//2-8 극장 좌석 배치
/*#include<stdio.h>
#include<iostream>
using namespace std;
int n,k;
int f(int m,int t)
{
    if((t==0)||(m==t))
    {
        return 1;
    }
    else
    {
        int sum;
        sum=f(m-1,t-1)+f(m-1,t);
        return sum;
    }
}
int main()
{
    scanf("%d %d",&n,&k);
    printf("%d",f(n,k));
    return 0;
}*/
//3-1 진법 변환
/*#include<stdio.h>
#include<iostream>
using namespace std;
int n,k;
void f(int m,int st)
{
    if(m==0){return;}
    else{
    f(m/st,st);
    if(m%st<=9)
    {
        printf("%d",m%st);
    }
    else
    {
        printf("%c",(char)('A'+m%st-10));
    }
    }
}
int main()
{
    scanf("%d %d",&n,&k);
    f(n,k);
    return 0;
}*/
//3-2 number reverse
/*#include<stdio.h>
#include<iostream>
using namespace std;
int n;
void f(int be,int af)
{
    if(be==0)
    {
        printf("%d",af);
        return;
    }
    else
    {
        f(be/10,af*10+be%10);
        return;
    }
}
int main()
{
    scanf("%d",&n);
    f(n,0);
    return 0;
}*/
//3-3 reverse and add
/*#include<stdio.h>
#include<iostream>
using namespace std;
int n;
int f(int be,int af)
{
    if(be==0)
    {
        return af;
    }
    else
    {
        f(be/10,af*10+be%10);
    }
}
int main()
{
    int cnt=0;
    scanf("%d",&n);
    while(1)
    {
        if(n==f(n,0))
        {
            break;
        }
        n+=f(n,0);
        cnt++;
    }
    printf("%d %d",cnt,n);
    return 0;
}*/
//3-4 별그리기 9
/*#include<stdio.h>
#include<iostream>
using namespace std;
int n;
int f(int m)
{
    if(m==0)
    {
        return 0;
    }
    else
    {
        int sum=0;
        sum+=f(m-1);
        printf("\n");
        for(int i=0;i<m;i++)
        {
            printf("*");
        }
        sum+=m;
        printf("\n");
        sum+=f(m-1);
        return sum;
    }
}
int main()
{
    scanf("%d",&n);
    printf("\n%d",f(n));
    return 0;
}*/
//3-5 동전줍기 Small
/*#include<stdio.h>
#include<iostream>
int n,a[30],max=0;
int f(int now,int tot,int t)
{
    if(now==n)
    {
        if(max<tot)
        {
            max=tot;
        }
    }
    else
    {
        if(t==0)
        {
            f(now+1,tot+a[now],1);
            f(now+1,tot,0);
        }
        else if(t==1)
        {
            f(now+1,tot+a[now],2);
            f(now+1,tot,0);
        }
        else
        {
            f(now+1,tot,0);
        }
    }
}
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    f(0,0,0);
    printf("%d",max);
    return 0;
}*/
//3-6 Ants
/*#include<stdio.h>
#include<iostream>
int n,k,a[15],max=0,min=0;
int main()
{
    scanf("%d %d",&n,&k);
    for(int i=0;i<k;i++)
    {
        scanf("%d",&a[i]);
    }
    for(int i=0;i<k;i++)
    {
        if(a[i]<n-a[i])
        {
            if(max<n-a[i])
            {
                max=n-a[i];
            }
            if(min<a[i])
            {
                min=a[i];
            }
        }
        else
        {
             if(max<a[i])
            {
                max=a[i];
            }
            if(min<n-a[i])
            {
                min=n-a[i];
            }
        }
    }
    printf("%d %d",min,max);
    return 0;
}*/
//3-7 4진 트리
/*#include<stdio.h>
int n,a[1030][1030];
void f(int lowx,int highx,int lowy,int highy)
{
    if(lowx==highx)
    {
        printf("%d",a[lowx][lowy]);
    }
    else
    {
        int ex1=0,ex0=0;
        for(int i=lowx;i<=highx;i++)
        {
            for(int j=lowy;j<=highy;j++)
            {
                if(a[i][j]==1)
                {
                    ex1=1;
                }
                else
                {
                    ex0=1;
                }
            }
        }
        if((ex1==1)&&(ex0==1))
        {
            printf("X");
            f(lowx,(lowx+highx)/2,lowy,(lowy+highy)/2);
            f(lowx,(lowx+highx)/2,(lowy+highy)/2+1,highy);
            f((lowx+highx)/2+1,highx,lowy,(lowy+highy)/2);
            f((lowx+highx)/2+1,highx,(lowy+highy)/2+1,highy);
        }
        else
        {
            printf("%d",a[lowx][lowy]);
        }
    }
}
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    f(0,n-1,0,n-1);
    return 0;
}
*/
//3-8 압축 해제
/*#include<stdio.h>
#include<string.h>
int n,ans[1030][1030],size,cnt=0;
char a[2000100];
void f(int lowx,int highx,int lowy,int highy)
{
    if(cnt==size)
    {
        return;
    }
    if(a[cnt]=='X')
    {
        cnt++;
        if(highx>=lowx+1){
        f(lowx,(lowx+highx)/2,lowy,(lowy+highy)/2);
        f(lowx,(lowx+highx)/2,(lowy+highy)/2+1,highy);
        f((lowx+highx)/2+1,highx,lowy,(lowy+highy)/2);
        f((lowx+highx)/2+1,highx,(lowy+highy)/2+1,highy);}
        return;
    }
    else if(a[cnt]=='1')
    {
        if((lowx>highx)||(lowy>highy))
        {
            return;
        }
        for(int i=lowx;i<=highx;i++)
        {
            for(int j=lowy;j<=highy;j++)
            {
                ans[i][j]=1;
            }
        }
        cnt++;
        return;
    }
    else if(a[cnt]=='0')
    {
        for(int i=lowx;i<=highx;i++)
        {
            for(int j=lowy;j<=highy;j++)
            {
                ans[i][j]=0;
            }
        }
        cnt++;
        return;
    }
    else{}
        return;
}
int main()
{
    scanf("%d",&n);
    scanf("%s",a);
    size=strlen(a);
    f(0,n-1,0,n-1);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("%d ",ans[i][j]);
        }
        printf("\n");
    }
    return 0;
}*/
//4-1 the tower of hanoi
/*#include<stdio.h>
void f(int n,char a,char b,char c)
{
    if(n==1)
    {
        printf("move disk %d %c->%c\n",n,a,c);
        return;
    }
    f(n-1,a,c,b);
    printf("move disk %d %c->%c\n",n,a,c);
    f(n-1,b,a,c);
    return;
}
int main()
{
    int n;
    scanf("%d",&n);
    printf("%d\n",(1<<n)-1);
    f(n,'A','B','C');
}*/
//4-2 the tower of hanoi2
/*#include<stdio.h>
int f(int n,char a,char b,char c)
{
    int sum=0;
    if(n==1)
    {
        printf("%d : %c->%c\n",n,a,b);
        printf("%d : %c->%c\n",n,b,c);
        return 2;
    }
    sum+=f(n-1,a,b,c);
    printf("%d : %c->%c\n",n,a,b);
    sum+=f(n-1,c,b,a);
    printf("%d : %c->%c\n",n,b,c);
    sum+=f(n-1,a,b,c);
    sum+=2;
    return sum;
}
int main()
{
    int n;
    scanf("%d",&n);
    printf("%d",f(n,'A','B','C'));
}*/
//4-3 the tower of hanoi 3
/*#include<stdio.h>
long long int a[130],b[130],k;
long long int f(long long int n)
{
    long long int i;
    if(n==0)
    {
        return 0;
    }
    if(b[n]!=0)
    {
        return b[n];
    }
    else
    {
        long long int s=10000000000,tempt=0;
        for(i=n/2;i<n;i++)
        {
            tempt+=2*f(i)+a[n-i];
            if(tempt<s)
            {
                s=tempt;
            }
            tempt=0;
        }
        b[n]=s;
        return b[n];
    }
}
int main()
{
    long long int i;
    scanf("%lld",&k);
    a[0]=0;
    for(i=1;i<=k+2;i++)
    {
        a[i]=a[i-1]*2+1;
    }
    printf("%lld",f(k));
    return 0;
}
*/
//4-4 가장 긴 하노이
/*#include<stdio.h>
#include<iostream>
using namespace std;
long long int n,cnt=0,a[100000000];
int p(long long int k,char x,char y,char z)
{
    if(k==0)
    {
        return 1;
    }
    if(cnt<=99)
    {
        p(k-1,x,y,z);
    }
    if(cnt<=99)
    {
        printf("%lld : %c->%c\n",k,x,y);
        cnt++;
    }
    if(cnt<=99)
    {
         p(k-1,z,y,x);
    }
    if(cnt<=99)
    {
         printf("%lld : %c->%c\n",k,y,z);
         cnt++;
    }
    if(cnt<=99)
    {
         p(k-1,x,y,z);
    }
    return 1;
}
int main()
{
    scanf("%lld",&n);
    if(n>=5)
    {
        p(5,'A','C','B');
    }
    else
    {
        p(n,'A','C','B');
    }
    for(long long int i=1;i<=n;i++)
   {
        a[i]=(3*a[i-1]+2)%1000000007;
   }
   printf("%lld",a[n]);
    return 0;
}*/
//4-5 삼각하노이
/*#include<stdio.h>
#include<iostream>
using namespace std;
long long int a[10000000],n,b[1000000],c[100000000];
int main()
{
    scanf("%lld",&n);
    a[1]=1;
    for(long long int i=2;i<=n;i++)
    {
        a[i]=a[i-1]*2+1;
    }
    b[1]=2;
    c[1]=1;
    for(long long int i=2;i<=n;i++)
    {
        c[i]=b[i-1]+1+2*a[i-1];
        b[i]=c[i-1]+1+2*a[i-1]+1+2*a[i-1];
    }
    printf("%lld",b[n]);
    return 0;
}*/
//4-6 삼각하노이 large
/*#include<stdio.h>
#include<iostream>
using namespace std;
long long int a[1000005],n,b[1000005],c[1000005];
int main()
{
    scanf("%lld",&n);
    a[1]=1;
    for(long long int i=2;i<=n;i++)
    {
        a[i]=(a[i-1]*2+1)%1000000007;
    }
    b[1]=2;
    c[1]=1;
    for(long long int i=2;i<=n;i++)
    {
        c[i]=(b[i-1]+1+2*a[i-1])%1000000007;
        b[i]=(c[i-1]+1+2*a[i-1]+1+2*a[i-1])%1000000007;
    }
    printf("%lld",b[n]);
    return 0;
}*/
//4-7 초보들의 하노이 타워
/*#include<stdio.h>
#include<iostream>
using namespace std;
long long int n,m,p3[10],dp[1005][10000],visit[1005][10000];
long long int dfs(long long int Hanoi,long long int time)
{
    if(visit[Hanoi][time])
    {
        return dp[Hanoi][time];
    }
    else{
    if(time>m)
    {
        visit[Hanoi][time]=1;
        dp[Hanoi][time]=0;
        return 0;
    }
    if(Hanoi==p3[n]-1)
    {
        visit[Hanoi][time]=1;
        dp[Hanoi][time]=1;
        return 1;
    }
    else
    {
        long long int a[10],top[3]={6,6,6};
        long long int H=Hanoi;
        for(int i=1;i<=n;i++)
        {
            a[i]=Hanoi%3;
            Hanoi/=3;
        }
        for(int i=n;i>=1;i--)
        {
            top[a[i]]=i;
        }
        long long int ret=0;
        for(int i=0;i<=2;i++)
        {
            for(int j=0;j<=2;j++)
            {
                if((top[i]!=6)&&(i!=j)&&(top[i]<top[j]))
                {
                    a[top[i]]=j;
                    long long int Han=0;
                    for(int k=n;k>=1;k--)
                    {
                        Han=Han*3+a[k];
                    }
                    ret+=dfs(Han,time+1);
                    ret%=1000000007;
                    a[top[i]]=i;
                }
            }
        }
        visit[H][time]=1;
        dp[H][time]=ret;
        return ret;
    }
}}
int main()
{
    scanf("%lld %lld",&n,&m);
    p3[0]=1;
    for(int i=1;i<=n;i++)
    {
        p3[i]=p3[i-1]*3;
    }
    printf("%lld",dfs((long long int)0,(long long int)0));
    return 0;
}*/
//4-8 4기둥 L
/*#include<stdio.h>
long long int a[130],b[130],k;
long long int f(long long int n)
{
    long long int i;
    if(n==0)
    {
        return 0;
    }
    if(b[n]!=0)
    {
        return b[n];
    }
    else
    {
        long long int s=10000000000,tempt=0;
        for(i=n/2;i<n;i++)
        {
            tempt+=2*f(i)+a[n-i];
            if(tempt<s)
            {
                s=tempt;
            }
            tempt=0;
        }
        b[n]=s;
        return b[n];
    }
}
int main()
{
    long long int i;
    scanf("%lld",&k);
    a[0]=0;
    for(i=1;i<=k+2;i++)
    {
        a[i]=a[i-1]*2+1;
    }
    printf("%lld",f(k));
    return 0;
}*/
//5-1 문자열 뒤집기
/*#include<stdio.h>
#include<iostream>
#include<stack>
#include<string.h>
using namespace std;
stack <char> q;
char a[100];
int main()
{
    fgets(a,50,stdin);
    for(int i=0;i<strlen(a);i++)
    {
        q.push(a[i]);
    }
    for(int i=0;i<strlen(a);i++)
    {
        printf("%c",q.top());
        q.pop();
    }
    return 0;
}*/
//5-2 bad hair day
/*#include<stdio.h>
#include<iostream>
#include<stack>
using namespace std;
stack <long long int> q;
long long int n,a[100000],sum=0,k=0;
int main()
{
    scanf("%lld",&n);
    for(long long int i=0;i<n;i++)
    {
        scanf("%lld",&a[i]);
    }
    while(1)
    {
        if(q.size()==0)
        {
            q.push(a[k]);
            k++;
        }
        else if(q.top()<=a[k])
        {
            q.pop();
        }
        else
        {
            sum+=q.size();
            q.push(a[k]);
            k++;
        }
        if(k>=n)
        {
            break;
        }
    }
    printf("%lld",sum);
}
*/
//5-3 괄호 문자열
/*#include<stdio.h>
#include<iostream>
#include<stack>
#include<string.h>
#include<stdlib.h>
using namespace std;
stack <char> q;
char x[1000];
int k=0,check=0;
int main()
{
    scanf("%s",x);
    while(1)
    {
        if((k==strlen(x))&&((check==1)||(q.size()==1)))
        {
            break;
        }
        if(q.empty())
        {
            q.push(x[k]);
            k++;
        }
        if(q.size()>=2)
        {
            char first,second;
            first=q.top();
            q.pop();
            second=q.top();
            q.pop();
            //printf("%c %c\n",second, first);
            if((second=='(')&&(first==')'))
            {
                if(q.empty())
                {
                   check=1;
                }
            }
            else
            {
                q.push(second);
                q.push(first);
                check=1;
            }

        }
        if(((check==1)||(q.size()<=1))&&(k<strlen(x)))
        {
            q.push(x[k]);
            k++;
            check=0;
        }
        else{}
    }
    if(q.empty())
    {
        printf("YES");
    }
    else
    {
        printf("NO");
    }
    return 0;
}
*/
//5-4 stack
/*#include<stdio.h>
#include<iostream>
#include<string.h>
#include<stack>
using namespace std;
stack <int> q;
int n,a[1000005],cnt=1,cnta=0;
char ans[1000005];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(int i=1 ;i<=n;i++)
    {
        if(a[i]>=cnt)
        {
            for(int j=cnt;j<=a[i];j++)
            {
                q.push(cnt);
                cnt++;
                ans[cnta]='+';

                cnta++;
            }
             q.pop();
             ans[cnta]='-';

             cnta++;
        }
        else
        {
            if(a[i]<cnt)
            {
                if(q.top()==a[i])
                {
                    q.pop();
                    ans[cnta]='-';
                    cnta++;
                }
                else
                {
                    printf("NO");
                    return 0;
                }
            }
        }
    }
    for(int i=0;i<cnta;i++)
    {
        printf("%c\n",ans[i]);
    }
    return 0;
}
*/
//5-5 후위 표현식 1
/*#include<stdio.h>
#include<iostream>
#include<stack>
#include<string.h>
using namespace std;
stack <char> q;
char a[1000000],ans[100000];
int anst=0;
int check(char k)
{
    if((k=='+')||(k=='-'))
    {
        return 2;
    }
    else if((k=='/')||(k=='*'))
    {
        return 3;
    }
    else
    {
        return -1;
    }
}
int main()
{
    scanf("%s",a);
    for(int i=0;i<strlen(a);i++)
    {
        if(check(a[i])==-1)
        {
            ans[anst]=a[i];
            anst++;
        }
        else
        {
            while(1)
            {
                if((!q.empty())&&(check(q.top())>=check(a[i])))
                {
                    ans[anst]=q.top();
                    anst++;
                    q.pop();
                }
                else
                {
                    break;
                }
            }
            q.push(a[i]);
        }
    }
    while(!q.empty())
    {
        ans[anst]=q.top();
        anst++;
        q.pop();
    }
    for(int i=0;i<anst;i++)
    {
        printf("%c",ans[i]);
    }
    return 0;
}*/
//5-6후위 표현식 2
/*#include<stdio.h>
#include<iostream>
#include<stack>
#include<string.h>
using namespace std;
stack <char> q;
char a[1000000],ans[100000];
int anst=0;
int check(char k)
{
    if((k=='+')||(k=='-'))
    {
        return 2;
    }
    else if((k=='/')||(k=='*'))
    {
        return 3;
    }
    else if((k=='(')||(k==')'))
    {
        return 1;
    }
    else
    {
        return -1;
    }
}
int main()
{
    scanf("%s",a);
    for(int i=0;i<strlen(a);i++)
    {
        if(check(a[i])==-1)
        {
            ans[anst]=a[i];
            anst++;
        }
        else
        {
            if(a[i]=='(')
            {
                q.push(a[i]);
            }
            else if(a[i]==')')
            {
                while(!(q.top()=='('))
                {
                    ans[anst]=q.top();
                    anst++;
                    q.pop();
                }
                q.pop();
            }
            else
            {
                while(1)
                {
                    if((!q.empty())&&(check(q.top())>=check(a[i])))
                    {
                        ans[anst]=q.top();
                        anst++;
                        q.pop();
                    }
                    else
                    {
                        break;
                    }
                }
                q.push(a[i]);
            }

        }
    }
    while(!q.empty())
    {
        ans[anst]=q.top();
        anst++;
        q.pop();
    }
    for(int i=0;i<anst;i++)
    {
        printf("%c",ans[i]);
    }
    return 0;
}*/
//5-7 수식 계산 1
/*#include<stdio.h>
#include<iostream>
#include<stack>
#include<string.h>
using namespace std;
char a[100000];
int main()
{
    scanf("%s",a);
    long long int cnt=0,now=0,last=1;
    for(long long int i=0;i<strlen(a);i++)
    {
        if(a[i]=='+')
        {
            if(last==1)
            {
                cnt+=now;
                now=0;
                last=1;
            }
            if(last==0)
            {
                cnt-=now;
                now=0;
                last=1;
            }
        }
        else if(a[i]=='-')
        {
            if(last==1)
            {
                cnt+=now;
                now=0;
                last=0;
            }
            if(last==0)
            {
                cnt-=now;
                now=0;
                last=0;
            }
        }
        else
        {
            now*=10;
            now+=(long long int)(a[i]-'0');
        }
    }
    if(last==1)
    {
        cnt+=now;
    }
    if(last==0)
    {
        cnt-=now;
    }
    printf("%lld",cnt);
    return 0;
}*/
//5-8 괄호
/*#include<stdio.h>
#include <iostream>
#include<stack>
using namespace std;
stack<int> st;
char arr[50];
int main()
{
    cin>>arr;
    for(int i=0; arr[i]!=0; i++)
    {
        if(!st.empty() && (st.top()+1==arr[i] || st.top()+2==arr[i])) st.pop();
        else st.push(arr[i]);
    }
    if(!st.empty())
    {
        printf("0");
        return 0;
    }

    for(int i=0; arr[i]!=0; i++)
    {
        if(!st.empty() && arr[i]==')' || arr[i]==']')
        {
            int tmp=0;
            while(!st.empty() && !(st.top()=='(' || st.top()=='['))
            {
                tmp+=st.top();
                st.pop();
            }

            if(tmp==0) tmp++;
            tmp*=(st.top()=='(' ? 2:3);
            st.pop();
            st.push(tmp);
        }
        else st.push(arr[i]);
    }

    while(st.size()!=1)
    {
        int tmp=st.top();
        st.pop();
        st.top()+=tmp;
    }

    cout<<st.top();
    return 0;
}*/
//6-1 숫자 생성 머신
/*#include<stdio.h>
#include<iostream>
#include<queue>
using namespace std;
queue <long long int> q;
long long int n,m,k,cnt=2,a[1000005];
int main()
{
    scanf("%lld %lld %lld",&n,&m,&k);
    q.push(n);
    q.push(m);
    a[0]=n;
    a[1]=m;
    while(cnt<=k)
    {
        long long int f1,f2;
        f1=q.front();
        q.pop();
        q.push(f1*n%1000000007);
        a[cnt]=f1*n%1000000007;
        q.push(f1*m%1000000007);
        a[cnt+1]=f1*m%1000000007;
        cnt+=2;
    }
    printf("%lld",a[k-1]);
    return 0;
}*/
//6-2 백신 1차원
/*#include<stdio.h>
long long int m,n,a[10010000],q[10001000],st=0,end=0;
void push(long long int k)
{
    q[end]=k;
    end++;
}
void pop()
{
    q[st]=0;
    st++;
}
int main()
{
    scanf("%lld %lld",&m,&n);
    long long int t;
    for(long long int i=0; i<n; i++)
    {
        scanf("%lld",&t);
        a[t]=1;
        push(t);
    }
    while(st!=end)
    {
        if((q[st]+1<=m)&&(a[q[st]+1]==0))
        {
            a[q[st]+1]=a[q[st]]+1;
            push(q[st]+1);
        }
        if((q[st]-1>=1)&&(a[q[st]-1]==0))
        {
            a[q[st]-1]=a[q[st]]+1;
            push(q[st]-1);
        }
        pop();
    }
    for(long long int i=1; i<=m; i++)
    {
        printf("%lld ",a[i]);
    }
}
*/
//6-3 백신 2차원
//6 생략
//7-1 이진트리의 전위순회 중 후
/*#include<stdio.h>
#include<iostream>
using namespace std;
char x[10000];
int cnt=1,n;
void dfs(int node)
{
    if(2*node<=n)
    {
        dfs(2*node);
    }
printf("%c ",x[node-1]);
    if(2*node+1<=n)
    {
        dfs(2*node+1);
    }
    return;
}
int main()
{
    scanf("%d",&n);
    scanf("%s",x);
    dfs(1);
}*/
// 7-4  트리의 수
/*#include<stdio.h>
#include<iostream>
using namespace std;
int a[100],n;
int main()
{
    scanf("%d",&n);
    a[0]=1;
    a[1]=1;
    for(int i=2;i<=n;i++)
    {
        int sum=0;
        for(int j=0;j<=i-1;j++)
        {
            sum+=a[j]*a[i-1-j];
        }
        a[i]=sum;
    }
    printf("%d",a[n]);
    return 0;
}*/
//카테시안 트리
/*#include<stdio.h>
#include<iostream>
using namespace std;
int x[10000],cnt=1,n;
void dfs(int node)
{
    if(2*node<=n)
    {
        dfs(2*node);
    }
printf("%d ",x[node-1]);
    if(2*node+1<=n)
    {
        dfs(2*node+1);
    }
    return;
}
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&x[i]);
    }
    dfs(1);
    return 0;
}*/
/*
#include<stdio.h>
#include<iostream>
using namespace std;
long long int dp[300][300],n,h;
int main()
{
    scanf("%lld %lld",&n,&h);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=100;j++)
        {
            if(j==1)
            {
                if(i==1)
                {
                    dp[i][j]=1;
                }
                if(i==0)
                {
                    dp[i][j]=0;
                }
            }
            else
            {
                for(int x=1; x<=i-1; x++)
                {
                    for(int y=0; y<=j-1; y++)
                    {
                        dp[i][j]+=(dp[x][y]*dp[i-1-x][j-1]+dp[x][j-1]*dp[i-1-x][y])%9901;
                    }
                    dp[i][j]-=dp[x][j-1]*dp[i-1-x][j-1]%9901;
                    if( dp[i][j]<0)
                    {
                         dp[i][j]+=9901;
                    }
                }

            }

        }
    }
    printf("%lld",dp[n][h]%9901);
    return 0;
}
*/
/*#include<stdio.h>
#include<iostream>
using namespace std;
int p,ns,t,a,b,c,Map[1000000];
void f(int w,int e)
{
    if(w==1)
    {
        printf("%d\n1\n",e);
    }
    else
    {
        f(Map[w],e+1);
        printf("%d\n",w);
    }
    return;
}
int main()
{
    scanf("%d %d %d",&p,&ns,&t);
    for(int i=0;i<ns;i++)
    {
        scanf("%d %d %d",&a,&b,&c);
        Map[b]=a;
        Map[c]=a;
    }
    f(t,1);
    return 0;
}*/
/*#include<stdio.h>
#include<iostream>
#include<queue>
#define INF 92000000
using namespace std;
struct node{ int e,m;};
struct node2{ int end1,mon;};
bool operator<(const node2& A,const node2& B){return A.mon>B.mon;}
priority_queue <node2> q;
vector< vector<node> > adj;
vector <long long int > length;
int v[100005],n,m,a,b,c;
int main()
{
    scanf("%d %d",&n,&m);
    adj.resize(n+5);length.resize(n+5,INF);
    for(int i=0;i<m;i++)
    {
        scanf("%d %d %d",&a,&b,&c);
        adj[a].push_back({b,c});
        adj[b].push_back({a,c});
    }

    length[1]=1;
    q.push({1,0});
    while(!q.empty())
    {
        int f1,f2;
        f1=(q.top()).end1;
        f2=(q.top()).mon;
        v[f1]=1;
        q.pop();
        if(length[f1]<f2) continue;
        else
        {
            length[f1]=f2;
            for(auto i: adj[f1])
            {
                if(v[i.e]==0)
                {q.push({i.e,i.m+length[f1]});}
            }
        }
    }
    long long int max1=0,indexi,indenmant=0;
    for(long long int i=1;i<=n;i++)
    {
        if(length[i]>max1)
        {
            max1=length[i];
        }
    }
    for(long long int i=n;i>=1;i--)
    {
        if(max1==length[i])
        {
            indexi=i;
            indenmant++;
        }
    }
    printf("%lld %lld",indexi,indenmant);
    return 0;
}*/
/*#include<stdio.h>
#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
queue <int> q;
vector<vector <int> > adj;
int n,m,v[100000];

int main()
{
    scanf("%d %d",&n,&m);
    int a,b;
    adj.resize(n+5);
    for(int i=0;i<m;i++)
    {
        scanf("%d %d",&a,&b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    /*for(int i=1;i<=n;i++)
    {
        sort(adj[i].begin(),adj[i].end());
    }*/
    /*q.push(1);
    v[1]=1;
    while(q.size())
    {
        int k=q.front();
        q.pop();
        printf("%d ",k);
        for(auto i: adj[k])
        {
            if(v[i]==0)
            {
                v[i]=1;
                q.push(i);
            }
        }
    }
    return 0;
}*/
#include<stdio.h>
int main()
{
    for(int i=1;i<=99;i++)
    {
        printf("%d  %d\n\n",i,i*99);
    }
}

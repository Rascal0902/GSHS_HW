//11-1
/*#include<stdio.h>
#include<iostream>
#include<set>
using namespace std;
int n;
set <int> s;
int main()
{
    scanf("%d",&n);
    int t;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&t);
        s.insert(t);
    }
    printf("%d",s.size());
    return 0;
}*/
//11-2
/*#include<stdio.h>
#include<iostream>
#include<set>
#include<string.h>
using namespace std;
int n;
char a[100];
set <string> s;
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%s",a);
        s.insert(a);
    }
    printf("%d",s.size());
    return 0;
}*/
//11-3
/*#include<stdio.h>
#include<iostream>
#include<set>
#include<algorithm>
using namespace std;
int n,m,t;
set <int> s;
int main()
{
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&t);
        s.insert(t);
    }
    for(int i=0;i<m;i++)
    {
        scanf("%d",&t);
        s.insert(t);
    }
    for(auto it=s.begin(); it!=s.end();++it)
    {
        printf("%d ",*it);
    }
    return 0;
}*/
//11-4
/*#include<stdio.h>
#include<iostream>
#include<set>
#include<algorithm>
using namespace std;
long long int n,m,t;
set <long long int> s;
int main()
{
    scanf("%lld %lld",&n,&m);
    for(long long int i=0;i<n;i++)
    {
        scanf("%lld",&t);
        s.insert(t);
    }
    for(long long int i=0;i<m;i++)
    {
        scanf("%lld",&t);
        s.erase(t);
    }
    if(s.size()==0)
    {
        printf("-1");
    }
    else
    {
         for(auto it=s.begin(); it!=s.end();++it)
         {
           printf("%lld ",*it);
          }
    }

    return 0;
}
*/
//11-5
/*#include<stdio.h>
#include<iostream>
#include<set>
using namespace std;
multiset <int> s;
int n,m;
int main()
{
    scanf("%d",&n);
    int t;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&t);
        s.insert(t);
    }
    scanf("%d",&m);
    for(int i=0;i<m;i++)
    {
        scanf("%d",&t);
        printf("%d ",s.count(t));
    }
    return 0;
}
*/
//11-6
/*#include<stdio.h>
#include<iostream>
#include<set>
using namespace std;
multiset <int> s;
set <int> go;
long long int n,t,sum=0,cnt=1,ans=0;
int main()
{
    scanf("%lld",&n);
    s.insert(0);
    go.insert(0);
    for(long long int i=0;i<n;i++)
    {
        scanf("%lld",&t);
        sum+=t;
        s.insert(sum);
        go.insert(sum);
    }
    for(auto it=go.begin(); it!=go.end();++it)
    {
           ans+=(long long int)(s.count(*it)*(s.count(*it)-1))/2;
    }
    printf("%lld",ans);
    return 0;
}
*/
//11-7
/*#include<stdio.h>
#include<iostream>
using namespace std;
int n,t;
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&t);
    }
}*/
//11-8
/*#include<stdio.h>
#include<iostream>
#include<set>
#include<algorithm>
#include<climits>
using namespace std;
set<pair<long long int,long long int> > s;
long long int n,t,sum=0,m;
signed main()
{
    scanf("%lld %lld",&n,&m);
    s.insert({0, -1});
    for(long long int i=0;i<n;i++)
    {
        scanf("%lld",&t);
        sum+=t;
        s.insert({sum, i});
    }
    auto it = s.upper_bound({s.begin() -> first + m, INT_MAX});
    it--;
    while(it -> second < s.begin() -> second){it--;}
    long long int ans=(*it).first;
    s.erase(s.begin());
    while(!s.empty()){
        pair<long long int,long long int> p;
        p=make_pair(*(s.begin()).first,(*(s.begin()).second);
        break;}
        s.erase(s.begin());
        if(s.empty()){break;}
        it= s.begin();
        while(it != s.end()){if(it -> first > p.first + m){break;}it++;}
        it--;
        while(it -> second < p.second){it--;}
        ans = max(ans, it -> first - p.first);
    }
    cout << ans;
    return 0;
}*/
/*#include<stdio.h>
#include<iostream>
#include<set>
using namespace std;
set <int> s, _s;
int a[10]={5,4,6,7,8,9,10,2,3,1};
int main()
{

    for(int i=0;i<10;i++)
    {
        s.insert(a[i]);
    }
    for(auto it=s.begin();it!=s.end();it++)
    {
        printf("%d ",*it);
    }
    puts("");
    s.erase(10);
    for(auto it=s.begin();it!=s.end();it++)
    {
        printf("%d ",*it);
    }
    s.insert(10);
    printf("\n%d",*s.rbegin());
    printf("\n%d",*s.begin());
    printf("\n%d",*s.lower_bound(5));
    printf("\n%d",*s.upper_bound(5));
    printf("\n%d",s.size());
    printf("\n%d",!s.empty());
    s.swap(_s);
    printf("\n%d",_s.empty());
    s.swap(_s);

}*/
/*#include<stdio.h>
#include<iostream>
#include<set>
using namespace std;
multiset <int> s, _s;
int a[10]={1,1,1,2,2,3,4,7,6,5};
int main()
{

    for(int i=0;i<10;i++)
    {
        s.insert(a[i]);
    }
    for(auto it=s.begin();it!=s.end();it++)
    {
        printf("%d ",*it);
    }
    puts("");
    s.erase(7);
    for(auto it=s.begin();it!=s.end();it++)
    {
        printf("%d ",*it);
    }
    puts("");
    s.insert(7);

    s.erase(s.find(1));
    cout << s.size() << '\n';
    cout << s.count(2) << '\n';
    cout << (s.find() != s.end());

}*/
/*#include<stdio.h>
#include<iostream>
#include<map>
#include<string>
using namespace std;
map <string, int> m;
string s[5] = {"apple", "banana", "pineapple", "fuck", "sibal"};
int main()
{
    for(int i = 0; i < 5; i++) m[s[i]] = i + 1;

    cout << m["fuck"] <<'\n';
    cout << m["fuckkkk"] <<'\n';
    cout << m.at("fuck") <<'\n';
*/
   /* v.at(3) v[3]*/

  /*  cout << m.begin() -> first << '\n';
    cout << m.rbegin() -> first <<'\n';

    m.erase("apple");
    cout << m["apple"] <<'\n';

    cout << m.upper_bound("banana") -> first;
}
*/
/*#include<stdio.h>
#include<iostream>
#include<map>
using namespace std;
long long int n,a[1000005];
map <unsigned long long int,long long int> s;
void f(unsigned long long int k)
{
    if(s[2*k]!=0)
    {
        f(2*k);
    }
    printf("%lld ",s[k]-1);
    if(s[2*k+1]!=0)
    {
        f(2*k+1);
    }
    return ;
}
int main()
{
    scanf("%lld",&n);
    unsigned long long int k=1;
    scanf("%lld",&a[0]);
    s[k]=a[0]+1;
    for(long long int i=1;i<n;i++)
    {
        scanf("%lld",&a[i]);
        if(s[k]>=a[i]+1)
        {
            s[(2*k)]=a[i]+1;
            k*=2;
        }
        else
        {
            s[(2*k+1)]=a[i]+1;
            k=2*k+1;
         }
    }
    f(1);
    return 0;
}*/
/*#include<stdio.h>
#include<iostream>
#include<map>
using namespace std;
long long int n,a[1000005],low=1000005,high=1000006,ans[2000010];
int main()
{
    scanf("%lld",&n);
    for(long long int i=0;i<n;i++)
    {
        scanf("%lld",&a[i]);
    }
    ans[low]=a[n-1];
    for(int i=n-2;i>=0;i--)
    {
        if(a[i]>a[i+1])
        {
            ans[high]=a[i];
            high++;
        }
        else
        {
            ans[low-1]=a[i];
            low--;
        }
    }
    for(int i=low;i<high;i++)
    {
        printf("%lld ",ans[i]);
    }
    return 0;
}*/
/*#include <stdio.h>
#include <iostream>
using namespace std;
long long int gcd(long long int a, long long int b);
int a[15000005];
int main() {
    long long int n;
    scanf("%lld",&n);
    long long int MAXLEN=n;
    long long int count1 = 0;
    for(long long int s = 1 ; s<= MAXLEN ; s+=2 )
    {
           for(long long int t = 1 ; t < s ; t +=2 ) {
           if( gcd(s, t) != 1 )  continue;
           long long int len = s*s + s*t;
           if( len > MAXLEN ) break;
            else{for(int i=len;i<=MAXLEN;i+=len)
                {
                    a[i]++;
                }
            }
        }
    }
    for(int i=1;i<=MAXLEN;i++)
    {
        if(a[i]==1)
        {
            count1++;
        }
    }
    printf("%lld",count1);
    return 0;
}
long long int gcd(long long int a, long long int b)
{ while( b )
{ long long int t = b; b = a%b; a = t; }
   return a; }

/*#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<iostream>
#include<map>
using namespace std;
struct RANGE{long long int a[3][3];};
map<long long int,RANGE > s;
long long int n;
RANGE operator*(RANGE A,RANGE B){
    RANGE ret;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            long long int sum=0;
            for(int k=0;k<3;k++){
                sum+=(A.a[i][k]*B.a[k][j]+1000000)%1000000;
                sum%=1000000;
            }
            ret.a[i][j]=sum;
        }}
    return ret;}
RANGE f(long long int k){
    if(k==1){return s[1];}
    else if(k%2==0){RANGE ck=f(k/2);
            return ck*ck;}
    else{RANGE ck=f(k/2);return s[1]*ck*ck;}}
int main(){
    scanf("%lld",&n);
    s[1]={0,1,0,0,0,1,-1,1,3};
    if(n==1){
        printf("%lld",3-1);
        return 0;}
    else if(n==2){
        printf("%lld",10-3);
        return 0;}
    else if(n==3){
        printf("%lld",32-10);}
    else
    {RANGE ans=f(n-3);
    printf("%lld",((ans.a[2][0]*3+ans.a[2][1]*10+ans.a[2][2]*32)%1000000-(ans.a[1][0]*3+ans.a[1][1]*10+ans.a[1][2]*32)%1000000+1000000)%1000000);
    return 0;}
}
*/
/*#include <stdio.h>
#include <deque>
using namespace std;
deque <int> dq[201];
int n,arr[200001],sum[201][200001];
int maxx;
int f(int x, int y)
{
    int temp[200001]={0},tempmax=0;
    for(int i=1 ; i<=200 ; i++)
    {
        temp[i]=sum[i][y-1]-sum[i][x];
        if(tempmax<temp[i])
            tempmax=temp[i];
    }
    return tempmax;
}
int main()
{
    scanf("%d",&n);
    for(int i=1 ; i<=n ; i++)
    {
        scanf("%d",&arr[i]);
        dq[arr[i]].push_back(i);
        for(int j=1 ; j<=200 ; j++)
            sum[j][i]=sum[j][i-1];
        sum[arr[i]][i]++;
    }
    for(int i=1 ; i<=200 ; i++)
    {
        if(maxx<sum[i][n])
            maxx=sum[i][n];
    }
    for(int i=1 ; i<=200 ; i++)
    {
        int cnt=0;
        while(dq[i].size()>=2)
        {
            cnt++;
            int a=f(dq[i].front(),dq[i].back());
            dq[i].pop_back();
            dq[i].pop_front();
            if(maxx<cnt+cnt+a)
                maxx=cnt+cnt+a;
        }
    }
    printf("%d",maxx);
    return 0;
}*/
/*#include <stdio.h>
#include <set>
using namespace std;
int arr[200001],n,m,maxx,sum[200001];
set <int> s;
set <int>::iterator it;
int main()
{
    scanf("%d %d",&n,&m);
    for(int i=1 ; i<=n ; i++)
    {
        scanf("%d",&arr[i]);
        sum[i]=sum[i-1]+arr[i];
    }
    for(int i=1 ; i<=n ; i++)
    {
        s.insert(sum[i-1]);
        it=s.lower_bound(sum[i]-m);
        //printf("%d %d\n",sum[i]-m,*it);
        if(maxx<sum[i]-*it && it!=s.end())
            maxx=sum[i]-*it;

    }
    printf("%d",maxx);
    return 0;
}*/
/*#include<stdio.h>
#include<iostream>
#include<set>
#include<string>
using namespace std;
set <string> s;
int n;
char x[1000000];
int main()
{
    scanf("%d",&n);
    int t;
    for(int i=0;i<n;i++)
    {
        scanf("%s",x);
        s.insert(x);
    }
    printf("%d",s.size());
    return 0;
}
*/
/*#include<stdio.h>
#include<iostream>
using namespace std;
long long int n,cnt=0;
int main()
{
    scanf("%lld",&n);

    while(1)
    {
        if(n==0)
        {
            break;
        }
        if(n%2==1)
        {
            cnt++;
        }
        n=n>>1;
    }
    printf("%lld",cnt);
    return 0;
}*/
#include<stdio.h>
#include<iostream>
#include<set>
using namespace std;
set <int> s;
set <int> :: iterator;
int n,m,t=0,a[200005],b[2000005];
int main()
{
    scanf("%d %d",&n,&m);
    s.insert(0);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);

    }
    for(int i=1;i<=n;i++)
    {

    }
}

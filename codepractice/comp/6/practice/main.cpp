/*#include<stdio.h>
#include<iostream>
#include<stack>
using namespace std;
stack <int> q;
int main()
{
    q.push(1);
    q.push(100);
    q.push(5);
    printf("%d\n",q.size());
    while(!q.empty())
    {
        printf("%d ",q.top());
        q.pop();
    }
    return 0;
}*/
/*#include<stdio.h>
#include<iostream>
#include<stack>
using namespace std;
stack <int> q;
int main()
{
    q.push(1);
    q.push(100);
    q.push(5);
    printf("%d\n",q.size());
     for(int i=0;i<3;i++)
     {
        printf("%d ",q.top());
        q.pop();
    }
    return 0;
}*/
/*#include<stdio.h>
#include<iostream>
#include<stack>
#include<utility>
using namespace std;
stack <pair<int,int> > q;
int main()
{
    q.push({1,1});
    q.push({1,2});
    q.push({1,3});
    printf("%d\n",q.size());
     for(int i=0;i<3;i++)
     {
        printf("%d %d\n",q.top().first,q.top().second);
        q.pop();
    }
    return 0;
}*/
/*#include<stdio.h>
#include<iostream>
#include<stack>
#include<utility>
using namespace std;
stack <pair<int, pair<int,int> > > q;
int main()
{
    q.push({1,{1,1}});
    q.push({1,{2,3}});
    q.push({1,{3,4}});
    printf("%d\n",q.size());
     for(int i=0;i<3;i++)
     {
        printf("%d %d\n",q.top().first,(q.top().second).first);
        q.pop();
    }
    return 0;
}*/
/*#include<stdio.h>
#include<iostream>
#include<queue>
#include<utility>
using namespace std;
queue <int> q;
int main()
{
    q.push(1);
    q.push(100);
    q.push(5);
    printf("%d\n",q.size());
    while(!q.empty())
    {
        printf("%d ",q.front());
        q.pop();
    }
    return 0;
}*/
/*#include<stdio.h>
#include<iostream>
#include<queue>
#include<utility>
using namespace std;
queue <pair<int, int> > q;
int main()
{
    q.push({1,3});
    q.push({3,5});
    q.push({5,7});
    printf("%d\n",q.size());
    while(!q.empty())
    {
        printf("%d %d\n",(q.front()).first,(q.front()).second);
        q.pop();
    }
    return 0;
}
*/
/*#include<stdio.h>
#include<iostream>
#include<queue>
#include<utility>
using namespace std;
queue <int> q,q2;
int main()
{
    q.push(1);
    q.push(100);
    q.push(5);
    q.push(4);
    q.push(6);
    q2=q;
    printf("%d\n",q.size());
    while(!q.empty())
    {
        printf("%d ",q.front());
        q.pop();
    }
    printf("\n\n");
    q2.pop();
    q=q2;
    while(!q.empty())
    {
        printf("%d ",q.front());
        q.pop();
    }
    printf("\n\n");
    q2.pop();
    q=q2;
    while(!q.empty())
    {
        printf("%d ",q.front());
        q.pop();
    }
     printf("\n\n");
    q2.pop();
    q=q2;
    while(!q.empty())
    {
        printf("%d ",q.front());
        q.pop();
    }
     printf("\n\n");
    q2.pop();
    q=q2;
    while(!q.empty())
    {
        printf("%d ",q.front());
        q.pop();
    }
    return 0;
}*/
/*#include<stdio.h>
#include<iostream>
#include<queue>
#include<utility>
using namespace std;
priority_queue <int> q,q2;
int main()
{
    q.push(1);
    q.push(100);
    q.push(5);
    q.push(4);
    q.push(6);
    q2=q;
    printf("%d\n",q.size());
    while(!q.empty())
    {
        printf("%d ",q.top());
        q.pop();
    }
    printf("\n\n");
    q2.pop();
    q=q2;
    while(!q.empty())
    {
        printf("%d ",q.top());
        q.pop();
    }
    printf("\n\n");
    q2.pop();
    q=q2;
    while(!q.empty())
    {
        printf("%d ",q.top());
        q.pop();
    }
     printf("\n\n");
    q2.pop();
    q=q2;
    while(!q.empty())
    {
        printf("%d ",q.top());
        q.pop();
    }
     printf("\n\n");
    q2.pop();
    q=q2;
    while(!q.empty())
    {
        printf("%d ",q.top());
        q.pop();
    }
    return 0;
}
*/
/*#include<stdio.h>
#include<iostream>
#include<queue>
#include<utility>
using namespace std;
struct Range
{
    int a;
};
typedef struct Range Range;
struct compare
{
    bool operator()(Range &A,Range &B){

    if(A.a<B.a)
    {
        return A.a>B.a;
    }
    return A.a>B.a;
    }
};
priority_queue <Range,vector<Range>,compare> q,q2;
int main()
{
    q.push({1});
    q.push({100});
    q.push({5});
    q.push({3});
    q.push({6});
    q2=q;
    printf("%d\n",q.size());
    while(!q.empty())
    {
        printf("%d ",q.top());
        q.pop();
    }
    printf("\n\n");
    q2.pop();
    q=q2;
    while(!q.empty())
    {
        printf("%d ",q.top());
        q.pop();
    }
    printf("\n\n");
    q2.pop();
    q=q2;
    while(!q.empty())
    {
        printf("%d ",q.top());
        q.pop();
    }
     printf("\n\n");
    q2.pop();
    q=q2;
    while(!q.empty())
    {
        printf("%d ",q.top());
        q.pop();
    }
     printf("\n\n");
    q2.pop();
    q=q2;
    while(!q.empty())
    {
        printf("%d ",q.top());
        q.pop();
    }
    return 0;
}
*/
/*
#include<stdio.h>
#include<iostream>
#include<queue>
#include<utility>
using namespace std;
struct Range
{
    int a;
};
bool operator<(Range A,Range B)
{
    return A.a>B.a;
}
priority_queue <Range> q,q2;
int main()
{
    q.push({1});
    q.push({100});
    q.push({5});
    q.push({3});
    q.push({6});
    q2=q;
    printf("%d\n",q.size());
    while(!q.empty())
    {
        printf("%d ",q.top());
        q.pop();
    }
    printf("\n\n");
    q2.pop();
    q=q2;
    while(!q.empty())
    {
        printf("%d ",q.top());
        q.pop();
    }
    printf("\n\n");
    q2.pop();
    q=q2;
    while(!q.empty())
    {
        printf("%d ",q.top());
        q.pop();
    }
     printf("\n\n");
    q2.pop();
    q=q2;
    while(!q.empty())
    {
        printf("%d ",q.top());
        q.pop();
    }
     printf("\n\n");
    q2.pop();
    q=q2;
    while(!q.empty())
    {
        printf("%d ",q.top());
        q.pop();
    }
    return 0;
}*/
#include <stdio.h>
#include <stack>
#include <queue>
#include <map>
#include <vector>
using namespace std;
struct RANGE{
    int s, e;
    RANGE(){s=0;e=0;}
    RANGE(int a,int b){s=a;e=b;}
    int distance(){
        return e-s;
    }
};
bool operator<(const RANGE a, const RANGE b){
    if(a.e-a.s==b.e-b.s){
        return a.s>b.s;
    }
    return a.e-a.s<b.e-b.s;
}
int main(){
    priority_queue<RANGE> pq;
    pq.push(RANGE(1,3));
    pq.push(RANGE(5,9));
    while(!pq.empty()){
        RANGE r = pq.top();
        RANGE x;
        printf("%d %d\n",r.s,r.e);
        pq.pop();
    }
}

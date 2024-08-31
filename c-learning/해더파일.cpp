//stl
/*#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int a[10]={3,4,7,6,5,1,2,9,8,0},i;
    sort(a,a+10);
    for(i=0;i<10;i++)
    {
        cout << a[i];
    }
    return 0;
}*/
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int a,b,c,d;
    cin >> a >> b;
    c=max(a,b);
    cout << c << ' ';
    d=min(a,b);
    cout << d;
    return 0;
}
/*#include<iostream>
#include<algorithm>
using namespace std;
bool F(int a,int b)
{
    return a>b;
}
int main()
{
    int a[10]={3,4,7,6,5,1,2,9,8,0},i;
    sort(a,a+10,F);
    for(i=0;i<10;i++)
    {
        cout << a[i];
    }
    return 0;

}*/
/*#include<iostream>
#include<vector>
using namespace std;
int main()
{   int i;
    vector <int> a;
   // a.reserve(8);     // 벡터 메모리 공간 8 예약 할당
    a.push_back (1);
    for(i=0;i<a.size();i++)
    {
        cout << a[i];
    }
    return 0;
}*/
/*#include<iostream>
#include<vector>
#include<utility>
using namespace std;
int main()
{
    int i;
    vector < pair <int,int> > a;
    a.push_back(pair<int,int>(1,5));
    a.push_back(pair<int,int>(2,4));
    for(i=0;i<a.size();i++)
    {
        cout << a[i].first<< a[i].second <<  "\n"  ;
    }
    pair<int, int> p1 = make_pair(25, 30);
    pair<int, int> p2 = make_pair(25, 30);
    pair<int, int> p3 = make_pair(25, 40);
    pair<int, int> p4 = make_pair(30, 30);

   cout << (p1 == p2) << endl; // true
   cout << (p1 < p3) << endl;  // true
   cout << (p1 < p4) << endl;  // true
    return 0;
}*/

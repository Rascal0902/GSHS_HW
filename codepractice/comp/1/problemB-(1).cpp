#include <iostream>

using namespace std;
int col[18];
int row[18];
int l[40], r[40];
int n;
int cnt;

void dfs(int lev)
{
    if(lev==n)
    {
        if(cnt<3)
        {
            for(int i=0; i<n; i++) cout<<row[i]<<" ";
            cout<<endl;
        }
        cnt++;
    }
    for(int i=0; i<n ;i++)
    {
        if(l[i+lev]==1 || r[n+i-lev]==1 || col[i]==1) continue;
        l[i+lev]=r[n+i-lev]=col[i]=1;
        row[lev]=i+1;
        dfs(lev+1);
        l[i+lev]=r[n+i-lev]=col[i]=0;
    }
}

int main()
{
    cin>>n;
    dfs(0);
    cout<<cnt<<endl;
    return 0;
}

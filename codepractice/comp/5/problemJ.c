#include<stdio.h>
typedef long long ll;
int n;
int arr[303030];
int dp[66][303030];// dp[x][s]=e : s~e-1까지 합치면 x가 나온다
int main()
{
    scanf("%d",&n);
    for(int i=1; i<=n; i++)
    {
          scanf("%d",&arr[i]);
    }
    for(int i=0; i<66; i++)
    {
        for(int j=1; j<=n; j++)  // i 라는 값을 j위치를 시작으로 만들 수 있는가 ?
        {
            if(arr[j] == i)
                dp[i][j] = j+1;
            else if(!i || !dp[i-1][j] || !dp[i-1][dp[i-1][j]])
                dp[i][j] = 0; // 없는 걸로 할거
            else
                dp[i][j] = dp[i-1][dp[i-1][j]];
        }
    }
    for(int i=65; i>=0; i--)
        for(int j=1; j<=n; j++)
        {
            if(dp[i][j])
            {
                printf("%d",i);
                return 0;
            }
        }
}

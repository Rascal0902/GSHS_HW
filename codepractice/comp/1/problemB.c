/*#include<stdio.h>
int b[20],end=0,n,a=1,sum=0,attempt=0;
void push(int k)
{
    b[end]=k;
    end++;
}
void pop()
{
    b[end-1]=0;
    end--;
}
void s(int k)
{
    int temp=0;
    int i,j;
    if(k==n)
    {
        sum+=1;
        attempt++;
        if(attempt<=3)
        {
            for(j=0; j<n; j++)
            {
                printf("%d ",b[j]+1);
            }
            printf("\n");
        }

        return;
    }
    else
    {
        for(i=0; i<n; i++)
        {
            a=1;
            for(j=0;j<end;j++)
            {
                if(i==b[j])
                {
                    a=0;
                }
                if(b[j]-i==k-j)
                {
                    a=0;
                }
                if(i-b[j]==k-j)
                {
                    a=0;
                }
            }
            if(a==1)
            {
                push(i);
                s(k+1);
                pop();
            }
            else
            {
                temp++;
            }


        }

    }
}
int main()
{
    int i,j;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        push(i);
        s(1);
        for(j=0; j<=end; j++)
        {
            b[j]=0;
        }
        end=0;
    }
    printf("%d",sum);
    return 0;
}*/
/*#include <cmath>

#define MAX_SIZE 8
// 최대 MAX_SIZE queen 문제까지 해결할 수 있다.

using namespace std;

int board[MAX_SIZE];
// board[i]는 i번째 행에 퀸이 몇번째 열에 있는지 의미하는 변수이다. (행열은 서로 바뀌어도 된다.)
// 즉 board[0] = 3일때, (1,4) 혹은 (4,1) 위치에 퀸이 있다는 뜻이다.
int n;
int cnt;

void path(int y) {
	// y는 현재 몇개의 퀸이 배치되었는지를 의미하는 변수다.
	int ko;
	if( y == n ) {
		// n개의 퀸이 배치가 되었다면 이 경우는 답이다.
		cnt++;
		return;
	}
	for( int i=0; i<n; i++ ) {
		// ko는 퀸이 배치될 수 있는지를 저장하는 플래그다.
		ko = 1;
		for( int j=0; j<y; j++ ) {
			// 이미 배치가 끝난 퀸을 참고해서 i번째 칸에 퀸을 설치할 수 있는지를 확인한다.
			if( board[j] == i || abs(y-j) == abs(i-board[j]) ) {
				// j번째 줄에 있는 퀸과 같은 칸에 있거나, 대각선에 같은 곳에 있다면, i번째 칸에 대한 탐색을 중단한다.
				ko = 0;
				break;
			}
		}
		if( ko ) {
			// 여기까지 왔다면 y번째 줄에 i번째 칸에 퀸을 놔두는 것이 가능하다.
			board[y] = i;
			path(y+1);
		}
	}
}

int main() {
	int k;
	cin >> k;

	while( k-- ) {
		cin >> n;
		cnt = 0;
		path(0);

		cout << cnt << '\n';
	}

	return 0;
}*/
#include <stdio.h>
int col[20],row[20],tr1[50],tr2[50],n,t=0;
void f(int k)
{
    if(k==n)
    {
        if(t<=2)
        {
            for(int i=0; i<n; i++)
            {
                printf("%d ",row[i]);
            }
            printf("\n");
        }
        t++;
    }
    for(int i=0; i<n ; i++)
    {
        if((tr1[i+k]==1)||(tr2[n+i-k]==1)||(col[i]==1))
        {
            continue;
        }
        tr1[i+k]=tr2[n+i-k]=col[i]=1;
        row[k]=i+1;
        f(k+1);
        tr1[i+k]=tr2[n+i-k]=col[i]=0;
    }
}
int main()
{
    scanf("%d",&n);
    f(0);
    printf("%d",t);
    return 0;
}

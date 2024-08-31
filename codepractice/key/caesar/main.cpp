/*#include<iostream>
#include<string.h>
#include<stdio.h>
using namespace std;
int n;
char a[100];
int main()
{
    scanf("%s",a);
    scanf("%d",&n);
    for(int i=0;i<strlen(a);i++)
    {
        a[i]=(char)(((int)(a[i]-'a')+n)%26+'a');
        printf("%c",a[i]);
    }
    return 0;
}*/
/*#include<iostream>
#include<string.h>
#include<stdio.h>
using namespace std;
int M,n, k,j;
long long int a[100];
int main()
{
    scanf("%d %d %d",&M,&n,&k);
    a[1]=M;
    for(int i=2;i<=k;i++)
    {
        a[i]=(a[i-1]*M)%n;
    }
    printf("%lld",a[k]);
}*/
/*#include<iostream>
#include<string.h>
#include<stdio.h>
using namespace std;
int a[10],b[10],n,m,a1;
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    scanf("%d %d",&m,&a1);
    for(int i=0;i<n;i++)
    {
        b[i]=(a[i]*a1)%m;
        printf("%d ",b[i]);
    }
    return 0;
}
*/
#include<stdio.h>
int main()
{
    printf("%d",28*13);
    return 0;
}

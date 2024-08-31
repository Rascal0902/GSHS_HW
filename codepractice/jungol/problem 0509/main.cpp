// 제곱근
/*#include<stdio.h>
#include<iostream>
using namespace std;
long long int N,ans;
long long int f(long long int n,long long int checklow,long long int checkhigh)
{
    long long int check=(checklow+checkhigh)/2;
    if(checklow>checkhigh)
    {
        return 1;
    }
    if((check*check<=n)&&((long long int)(n/(check+1))<check+1))
    {
        printf("%lld",check);
        return 0;
    }
    else if(check*check<n)
    {
        f(n,check+1,checkhigh);
        return 1;
    }
    else
    {
        f(n,checklow,check);
        return 1;
    }
}
int main()
{
    scanf("%lld",&N);
    f(N,0,3037000499);
    return 0;
}*/
//모자이크
/*#include<stdio.h>
#include<iostream>
using namespace std;
int row,col,want,much,a[1000003][3],b[2000003],c[2000003],rowmax=1;
int main()
{
    scanf("%d %d",&row,&col);
    scanf("%d",&want);
    scanf("%d",&much);
    for(int i=0;i<much;i++){
        scanf("%d %d",&a[i][0],&a[i][1]);
        if(rowmax<a[i][0])
        {
            rowmax=a[i][0];
        }
        c[a[i][1]]=1;
    }
    while(1){
        for(int i=1; i<=col; i++){ b[i]=c[i];}
        long long int wants=0,k;
        for(int i=1; i<=col; i++){
            if(b[i]==1){
                wants++;
                i+=rowmax-1;}}
        if(want<wants){
            k=2;
        }
        else{
            k=1;
        }
        if(k==1){
            break;
        }
        rowmax++;
    }
    printf("%d",rowmax);
    return 0;
}*/
//숫자 구슬
/*#include<stdio.h>
#include<iostream>
using namespace std;
int n,k,a[305],max=0;
int f(int m)
{

}
int main()
{
    scanf("%d %d",&n,&k);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        if(max<a[i])
        {
            max=a[i];
        }
    }
    while(1){

    }
    return 0;
}*/
//최댓값 기준으로 이분 탐색
//퀵 정렬
/*#include<stdio.h>
#include<iostream>
using namespace std;
int a[10010],n;
void f(int low,int high)
{
    if(low>=high)
    {
        return;
    }
    else
    {
       int pivot=a[high],i=low-1;
       for(int j=low;j<high;j++)
       {
           if(a[j]<pivot){swap(a[++i],a[j]);}
       }
       swap(a[++i],a[high]);
       for(int k=0;k<n;k++)
       {
         printf("%d ",a[k]);
       }
       printf("\n");
       f(low,i-1);
       f(i+1,high);
       return;
    }
}
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    f(0,n-1);
    return 0;
}*/
//합병 정렬
/*#include<stdio.h>
#include<iostream>
using namespace std;
int a[10010],b[10010],n;
void f(int low,int high)
{
    if(low>=high)
    {
        return;
    }
    else
    {
       int mid=(low+high)/2;
       f(low,mid);
       f(mid+1,high);
       int i=low,j=mid+1;
       for(int k=low;k<=high;k++)
       {
           if(j>high)
           {
               b[k]=a[i++];
           }
           else if(i>mid)
           {
               b[k]=a[j++];
           }
           else if(a[i]<=a[j])
           {
               b[k]=a[i++];
           }
           else
           {
               b[k]=a[j++];
           }
       }
       for(int i=low;i<=high;i++)
       {
           a[i]=b[i];
       }
       for(int k=0;k<n;k++)
       {
         printf("%d ",a[k]);
       }
       printf("\n");
       return;
    }
}
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    f(0,n-1);
}*/

/*struct data{

    char name[100];
    int score[100];
};

void myswap( data& a,const data b){


}

data a,b;
myswap(a,b);


void myswap(int& a, int& b){
    int t = a;
    a = b;
    b = t;
}

int a = 5;
int b = 3;
myswap(a,b);*/
// stl sort
/*#include <cstdio>
#include<algorithm>
using namespace std;
struct student{
    char name[20];
    int score;
    bool operator<(const student &r)const
    {
        return score<r.score;
    }
};
int main()
{
    int n;
    student students[50005];
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%s %d", students[i].name,&students[i].score);
    }
    sort(students+0,students+n);
    for(int i=0;i<n;i++)
    {
        printf("%s %d\n",students[i].name,students[i].score);
    }
    return 0;
}
*/
//

/*class student{
private:
    char name[100];
    int score;

public:
    void writeName(char name1[]){
        strcpy(name,name1);
    }
};

int main(){
    student a;
    a<b;
}*/
//해밀턴 순환 회로
#include<stdio.h>
int n,a[15][15];
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {

        }
    }
}



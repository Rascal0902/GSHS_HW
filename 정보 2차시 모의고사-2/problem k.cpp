/*#include<stdio.h>
#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<map>
using namespace std;
map <string, int> enc;
map <int, string> decode;
int dcnt,k=1;
int num[10005],a[30][50];
int mem[50];
int main()
{
    int n,i,j,t;
    char a[10010];
    scanf("%d",&n);
    scanf("%s",a);
    dcnt=1;
    for(i=0;i<n;i++)
    {
        string s="";
        s+=a[i];
        if(enc.find(s)!=enc.end())
            {continue;}
            t=0;
        for(j=0;j<n;j++)
        {
            if(a[j]==a[i])
            {
                t++;
            }
        }
        num[dcnt]=t;
        enc.insert({s, dcnt});
        decode.insert({dcnt, s});
        dcnt++;
    }
    dcnt--;
    for(i=1;i<=dcnt;i++)
    {
      cout<< i<<" " << decode[i] <<" " << num[i]<<endl;
    }
    int min1=10000,min2=10000,min1x=100000,min2x=100000;
    while(1)
    {
        if(dcnt==1)
        {
            break;
        }
        for(i=1;i<=dcnt;i++)
        {
            if(min2>=num[i])
            {
                if(min1>=num[i])
                {
                    min2=min1;
                    min1=num[i];
                    min2x=min1x
                    min1x=i;
                }
                else
                    {
                        min2=num[i];
                        min2x=i;
                    }

            }
        }

        a[min1x][mem[min1x]]=0;
        a[min2x][mem[min2x]]=1;
        mem[min2x]++;
        mem[min1x]++;





    }
}
*/
#include <stdio.h>
char treealpha[100]={0,};
int treebeta[100]={0,};
int treelink[100]={0,};
long long int treebaejung[100]={0,};
int n,alphalocate=0,locate,min1,min2,min1_gab,min2_gab,cnt;
char c[10005]={0,};
void eejin(long long int a)
{
    long long int b[50]={0,},i=0,d=a;
    if(a==0)
    {
        printf("0\n");
        return;
    }
    while(1)
    {
        if(d==0)
        {
            break;
        }
        b[i]=d%3;
        d/=3;
        i++;
    }
    for(int j=i-1;j>=0;j--)
        printf("%lld",b[j]-1);
    printf("\n");
}
int main()
{

    scanf("%d %s",&n,c);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<alphalocate;j++)
        {
            if(c[i]==treealpha[j])
            {
                treebeta[j]++;
                goto okay;
            }
        }
        treealpha[alphalocate]=c[i];
        treebeta[alphalocate]++;
        treelink[alphalocate]=alphalocate+1;
        alphalocate++;
        okay:
        printf("");
    }
    locate=alphalocate;
    for(int i=1;i<=alphalocate-1;i++)
    {
        min1_gab=10000;
        min2_gab=10000;
        for(int j=0;j<locate;j++)
        {
            if(min1_gab>treebeta[j]&&treelink[j]==j+1)
             {
                  min1=j;
                  min1_gab=treebeta[j];
             }
        }
        treelink[min1]=locate+1;
       for(int j=0;j<locate;j++)
        {
            if(min2_gab>treebeta[j]&&treelink[j]==j+1)
            {
                min2=j;
                min2_gab=treebeta[j];
            }
        }
        treelink[min2]=locate+1;
        treelink[locate]=locate+1;
        treebeta[locate]=treebeta[min1]+treebeta[min2];
        locate++;
    }
    /*for(int i=0;i<locate;i++)
    {
        printf("%d %d %d\n",i,treebeta[i],treelink[i]);
    }
    printf("\n");*/
    treebaejung[2*alphalocate-2]=0;
    for(int i=2*alphalocate-2;i>alphalocate-1;i--)
    {
        cnt=1;
        for(int j=0;j<i;j++)
        {
            if(cnt>2)
                break;
            if(treelink[j]==i+1)
            {
                treebaejung[j]=(long long int)cnt+3*treebaejung[i];
                cnt++;
             //   printf("%d %d %lld %d\n",i,j,treebaejung[j],cnt);

            }
        }
    }
    for(int i=0;i<alphalocate;i++)
    {
        printf("%c ",treealpha[i]);
        eejin(treebaejung[i]);
    }
    return 0;
}

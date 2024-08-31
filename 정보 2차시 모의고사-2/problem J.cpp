#include<stdio.h>
#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<map>
using namespace std;
map <string, int> enc;
map <int, string> decode;
int dcnt,k=1;
int encode[10005];
int main()
{
    int n,i;
    char a[10010];
    scanf("%d",&n);
    scanf("%s",a);
    dcnt=1;
    for(i=0;i<n;i++)
    {
        string s="";
        s+=a[i];
        if(enc.find(s)!=enc.end())
            continue;
        enc.insert({s, dcnt});
        decode.insert({dcnt, s});
        dcnt++;
    }
    string s="";
    i=0;
    while(1)
    {
        if(i>n-1)
            {
                encode[k]=enc[s];
                k++;
                break;
            }
        if(enc.find(s+a[i])!=enc.end())
        {
            s+=a[i];
            i++;
        }
        else
        {
            encode[k]=enc[s];
            k++;
            enc.insert({s+a[i], dcnt});
            decode.insert({dcnt, s+a[i]});
            dcnt++;
            s=a[i];
            i++;
        }
    }
    cout << k-1 << endl;
    for(i=1;i<k;i++)
    {
        cout<<encode[i]<<" ";
    }
    return 0;
}

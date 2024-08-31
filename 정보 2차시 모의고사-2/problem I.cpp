#include<stdio.h>
#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<map>
using namespace std;
map <string, int> enc;
map <int, string> decode;
int dcnt;

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
        if(enc.find(s+a[i])!=enc.end())
        {
            if(i+1>n-1)
            {
                break;
            }
            s+=a[i];
            i++;
        }
        else
        {   enc.insert({s+a[i], dcnt});
            decode.insert({dcnt, s+a[i]});
            dcnt++;
            s=a[i];
            if(i+1>n-1)
            {
                break;
            }
            i++;
        }
    }
    for(i=1;i<dcnt;i++)
    {
        cout<<i<<":"<<decode[i]<<endl;
    }
    return 0;
}

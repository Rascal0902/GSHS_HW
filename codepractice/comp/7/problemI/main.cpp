#include <bits/stdc++.h>
using namespace std;
char mid[60],fir[60];
int siz;
int found(char k,int midlow,int midhigh)
{
    for(int i=midlow;i<=midhigh;i++)
    {
        if(mid[i]==k)
        {
            return i;
        }
    }
    return 1;
}

void tre(int low,int high,int midlow,int midhigh)
{
    if(low>high)
    {
        return;
    }
    if(midlow>midhigh) return;
    int witch;
    char root;
    root=fir[low];
    if(low==high)
    {
        printf("%c",root);
    }
    if(low!=high)
    {
        witch=found(root,midlow,midhigh);
        if(witch==midlow)
        {
            tre(low+1,high,midlow+1,midhigh);
            printf("%c",root);
        }
        else if(witch==midhigh)
        {
            tre(low+1,high,midlow,midhigh-1);
            printf("%c",root);
        }
        else
        {
            tre(low+1,low+witch-midlow,midlow,witch-1);
            tre(low+witch-midlow+1,high,witch+1,midhigh);
            printf("%c",root);
        }

        return;
    }
    return;
}
int main()
{
    scanf("%s%s",mid,fir);
    siz=strlen(mid);
    tre(0,siz-1,0,siz-1);
    return 0;
}
/*
AaEDFCHG
CaADEFGH

AEFDaHGC
*/

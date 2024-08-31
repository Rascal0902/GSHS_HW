#include<stdio.h>
char c[300000];
int check(int a,int b)
{
    int i;
    char k;
    k=c[a];
    for(i=a;i<=b;i++)
    {
        if(k!=c[i])
        {
            return 2;
        }

    }
    return 3;
}
void go(int low,int high)
{
    int mid;
    mid=(low+high)/2;
    if(low==high)
    {
        printf("%c",c[low]);

        return;

    }
    else
    {
        int tr;
        tr=check(low,high);
        if(tr==3)
        {
            printf("%c",c[low]);
            return;
        }
        else
        {
            printf("-");
            go(low,mid);
            go(mid+1,high);
        }
    }
}

int main()
{
    int n,i,t=0;
    scanf("%d\n%s",&n,c);
    go(0,n-1);
    return 0;
}

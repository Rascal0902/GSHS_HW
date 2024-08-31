#include <stdio.h>
#include <queue>
using namespace std;
struct RANGE{
    int s,e;
    RANGE(){s=0;e=0;}
    RANGE(int a, int b){s=a;e=b;}
    int dis(){
        return e-s;
    }
    int center(){
        return (s+e)/2;
    }
};
bool operator<(const RANGE A,const RANGE B){
    int disa=(A.e-A.s);
    int disb=(B.e-B.s);
    if(disa==disb){
        return A.s>B.s;
    }
    return disa<disb;
}
priority_queue<RANGE> Q;
int ans[500005],n,s;
int main()
{
     scanf("%d",&n);
     Q.push(RANGE(0,n-1));
     int k=1;
    while(1)
    {
        int start,endt,mid;
        start=(Q.top()).s;
        endt=(Q.top()).e;
        mid=(start+endt)/2;
        if((k>=n+1)||(endt-start<=0))
        {
            s=k;
            break;
        }
        else
        {

            //printf("%d %d %d\n",start,endt,mid);
            ans[mid]=k;
            /*for(int i=0;i<n;i++)
            {
                printf("%d ",ans[i]);
            }
             printf("\n");*/
            Q.pop();
            Q.push(RANGE(start,mid-1));
            Q.push(RANGE(mid+1,endt));
            k++;
        }
     }
     if(s==n+1)
     {
         for(int i=0;i<n;i++)
        {
            printf("%d ",ans[i]);
        }
        return 0;
     }
     else
     {
         for(int i=0;i<n;i++)
        {
            if(ans[i]!=0)
            {
                printf("%d ",ans[i]);
            }
            else
            {
                ans[i]=s;
                printf("%d ",ans[i]);
                s++;
            }
        }
        return 0;
     }
}

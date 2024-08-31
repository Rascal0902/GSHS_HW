#include<stdio.h>
#include<vector>
using namespace std;
int main()
{
    int n,i,t,sum,tot=0,a[101]={0,};
    vector <int> v;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&t);
        v.push_back(t);

    }
    sum=v[0];
     while(1)
        {
            for(i=0;i<n-2;i++)
            {//printf("%d",a[i]);
                if(a[i]==0)
                {
                    sum+=v[i+1];
                }
                else
                {
                    sum-=v[i+1];
                }
            }
            if(sum==v[n-1])
          {
             tot++;
          }
          sum=0;
         a[0]++;
         for(i=0;i<n-2;i++)
         {
             if(a[i]==2)
             {
                 a[i+1]++;
                 a[i]=0;
             }
         }
         if(a[n-2]==1)
         {
             break;
         }
        }
        printf("%d",tot);
        return 0;
}

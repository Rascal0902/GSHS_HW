
#include<stdio.h>
int n,s=0,w=0;

int find(int a,int b)
{
    if(b==0)
    {
        return 1;
    }
    else if(a==b)
    {
        return 1;
    }
    else
    {
        int s;
        s=find(a-1,b)+find(a-1,b-1);
        return s;
    }
}
int ptm(int t)
{ if(t>=0)
   { printf("%d ",find(w,s));
    s++;
    ptm(t-1);

   }
   else
   {  s=0;
       return 1;
   }
}
int pt(int k)
{   w=k;
    ptm(k);
    if(k==n-1)
    {
        return 0;
    }
    else
    {
        printf("\n");
        pt(k+1);
    }
}
int main()
{
    int i,j;
    scanf("%d",&n);
    pt(0);
    return 0;
}

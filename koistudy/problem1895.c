#include<stdio.h>
int n,s=0,w=0;
int pt1(int t)
{ if(t>=0)
   { printf("%d ",f(w,s));
    s++;
    pt1(t-1);

   }
   else
   {  s=0;
       return 1;
   }
}
int pt(int k)
{   w=k;
    pt1(k);
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
int f(int a,int b)
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
        s=f(a-1,b)+f(a-1,b-1);
        return s;
    }
}
int main()
{
    int i,j,x,y;
    //scanf("%d",&n);
    //pt(0) Ãâ·Â;
    scanf("%d %d",&x,&y);
    printf("%d",f(x-1,y-1));
    return 0;
}

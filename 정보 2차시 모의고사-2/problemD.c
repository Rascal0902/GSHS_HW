/*#include<stdio.h>
char a[10003];
int m,n;
int target(int k)
{
    int i,x=0;
    while(1)
    {
        if((a[k+1]!='O')||(a[k+2]!='I'))
        {
            return 0;
        }
        x++;
        if(x==n)
        {
            return 1;
        }
        else
        {
            k+=2;
        }
    }
}
int main()
{
    int t=0,i;
    scanf("%d\n%d",&n,&m);
    scanf("%s",a);
    for(i=0;i<=m-2*n-1;i++)
    {
        if(a[i]=='I')
        {
            t+=target(i);
        }
    }
    printf("%d",t);
    return 0;
}*/
/*#include<stdio.h>
char a[10003];
int b[10003];
int m,n;
int target(int k)
{
    int i,x=0;
    for(i=k+1;i<k+1+2*n;i++)
    {
        x+=b[i];
        if(x>0)
        {
            return 0;
        }
    }
    return 1;
}
int main()
{
    int t=0,i,k=0;
    scanf("%d\n%d",&n,&m);
    scanf("%s",a);
    for(i=0;i<m;i++)
    {
        if(a[i]=='I')
        {
            b[i]=10;
        }
        if(a[i]=='O')
        {
            if((i+1<m)&&(a[i+1]=='I'))
            {
                b[i]=0;
                b[i+1]=0;
                i++;
            }
            else
            {
                b[i]=10;
            }
        }
    }
    for(i=0;i<=m-2*n-1;i++)
    {
        if(a[i]=='I')
        {
            t+=target(i);
        }
    }
    printf("%d",t);
    return 0;
}*/
#include<stdio.h>
int main()
{
    int m,n,j=0,sum=0,t=0,cnt;
    char a[1000003],i,b[500000];
    scanf("%d\n%d",&n,&m);
    scanf("%s",a);
    for(i=0;i<m;i++)
    {
        if(t==0)
        {
            cnt=0;
        }
        if(a[i]=='I')
        {

          t=1;
          if((a[i+1]=='O')&&(a[i+2]=='I'))
          {
              cnt++;
              i++;
          }
          else
          {
             b[j]=cnt;
             j++;
             t=0;
          }
        }

    }
    for(i=0;i<j;i++)
    {
        if(b[i]>=n)
        {
            sum+=b[i]-n+1;
        }
    }
    printf("%d",sum);
    return 0;
}

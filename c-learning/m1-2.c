#include<stdio.h>
char x=' ';
int a=0,b=0,i,j,n,c,d,arr[100][100],k;
int ne(int a,int b,int c,int d)
{
    for(i=a;i<=c;i++)
    {
        for(j=b;j<=d;j++)
        {
            arr[i][j]=n;
        }
    }
    for(i=a+1;i<=c;i++)
    {
        for(j=b;j<=d-1;j++)
        {
            arr[i][j]='\0';
        }
    }
    k=



    return sw(a+1,b,c,d-1)
}
int sw(int a,int b,int c,int d)
{
    for()
    {
        for()
        {

        }
    }

int main()
{
    scanf("%d",&n);
    c=n-1;
    d=n-1;
    ne(a,b,c,d);
    for(i=0;i<=n-1;i++)
    {
        for(j=0;j<=n-1;j++)
        {
            if(arr[i][j]==0)
            {printf(" ");}
            else
          printf("%d",arr[i][j]);
        }
        printf("\n");
    }
    return 0;
}

/*//problem1427
/*#include<stdio.h>
int main()
{
   int a[10],i,j,k=0,m,t,d;
  scanf("%d",&m);
    do
   {
      if(m==0)
     {
         break;
     }a[k]=m%10;

     m=m/10;
     k++;
     }while(k<=9);
   for(j=0; j<k; j++)
    {
        for(i=0; i<k-1; i++)
        {
            if(a[i+1]>a[i])
            {
                t=a[i+1];
                a[i+1]=a[i];
                a[i]=t;

            }
        }

    }
    for(i=0; i<k; i++)
    {
        printf("%d",a[i]);
    }
    return 0;
}*/
//stack
/*#include<stdio.h>
#include<string.h>
int size=-1,stack[10000];
int pop()
{
    if(size==-1)
    {
        printf("-1\n");
        return 1;
    }
    else
    {
        printf("%d\n",stack[size]);
        stack[size]=0;
        size--;
        return 1;
    }
}
int push(int k)
{
    size++;
    stack[size]=k;
    return 1;
}
int main()
{
    int n,i,b[10000];
    char a[10000][8];
    scanf("%d",&n);
    for(i=0; i<n; i++)
    {
        scanf("%s",a[i]);
        if(strcmp(a[i],"push")==0)
        {
            scanf("%d",&b[i]);
        }
    }
    for(i=0; i<n; i++)
    {
        if(strcmp(a[i],"push")==0)
        {
            push(b[i]);
        }
        else if(strcmp(a[i],"pop")==0)
        {
            pop();
        }
        else if(strcmp(a[i],"empty")==0)
        {
            if(size==-1)
            {
                printf("1\n");
            }
            else
            {
                printf("0\n");
            }
        }
        else if(strcmp(a[i],"top")==0)
        {
            if(size==-1)
            {
                printf("-1\n");
            }
            else
            {
                printf("%d\n",stack[size]);
            }
        }
        else
        {
            printf("%d\n",size+1);
        }

    }
    return 0;
}*/
/*
#include<stdio.h>
#include<string.h>
char stack[50],top=-1;
void cyc()
{
    while(1)
    {
        if(stack[top]==')')
       {
           if(stack[top-1]=='(')
          {
            stack[top]=' ';
            stack[top-1]=' ';
            top-=2;


        }
       }
       if(top==-1)
       {
           break;
       }
       else if(stack[top]=='(')
       {
           break;
       }
       else if((stack[top]==')')&&(stack[top]==')'))
       {
           break;
       }
    }

}
void push(char k)
{
    top++;
    stack[top]=k;
    cyc();
}
int main()
{
    int n,i,j,a;
   char b[50];
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%s",b);
        a=strlen(b);
        for(j=0;j<a;j++)
        {
            push(b[j]);
        }
        if(top==-1)
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
        for(j=0;j<50;j++)
        {
            b[j]=' ';
            stack[j]=' ';
        }
        top=-1;
    }
    return 0;
}*/
//11653 소인수 문해
/*#include<stdio.h>
int main()
{
    int n,i;
    scanf("%d",&n);
    while(1)
    {
        if(n==1)
        {
            break;
        }
        for(i=2;i<n;i++)
        {
            if(n%i==0)
            {
                break;
            }
        }
        printf("%d\n",i);
        n=n/i;
    }
    return 0;
}
*/

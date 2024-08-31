/*#include<stdio.h>
int N,K,t=1,i,j,k,s[10000000],u[10000000];
int main()
{
    scanf("%d %d",&N,&K);
    s[1]=N;
    for(i=1;;i++)
    {
        for(j=1;j<=t;j++)
        {
            if(i%2==1)
            {
                u[3*j-2]=s[j]+1;
                u[3*j-1]=s[j]-1;
                u[3*j]=2*s[j];
            }
             if(i%2==0)
            {
                s[3*j-2]=u[j]+1;
                s[3*j-1]=u[j]-1;
                s[3*j]=2*u[j];
            }
        }
        t*=3;
        for(j=1;j<=t;j++)
        {
            if(i%2==1)
            {
                if(u[j]==K)
                {
                    printf("%d",i);
                    return 0;
                }
            }
             if(i%2==0)
            {
                if(s[j]==K)
                {
                    printf("%d",i);
                    return 0;
                }
            }
        }
    }

    return 0;
}
  /*for(k=1; k<=t; k++)
    {
        printf("%d\n",u[k]);
    }*/
     /*   for(k=1; k<=t; k++)
    {
        printf("%d\n",s[k]);
    }*/
#include<stdio.h>
int a[1000000], len[1000000],s=0,e=0,N,K,t,v[1000000],b=0,ch;
void push(int k)
{
    a[e]=k;
    v[k]=1;
    e++;
}
void pop()
{
    a[s]=0;
    s++;
}
int main()
{
     scanf("%d %d",&N,&K);
         push(N);
         len[s]=0;

    while(1)
    {

        t=a[s];
        if(t==K)
        {
            printf("%d",len[s]);
            return 0;
        }
        if(t<=99999)
        {

            if(v[t+1]==0)
            {push(t+1);

            len[e-1]=len[s]+1;}
        }
        if(t>=1)
        {

           if(v[t-1]==0)
            {
                push(t-1);
             len[e-1]=len[s]+1;}
        }
        if(t<=50000)
        {

           if(v[t*2]==0)
            {push(t*2);
             len[e-1]=len[s]+1;}
        }

        pop();

    }
}

























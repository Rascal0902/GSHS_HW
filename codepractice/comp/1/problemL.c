#include<stdio.h>
int a[15],b[15],c[15],end1=0,end2=0,end3=0,i;
int push1(int k)
{
    a[end1]=k;
    end1++;
    return 1;
}
int push2(int k)
{
    b[end2]=k;
    end2++;
    return 1;
}
int push3(int k)
{
    c[end3]=k;
    end3++;
    return 1;
}
int pop1()
{
    a[end1-1]=0;
    end1--;
}
int pop2()
{
    b[end2-1]=0;
    end2--;
}
int pop3()
{
    c[end3-1]=0;
    end3--;
}
void Hanoi(int n, char A, char B, char C)
{
    int k=0;
    if(n == 1)
    {
        if(A=='A')
        {
            k=a[end1-1];
            pop1();
            if(C=='B')
            {
                push2(k);
            }
            else
            {
                push3(k);
            }

        }
        else if(A=='B')
        {
            k=b[end2-1];
            pop2();
             if(C=='A')
            {
                push1(k);
            }
            else
            {
                push3(k);
            }
        }
        else
        {
            k=c[end3-1];
            pop3();
             if(C=='A')
            {
                push1(k);
            }
            else
            {
                push2(k);
            }
        }
        printf("move disk %d %c->%c\n",k,A,C);

    }
    else
    {
        Hanoi(n-1, A, C, B);
        if(A=='A')
        {
            k=a[end1-1];
            pop1();
            if(C=='B')
            {
                push2(k);
            }
            else
            {
                push3(k);
            }

        }
        else if(A=='B')
        {
            k=b[end2-1];
            pop2();
             if(C=='A')
            {
                push1(k);
            }
            else
            {
                push3(k);
            }
        }
        else
        {
            k=c[end3-1];
            pop3();
             if(C=='A')
            {
                push1(k);
            }
            else
            {
                push2(k);
            }
        }
        printf("move disk %d %c->%c\n",k,A,C);
        Hanoi(n-1, B, A, C);

    }

}
int main()
{
    int n;
    scanf("%d", &n);
    printf("%d\n",(2<<(n-1))-1);
    for(i=n;i>=1;i--)
    {
        push1(i);
    }
    Hanoi(n,'A','B','C');
    return 0;
}

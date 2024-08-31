#include <stdio.h>
#include <stdbool.h>
int f(int k);
bool is_Pal(int k);
int main()
{

    int n, cnt = 0;

    scanf("%d", &n);

    for( cnt = 0 ; !is_Pal(n) ; cnt++ )

    {

        n = n + f(n);


    }

    printf("%d %d", cnt, n);

    return 0;

}
int a[100];
int f(int k)
{

    int i,t=0;
    int s=0;
    for(i=0;i<100;i++)
    {
        if(k<10)
        {
            a[t]=k;
            break;
        }
        else
        {
            a[t]=k%10;
            t++;
            k=k/10;
        }
    }

    for(i=0;i<=t;i++)
    {
        s=s*10;
        s+=a[i];
    }

    return s;

}
bool is_Pal(int k)
{

    int i,j,t=0;
    for(i=0;i<100;i++)
    {
        if(k<10)
        {
            a[t]=k;
            break;
        }
        else
        {
            a[t]=k%10;
            t++;
            k=k/10;
        }
    }
    i=0;
    j=t;
    while(1)
    {

        if(i>=j)
        {
            break;
        }
        else
        {
            if(a[i]!=a[j])
            {
                return false;
            }
            i++;
            j--;
        }
    }

     return true;
}

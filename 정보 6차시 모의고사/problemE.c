#include <stdio.h>



int f(int k);



void g(int a , int b)  // reference를 이용한 전달

{

    int t;

    t = a;

    a = b;

    b = t;

}



int get_max(int a, int b)

{

    return a > b ? a : b;

}



int main()

{

    int a, b, ans = 0;

    scanf("%d%d", &a, &b);

    if( a > b )

        g(a, b);

    for(int i = a ; i <= b ; i++ )

        ans = get_max( ans, f(i) );

    printf("%d", ans);

    return 0;

}
int x=0;
int f(int k)
{
    if(k==1)
    {
        x++;
        int y;
        y=x;
        x=0;
        return y;
    }
    else
    {
        if(k%2==1)
        {
            int s;
            s=3*k+1;
            x++;
            f(s);
        }
        else
        {
            int z;
            z=k/2;
            x++;
            f(z);
        }
    }
}

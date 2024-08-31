#include<stdio.h>
int main()
{
    int n,k;
    scanf("%d",&n);
    lable:
        scanf("%d",&k);
        printf("%d\n",k);
        n--;
        if(n!=0)
        {
            goto lable;
        }
        else
        {
            return 0;
        }
}

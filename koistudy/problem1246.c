#include<stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    if(n%10!=0)
    {
        printf("-1");
        return 0;
    }
    else
    {
        printf("%d %d %d",(int)n/300,(int)(n-((int)n/300)*300)/60,(n-((int)n/300)*300-(int)((n-((int)n/300)*300)/60)*60)/10);
    }
    return 0;
}

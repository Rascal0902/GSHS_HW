#include<stdio.h>
#include<string.h>
int main()
{
   int i,ans,sum;
   char exp[1000000],a='-',b='+',c;
   scanf("%s",exp);
    for(i=0;i<strlen(exp);i++){
        if((exp[i]>=0)&&(exp[i]<10)){
            sum*=10;
            sum+=exp[i];

        }
        else{
                if(exp[i]==a)
                {
                    if(c==a)
                    {
                        c=b;
                    }
                    else{
                        c=a;
                    }
                }


                if(exp[i]==c)
                {
                    ans-=exp[i];
                }
                else{
                    ans+=exp[i];
                }

        }
    }
    printf("%d",ans);
    return 0;
}


#include<stdio.h>
struct fine
{
    int a,b,c;
    fine operator-(fine x)
    {
        int q,w,e;
        q=a-x.a;
        w=b-x.b;
        e=c-x.c;
        if(e<0)
        {
            w-=1;
            e+=60;
        }
        if(w<0)
        {
            q-=1;
            w+=60;
        }
        return (fine){q,w,e};
    }
};
int main()
{
    int i;
    fine s1[2],sk[2],sm[2],time[3];
    scanf("%d %d %d %d %d %d",&s1[0].a,&s1[0].b,&s1[0].c,&s1[1].a,&s1[1].b,&s1[1].c);
    scanf("%d %d %d %d %d %d",&sk[0].a,&sk[0].b,&sk[0].c,&sk[1].a,&sk[1].b,&sk[1].c);
    scanf("%d %d %d %d %d %d",&sm[0].a,&sm[0].b,&sm[0].c,&sm[1].a,&sm[1].b,&sm[1].c);
    time[0]=s1[1]-s1[0];
    time[1]=sk[1]-sk[0];
    time[2]=sm[1]-sm[0];
    for(i=0;i<=2;i++)
    {
        printf("%d %d %d\n",time[i].a,time[i].b,time[i].c);
    }
    return 0;
}

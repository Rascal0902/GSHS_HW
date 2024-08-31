#include<stdio.h>
struct boonso
{
    int boonja;
    int boonmo;
};
int main()
{
    struct boonso a={100,200};
    struct boonso b[3]={20,30,40,50,60,70};
    printf(" %d/ %d\n", a.boonja, a.boonmo);
     for (int i=0;i<3;i++)
     {
         printf(" %d/ %d\n", b[i].boonja, b[i].boonmo);
     }
     return 0;
}

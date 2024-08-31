#include<stdio.h>

int main()
{
    int n,i;
    char english[5][10]={"book",
                         "computer",
                         "program" ,
                         "keyboard",
                         "mouse"    };
   char korean[5][10]={"책",
                       "컴퓨터",
                       "프로그램",
                       "키보드",
                       "마우스"};
  char input[20],output[20];
   scanf("%d",&n);
   if(n==1)
   {scanf(" %s",&input);

   for(i=0;i<5;i++)
   {
       if(strcmp(english[i],input)==0)
       {
           printf(" %s",korean[i]);
       }
   }
   }
    if(n==2)
   {scanf(" %s",&output);

   for(i=0;i<5;i++)
   {
       if(strcmp(korean[i],input)==0)
       {
           printf(" %s",english[i]);
       }
   }
   }
}





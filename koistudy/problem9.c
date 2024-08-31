#include<stdio.h>
int main()
{int i;
char a[5][40]={"\#include\<stdio\.h\>",
                "main\(\)",
                "\{",
                " printf\(\"Hello World\\n\"\)\;",
                "\}"};
 for(i=0;i<5;i++)
 {
      printf(" %s",a[i]);
      printf("\n");

 }
}



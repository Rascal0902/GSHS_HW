#include<stdio.h>
int main()
{
  char arr[ ]={'c','o','m','p','u','t','e','r'};
  int i,size;
  size=strlen(arr);
  for(i=0; i<size; i++)
  {
      printf("%c",arr[i]);
  }
}

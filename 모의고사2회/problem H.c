#include<stdio.h>
#include<string.h>
int main()
{
    int a=0,b=0,d=0,i,c[20]={0,};
    char arr[50],brr[50];
    scanf("%s",arr);
    scanf("%s",brr);
    for(i=0;i<strlen(arr);i++)
    {
         if(arr[i]=='M')
        {
           if(i>=1)
            {
                if(arr[i-1]=='C')
                {
                    a+=800;
                }
                else a+=1000;
            }
            else a+=1000;
        }
        else if(arr[i]=='D')
        {
          if(i>=1)
            {
                if(arr[i-1]=='C')
                {
                    a+=300;
                }
                else a+=500;
            }
            else a+=500;
        }
        else if(arr[i]=='C')
        {
          if(i>=1)
            {
                if(arr[i-1]=='X')
                {
                    a+=80;
                }
                else a+=100;
            }
            else a+=100;
        }
         else if(arr[i]=='L')
        {
        if(i>=1)
            {
                if(arr[i-1]=='X')
                {
                    a+=30;
                }
                else a+=50;
            }
            else a+=50;
        }
         else if(arr[i]=='X')
        {
           if(i>=1)
            {
                if(arr[i-1]=='I')
                {
                    a+=8;
                }
                else a+=10;
            }
            else a+=10;
        }
         else if(arr[i]=='V')
        {
           if(i>=1)
            {
                if(arr[i-1]=='I')
                {
                    a+=3;
                }
                else a+=5;
            }
            else a+=5;
        }
         else
        {
          a+=1;
        }
    }
    for(i=0;i<strlen(brr);i++)
    {
      if(brr[i]=='M')
        {
           if(i>=1)
            {
                if(brr[i-1]=='C')
                {
                    b+=800;
                }
                else b+=1000;
            }
            else b+=1000;
        }
        else if(brr[i]=='D')
        {
          if(i>=1)
            {
                if(brr[i-1]=='C')
                {
                    b+=300;
                }
                else b+=500;
            }
            else b+=500;
        }
        else if(brr[i]=='C')
        {
          if(i>=1)
            {
                if(brr[i-1]=='X')
                {
                    b+=80;
                }
                else b+=100;
            }
            else b+=100;
        }
         else if(brr[i]=='L')
        {
        if(i>=1)
            {
                if(brr[i-1]=='X')
                {
                    b+=30;
                }
                else b+=50;
            }
            else b+=50;
        }
         else if(brr[i]=='X')
        {
           if(i>=1)
            {
                if(brr[i-1]=='I')
                {
                    b+=8;
                }
                else b+=10;
            }
            else b+=10;
        }
         else if(brr[i]=='V')
        {
           if(i>=1)
            {
                if(brr[i-1]=='I')
                {
                    b+=3;
                }
                else b+=5;
            }
            else b+=5;
        }
         else
        {
          b+=1;
        }
    }
   printf("%d",a+b);
   d=a+b;
   c[0]=d/1000;
   c[1]=(d%1000)/900;
   c[2]=(d%1000-c[1]*900)/500;
   c[3]=(d%1000-c[1]*900-c[2]*500)/400;
   c[4]=(d%1000-c[1]*900-c[2]*500-c[3]*400)/100;
   c[5]=(d%1000-c[1]*900-c[2]*500-c[3]*400-c[4]*100)/90;
   c[6]=(d%1000-c[1]*900-c[2]*500-c[3]*400-c[4]*100-c[5]*90)/50;
   c[7]=(d%1000-c[1]*900-c[2]*500-c[3]*400-c[4]*100-c[5]*90-c[6]*50)/40;
   c[8]=(d%1000-c[1]*900-c[2]*500-c[3]*400-c[4]*100-c[5]*90-c[6]*50-c[7]*40)/10;
   c[9]=(d%1000-c[1]*900-c[2]*500-c[3]*400-c[4]*100-c[5]*90-c[6]*50-c[7]*40-c[8]*10)/9;
   c[10]=(d%1000-c[1]*900-c[2]*500-c[3]*400-c[4]*100-c[5]*90-c[6]*50-c[7]*40-c[8]*10-c[9]*9)/5;
   c[11]=(d%1000-c[1]*900-c[2]*500-c[3]*400-c[4]*100-c[5]*90-c[6]*50-c[7]*40-c[8]*10-c[9]*9-c[10]*5)/4;
   c[12]=(d%1000-c[1]*900-c[2]*500-c[3]*400-c[4]*100-c[5]*90-c[6]*50-c[7]*40-c[8]*10-c[9]*9-c[10]*5-c[11]*4)/1;
   printf("\n");
   for(i=0;i<c[0];i++)
   {
       printf("M");
   }
   for(i=0;i<c[1];i++)
   {
       printf("CM");
   }
   for(i=0;i<c[2];i++)
   {
       printf("D");
   }
   for(i=0;i<c[3];i++)
   {
       printf("CD");
   }
   for(i=0;i<c[4];i++)
   {
       printf("C");
   }
   for(i=0;i<c[5];i++)
   {
       printf("XC");
   }
   for(i=0;i<c[6];i++)
   {
       printf("L");
   }
   for(i=0;i<c[7];i++)
   {
       printf("XL");
   }
   for(i=0;i<c[8];i++)
   {
       printf("X");
   }
   for(i=0;i<c[9];i++)
   {
       printf("IX");
   }
   for(i=0;i<c[10];i++)
   {
       printf("V");
   }
   for(i=0;i<c[11];i++)
   {
       printf("IV");
   }
   for(i=0;i<c[12];i++)
   {
       printf("I");
   }
return 0;
}

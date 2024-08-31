/*#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
    int arr[10]={'A','B','C','D','E','a','b','c','d','e'},brr[10],i,j;
    long long int sum=0;
    char crr[13];
    scanf("%s",crr);
    for(i=0;i<strlen(crr);i++)
    {
        for(j=0;j<10;j++)
        {
            if(crr[i]==arr[j])
            {
                brr[i]=j;
                break;
            }
        }
    }
    for(i=0;i<strlen(crr);i++)
    {
       sum*=(long long int)10;
       sum+=(long long int)brr[i];
    }
    printf("%lld",sum);
    return 0;

}*/
#include <stdio.h>
#include <string.h>
char A[11];
int ans(char k){
    if(k=='A') return 0;
    if(k=='B') return 1;
    if(k=='C') return 2;
    if(k=='D') return 3;
    if(k=='E') return 4;
    if(k=='a') return 5;
    if(k=='b') return 6;
    if(k=='c') return 7;
    if(k=='d') return 8;
    if(k=='e') return 9;
}
int main()
{
    long long int sum=0;
    scanf("%s",A);
    for(int i=0;i<strlen(A);i++){
        sum*=10;
        sum+=ans(A[i]);
    }
    printf("%d",sum);
    return 0;
}

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
    for(int i=strlen(A)-1;i>=0;i--){
        sum*=10;
        sum+=ans(A[i]);
    }
    printf("%d",sum);
    return 0;
}


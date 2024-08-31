/*#include<stdio.h>
#include<stdio.h>
int main()
{
    char a[20],b,c[6]={'a','p','p','l','e'},f[6],i;
    FILE *fp ,*fp2, *fp3,*fp4,*fp5;
    fp=fopen("text.txt","r");
    fscanf(fp,"%s",a);
    printf("%s\n",a);
    fclose(fp);
    fp2=fopen("text.txt","w");
    fputc('s',fp2);
    /*fp3=fopen("text.txt","r");
    b=fgetc(fp3);
    printf("%c",b);*/
    /*fp4=fopen("text.txt","a");
    fputs(c,fp4);*/
    /*fp5=fopen("text.txt","r");
    fgets(f,sizeof(f),fp5);
    for(i=0;i<strlen(f);i++)
    {
         printf("%c",f[i]);
    }*/
/*
    return 0;
}*/
#include<stdio.h>
int main()
{
    freopen("text.txt","w",stdout);
    printf("123456765321\n");
    return 0;
}

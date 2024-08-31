/*#include<stdio.h>
#include<string.h>
char stack1[1000],end1=0,stack2[1000],end2=0,a[1000],size=0;
int push1(char k)
{
    stack1[end1]=k;
    end1++;
    return 1;
}
int pop1()
{
    printf("%c",stack1[end1-1]);
    stack1[end1-1]='0';
    end1--;
}
int push2(char k)
{
    stack2[end2]=k;
    end2++;
    return 1;
}
int pop2()
{
    printf("%c",stack2[end2-1]);
    stack2[end2-1]='0';
    end2--;
}
int main()
{
    scanf("%s",a);
    size=strlen(a);
    for(int i=0;i<size;i++)
    {
        if(i%2==0)
        {
            printf("%c",a[i]);
        }
    }
    for(int i=0;i<size;i++)
    {
        if(i%2==1)
        {
            if((a[i]=='*')||(a[i]=='/'))
            {
                push1(a[i]);
            }
            else
            {
                push2(a[i]);
            }
        }
    }
    for(int i=end1-1;i>=0;i--)
    {
        pop1();
    }
    for(int i=end2-1;i>=0;i--)
    {
        pop2();
    }
    return 0;
}
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stack>
#include <stdio.h>
#include <ctype.h>
#define EXPMAX 256
int getPriorty(char op) {
	switch (op) {
	default: // (, ), ...
		return 0;
	case '+':
	case '-':
		return 1;
	case '*':
	case '/':
		return 2;
	}
}

int main()
{
	int pos = 0;
	char postExp[EXPMAX];

	char preExp[EXPMAX] = { 0, };
	printf("중위 표기식: ");
	scanf("%s", preExp);

	ArrayStack* opStack = NULL;
	AS_CreateStack(&opStack, EXPMAX);

	for (int i = 0; i < EXPMAX; i++) {
		if (isdigit(preExp[i])) {
			postExp[pos++] = preExp[i];
		}
		else {
			char op = preExp[i];
			if (op == '(') {
				AS_Push(opStack, op);
				continue;
			}
			else if (op == ')') {
				while (!AS_IsEmpty(opStack) && AS_Top(opStack) != '(') {
					postExp[pos++] = AS_Pop(opStack);
				}
				AS_Pop(opStack);
				continue;
			}
			else if (!AS_IsEmpty(opStack)) {
				while (!AS_IsEmpty(opStack) && getPriorty(AS_Top(opStack)) >= getPriorty(op)) {
					postExp[pos++] = AS_Pop(opStack);
				}
			}
			AS_Push(opStack, op);
		}
	}
	while (!AS_IsEmpty(opStack)) {
		postExp[pos++] = AS_Pop(opStack);
	}
	AS_DestroyStack(opStack);
	printf("후위 표기식: %s\n", postExp);

	system("pause");
	return 0;
}

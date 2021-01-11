#include<stdio.h>
#include<ctype.h>
#include<string.h>
char stack[20];
int top = -1;

void push(char c )
{
	top = top + 1;
	stack[top] =  c;
}

void pop()
{
	stack[top] = ' ';
	top = top -1;

}




void main()
{
	char inputBuffer[10],grammar[10][10];
	printf("Enter input string");
	scanf("%s",inputBuffer);
	printf("Enter grammar\n");
	scanf("%s",grammar);
	for(int i = 0;i<3;i++)
	{
		scanf("%s",grammar[i]);
	}
	
	for(int i = 0 ; i<3; i ++)
	{
		printf("%s",grammar[i]);
	}

}

#include<stdio.h>
#include<ctype.h>
#include<string.h>
void E();
void Edash();
void T();
void Tdash();
void F();
int  i = 0;
char input[20];
void main()
{

	printf("Enter expression\n");
	scanf("%s",input);
	E();
	if (i == strlen(input))
	{

		printf("Accepted\n");
		
	}
	else
	{

		printf("Rejected\n");
	} 
   
}

void E()
{
		
		T();
		Edash();

}
void Edash()
{

	if(input[i] == '+')
	{
		++i;
		T();
		Edash();
	}

}

void T()
{

 	 F();
	 Tdash();

}

void Tdash()
{
	if (input[i] == '*')
	{
		++i;
		F();
		Tdash();
	}

}

void F(){
	if (input[i] == '(')
	{
		++i;
		E();
	}
	if (input[i] == ')'){
		++i;
	}
	if (isdigit(input[i]) || isalpha(input[i])){
		++i;
	
	}

}

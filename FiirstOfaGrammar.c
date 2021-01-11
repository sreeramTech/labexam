#include<stdio.h>
#include<string.h>
#include<ctype.h>

int k = -1,i = 0,n;
char search[5] = {'#','#','#','#'};
char first[10][10];
char input[10][10];
void firstOf(char c){
int j;

if (!(isupper(c)))first[i][++k] = c;
for (j = 0 ; j<n ;j++)
{
  if(input[j][0] == c)
  {
    if(input[j][2] == '@')first[i][++k] = '@';
    else if(islower(input[j][2]))first[i][++k] = input[j][2];
    else firstOf(input[j][2]);
 

}

}
}

void main()
{

	n = 8;
	int flag =0,d=-1,g=0;
	for (i = 0;i<n;i++)
		scanf("%s",input[i]);



	for(i = 0;i<n;i++)
	{
		
		flag=0;
		for (int m = 0 ; m < 5 ; m ++)
		{
                  if(search[m] == input[i][0]){ flag =  1; break; }

		}
		if(flag == 0 )
		{
		search[++d] = input[i][0];
                firstOf(input[i][0]);
		k = -1;
		}
	}


        for(i=0;i<n;i++)
	{
		if (strcmp(first[i], "") == 0)continue;
		else {printf("First(%c){%s}\n",search[g],first[i]);++g;}		
	}
}


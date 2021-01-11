#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main()
{
    char str[]="a+b=c";
    char sym[10];
    char *addr[10],*t,a;
    int x=0,f=0;

    for(int i=0;i<strlen(str);i++){
        if(isalpha(str[i])){
            t=malloc(str[i]);
            addr[x]=t;
            sym[x]=str[i];
            printf("%c \t %d \t identifer\n",sym[i],t);
            x++;
        }else if(str[i]=='+' || str[i]=='*' || str[i]=='='){
            t=malloc(str[i]);
            addr[x]=t;
            sym[x]=str[i];
            //printf("%c \t %d \t operator\n",sym[i],t);
            x++;
        }
    }
  
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char grammer[3][5]={
    "S=S+S",
    "S=S*S",
    "S=a"
};

char inp[]="a+a+a$";
int p=0;
char stac[10];
int q=0;

void s_r(){
    if(stac[q-1]=='a'){
        stac[q-1]='S';
    }
    if(stac[q-1]=='S' && (stac[q-2]=='+' || stac[q-2]=='*') && stac[q-3]=='S'){
        stac[q-3]=='\0';
        stac[q-2]=='\0';
        q=q-2;
    }
}

void main(){

    char temp[10];
    int t=0,f=0;
    stac[q++]='$';
    for(int i=0;i<6;i++){
        if(inp[i]=='a' || inp[i]=='+' || inp[i]=='*'){
            stac[q++]=inp[p++];
            inp[p-1]=' ';
            s_r();
        }
    }
    printf("%s\n%s",stac,inp);
}

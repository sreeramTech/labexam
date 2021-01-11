#include<stdio.h>
#include<string.h>

int M=8,N=5;
char str[8][7]={
    "E=TA;",
    "A=+TA;",
    "A=@;",
    "T=FB;",
    "B=*FB;",
    "B=@;",
    "F=a;",
    "F=(E);"
};
int size[8]={4,5,3,4,5,3,3,5};

char non_ternimal[]={"EATBF"};
int non_ternimal_count=5;

char ternimal[]={"+*@()a"};
int ternimal_count=6;

char first[10],follow[10];
int p=0,q=0;

int isTernimal(char a);
void find_first(char a);
void find_follow(char a);
void insert(char a);

void main(){
    for(int i=0;i<non_ternimal_count;i++){
        find_follow(non_ternimal[i]);
        printf("%c:%s\n",non_ternimal[i],follow);
        q=0;
    }
}

void find_follow(char a){
    int f=0;
    if(a==str[0][0]){
        insert('$');
    }
        for(int i=0;i<M;i++){
            for(int j=0;j<size[i];j++){
                if(a==str[i][j]){
                    if(str[i][j+1]==';' && str[i][0]!=a){
                        find_follow(str[i][0]);
                    }else{
                        find_first(str[i][j+1]);
                        f=0;
                        for(int k=0;k<p;k++){
                            if(first[k]=='@'){
                                f=1;
                            }else{
                                insert(first[k]);
                            }
                        }
                        p=0;
                        if(f==1 && str[i][0]!=a){
                            find_follow(str[i][0]);
                        }
                    }
                }
            }
        }
}

void insert(char a){
    int k=0;
    for(int i=0;i<q;i++){
        if(a==follow[i]){
            k=1;
        }
    }
    if(k==0){
        follow[q++]=a;
    }
}

void find_first(char a){
    if(isTernimal(a)==1){
        for(int j=0;j<M;j++){
            if(a==str[j][0]){
                find_first(str[j][2]);
            }
        }
    }else{
        first[p++]=a;
    }
}

int isTernimal(char a){
    for(int i=0;i<ternimal_count;i++){
        if(a==ternimal[i]){
            return 0;
        }
    }
    return 1;
}

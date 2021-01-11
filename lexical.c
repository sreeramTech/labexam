#include<stdio.h>
#include<ctype.h>
#include<string.h>
char key[34][20]={"auto","break","case","char","const","continue","default",
"do","double","else","enum","extern","float","for","goto",
"if","int","long","register","return","short","signed",
"sizeof","static","struct","switch","typedef","union",
"unsigned","void","volatile","while","printf","scanf"};
void main()
{

    FILE *fp;
    char c, word[20],dig[10];
    int i=0,j,k,flag=0,d=0,sum=0,id=0,kw=0,num=0,op=0,pu=0;
    char fname[50];
    printf("enter file name \n");
    scanf("%s",fname);
    fp= fopen(fname,"r");

     if(fp==NULL)


         {
          printf("file not found\n");
         }
     else{
        printf("file found\n\n");
     }

    while((c=getc(fp))!=EOF)
    {
        if(isalpha(c)||(c=='_'))
        {
            flag=0;

            while(isalpha(c)||(c=='_')||isdigit(c))
            {
                word[i++]=c;
                c=getc(fp);
            }
            word[i++]='\0';
            i=0;
            for(j=0;j<34;j++)
            {
                if(strcmp(word,key[j])==0)
                {
                    flag=1;
                    break;
                }
            }
            if (flag==1)
                printf("keyword :%s\n",word);
                kw++;
            if (flag==0)
                printf("identifier :%s\n",word);
                id++;
        }
        if (isdigit(c))
        {
            while(isdigit(c))
            {
                dig[d++]=c;
                c=getc(fp);
            }
            dig[d]='\0';
            d=0;
            printf("Constant :%s\n",dig);
            num++;
        }
        if(c=='+'||c=='-'||c=='*'||c=='/'||c=='<'||c=='>'||c=='%'||c=='&'||c=='?'||c=='='||c=='^')
        {
            printf("operator :%c\n",c);
            op++;
        }
        if(c=='('||c=='{'||c=='}'||c==';'||c==','||c==')')
            {
                printf("Punctuations :%c\n",c);
                pu++;
            }
    }
    fclose(fp);
   // getch();
}

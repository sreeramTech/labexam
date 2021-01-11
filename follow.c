#include<stdio.h>
#include<string.h>
#include<ctype.h>
int n=8,m=0,p,i=0,j=0;
char a[10][10],f[10];
void follow(char c);
void first(char c);
int main()
{
 int i,z,k=-1,flag=0,s;
 char c,ch;
 char buf[5];
 printf("Enter the productions:\n");
 for(i=0;i<n;i++)
  scanf("%s%c",a[i],&ch);

   m=0;
 
  for (i = 0; i<8;i++)
   
  {
    
    c = a[i][0];

  follow(c);
  printf("FOLLOW(%c) = { ",c);
  for(i=0;i<m;i++)
   printf("%c ",f[i]);
  printf(" }\n");
  
 }

}
void follow(char c)
{

 if(a[0][0]==c)f[m++]='$';
 for(i=0;i<n;i++)
 {
  for(j=2;j<strlen(a[i]);j++)
  {
   if(a[i][j]==c)
   {
    if(a[i][j+1]!='\0')first(a[i][j+1]);

    if(a[i][j+1]=='\0'&&c!=a[i][0])
     follow(a[i][0]);

   }
  }
 }
}
void first(char c)
{
      int k;
                 if(!(isupper(c)))f[m++]=c;
                 for(k=0;k<n;k++)
                 {
                 if(a[k][0]==c)
                 {
                 if(a[k][2]=='@') follow(a[i][0]);
                 else if(islower(a[k][2]))f[m++]=a[k][2];
                 else first(a[k][2]);
                 }
                 }

}


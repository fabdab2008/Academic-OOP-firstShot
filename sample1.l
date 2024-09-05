%option noyywrap  

%{
#include<stdio.h>
int id_count=0;
int len_count=0;
%}

start[_A-Za-z]
id {start}[A-Za-z0-9]+


%%
while {fprintf(yyout,"WHILE");id_count++;len_count++;}
id	{fprintf(yyout,"id");id_count++;len_count++;}
{id}	 {fprintf(yyout,"<ID, Lexeme=%s,Length=%d>",yytext,yyleng); id_count++;len_count++;}
[0-9]+	 {fprintf(yyout,"<NUM,Lexeme=%s,Length=%d>",yytext,yyleng);id_count++;len_count++;}
.* 	{fprintf(yyout,"Other pattern,Lexeme=%s,Length=%d",yytext,yyleng);id_count++;len_count++;}


%%


int main()
{
yyin= fopen("in.txt","r");
yyout=fopen("out.txt","w");
yylex();
printf(" Total  = %d ", id_count );
printf(" Number of lines= %d ", len_count );
return 0;
}
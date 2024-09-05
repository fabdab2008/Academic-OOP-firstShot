%option noyywrap

%{
#include<stdio.h>
#include "symboltable.h"
symboltable table;
FILE* log_file;
%}




%%
int      		 {fprintf("<INT>");}
[a-zA-Z]		{fprintf("<id,%s>",yytext);
                table.insert("ID",yytext);
                fprintf(log_file,"Line x: token <id> lexeme %s",yytext);
                }
[0-9]+	 	{fprintf("<const_int,%s>",yytext);}
=			{fprintf("<assign_op,%s>",yytext);}
";"			{fprintf("<semicolon,%s>",yytext);}


%%


int main()
{
yyin=fopen("in.txt","r");
yyin=fopen("token.txt","w");
log_file=fopen("token.txt","w");
yylex();
return 0;
}

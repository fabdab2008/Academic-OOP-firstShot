%option noyywrap
%{
#include <bits/stdc++.h>
using namespace std;
#include "symboltable.h"

symboltable s;
int line_no = 1;
int error_count = 0;

ofstream output("202214302_token.txt");
ofstream logg("log.txt");
ofstream errorLog("log_error.txt");

void insert_symbol(const string &type, const string &symbol){
    symbolinfo entry(symbol, type);
    if (!s.lookup(symbol)) {
        s.insert_(entry);
        s.print(logg);
    } else {
        errorLog << "Line no: " << line_no << " Error: Variable '" << symbol << "' already exists in the symbol table." << endl;
    }
}
%}

%%

\t  {} // Tab characters - ignored
[ ]+ {} // Spaces - ignored

if  {output << "<IF>"; logg << "Line no: " << line_no << " Token <IF> Lexeme '" << yytext << "' found." << endl;}
else {output << "<ELSE>"; logg << "Line no: " << line_no << " Token <ELSE> Lexeme '" << yytext << "' found." << endl;}
for {output << "<FOR>"; logg << "Line no: " << line_no << " Token <FOR> Lexeme '" << yytext << "' found." << endl;}
while {output << "<WHILE>"; logg << "Line no: " << line_no << " Token <WHILE> Lexeme '" << yytext << "' found." << endl;}
do {output << "<DO>"; logg << "Line no: " << line_no << " Token <DO> Lexeme '" << yytext << "' found." << endl;}
break {output << "<BREAK>"; logg << "Line no: " << line_no << " Token <BREAK> Lexeme '" << yytext << "' found." << endl;}
int {output << "<INT>"; logg << "Line no: " << line_no << " Token <INT> Lexeme '" << yytext << "' found." << endl;}
char {output << "<CHAR>"; logg << "Line no: " << line_no << " Token <CHAR> Lexeme '" << yytext << "' found." << endl;}
float {output << "<FLOAT>"; logg << "Line no: " << line_no << " Token <FLOAT> Lexeme '" << yytext << "' found." << endl;}
double {output << "<DOUBLE>"; logg << "Line no: " << line_no << " Token <DOUBLE> Lexeme '" << yytext << "' found." << endl;}
void {output << "<VOID>"; logg << "Line no: " << line_no << " Token <VOID> Lexeme '" << yytext << "' found." << endl;}
return {output << "<RETURN>"; logg << "Line no: " << line_no << " Token <RETURN> Lexeme '" << yytext << "' found." << endl;}
switch {output << "<SWITCH>"; logg << "Line no: " << line_no << " Token <SWITCH> Lexeme '" << yytext << "' found." << endl;}
case {output << "<CASE>"; logg << "Line no: " << line_no << " Token <CASE> Lexeme '" << yytext << "' found." << endl;}
default {output << "<DEFAULT>"; logg << "Line no: " << line_no << " Token <DEFAULT> Lexeme '" << yytext << "' found." << endl;}
continue {output << "<CONTINUE>"; logg << "Line no: " << line_no << " Token <CONTINUE> Lexeme '" << yytext << "' found." << endl;}

[0-9]+ {output << "<CONST_INT," << yytext << ">"; logg << "Line no: " << line_no << " Token <CONST_INT> Lexeme '" << yytext << "' found." << endl; insert_symbol("CONST_INT", yytext);}
[0-9]*\.[0-9]+([eE][+-]?[0-9]+)? {output << "<CONST_FLOAT," << yytext << ">"; logg << "Line no: " << line_no << " Token <CONST_FLOAT> Lexeme '" << yytext << "' found." << endl; insert_symbol("CONST_FLOAT", yytext);}
'\''[^\']'\'' {output << "<CONST_CHAR," << yytext[1] << ">"; logg << "Line no: " << line_no << " Token <CONST_CHAR> Lexeme '" << yytext << "' found." << endl; insert_symbol("CONST_CHAR", yytext);}

"++" {output << "<INCOP," << yytext << ">"; logg << "Line no: " << line_no << " Token <INCOP> Lexeme '" << yytext << "' found." << endl;}
"--" {output << "<DECOP," << yytext << ">"; logg << "Line no: " << line_no << " Token <DECOP> Lexeme '" << yytext << "' found." << endl;}
"+" {output << "<ADDOP," << yytext << ">"; logg << "Line no: " << line_no << " Token <ADDOP> Lexeme '" << yytext << "' found." << endl;}
"-" {output << "<SUBOP," << yytext << ">"; logg << "Line no: " << line_no << " Token <SUBOP> Lexeme '" << yytext << "' found." << endl;}
"*" {output << "<MULOP," << yytext << ">"; logg << "Line no: " << line_no << " Token <MULOP> Lexeme '" << yytext << "' found." << endl;}
"/" {output << "<DIVOP," << yytext << ">"; logg << "Line no: " << line_no << " Token <DIVOP> Lexeme '" << yytext << "' found." << endl;}
"=" {output << "<ASSIGNOP," << yytext << ">"; logg << "Line no: " << line_no << " Token <ASSIGNOP> Lexeme '" << yytext << "' found." << endl;}
"&&" {output << "<LOGICOP," << yytext << ">"; logg << "Line no: " << line_no << " Token <LOGICOP> Lexeme '" << yytext << "' found." << endl;}
"||" {output << "<LOGICOP," << yytext << ">"; logg << "Line no: " << line_no << " Token <LOGICOP> Lexeme '" << yytext << "' found." << endl;}
"!" {output << "<NOT," << yytext << ">"; logg << "Line no: " << line_no << " Token <NOT> Lexeme '" << yytext << "' found." << endl;}
"<" {output << "<RELOP,<>"; logg << "Line no: " << line_no << " Token <RELOP> Lexeme '" << yytext << "' found." << endl;}
"<=" {output << "<RELOP,<=>"; logg << "Line no: " << line_no << " Token <RELOP> Lexeme '" << yytext << "' found." << endl;}
">" {output << "<RELOP,>"; logg << "Line no: " << line_no << " Token <RELOP> Lexeme '" << yytext << "' found." << endl;}
">=" {output << "<RELOP,>=>"; logg << "Line no: " << line_no << " Token <RELOP> Lexeme '" << yytext << "' found." << endl;}
"==" {output << "<RELOP,==>"; logg << "Line no: " << line_no << " Token <RELOP> Lexeme '" << yytext << "' found." << endl;}
"!=" {output << "<RELOP,!=>"; logg << "Line no: " << line_no << " Token <RELOP> Lexeme '" << yytext << "' found." << endl;}

";" {output << "<SEMICOLON," << yytext << ">"; logg << "Line no: " << line_no << " Token <SEMICOLON> Lexeme '" << yytext << "' found." << endl;}
"," {output << "<COMMA," << yytext << ">"; logg << "Line no: " << line_no << " Token <COMMA> Lexeme '" << yytext << "' found." << endl;}
"(" {output << "<LPAREN," << yytext << ">"; logg << "Line no: " << line_no << " Token <LPAREN> Lexeme '" << yytext << "' found." << endl;}
")" {output << "<RPAREN," << yytext << ">"; logg << "Line no: " << line_no << " Token <RPAREN> Lexeme '" << yytext << "' found." << endl;}
"{" {output << "<LCURL," << yytext << ">"; logg << "Line no: " << line_no << " Token <LCURL> Lexeme '" << yytext << "' found." << endl;}
"}" {output << "<RCURL," << yytext << ">"; logg << "Line no: " << line_no << " Token <RCURL> Lexeme '" << yytext << "' found." << endl;}
"[" {output << "<LTHIRD," << yytext << ">"; logg << "Line no: " << line_no << " Token <LTHIRD> Lexeme '" << yytext << "' found." << endl;}
"]" {output << "<RTHIRD," << yytext << ">"; logg << "Line no: " << line_no << " Token <RTHIRD> Lexeme '" << yytext << "' found." << endl;}

[a-zA-Z_][a-zA-Z0-9_]* {output << "<ID," << yytext << ">"; logg << "Line no: " << line_no << " Token <ID> Lexeme '" << yytext << "' found." << endl; insert_symbol("ID", yytext);}

\".*\" {output << "<STRING," << yytext << ">"; logg << "Line no: " << line_no << " Token <STRING> Lexeme '" << yytext << "' found." << endl; insert_symbol("STRING", yytext);}

\n {line_no++;}

. {errorLog << "Line no: " << line_no << " Unrecognized token '" << yytext << "' found." << endl; error_count++;}

%%

int main(int argc, char** argv) {
    yylex();
    logg << "Total number of errors: " << error_count << endl;
    output.close();
    logg.close();
    errorLog.close();
    return 0;
}

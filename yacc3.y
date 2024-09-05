%{
#include <bits/stdc++.h>
#include "symboltable.h"

extern int line_no;
extern symboltable s;
extern int yylex();
extern int yyparse();
extern FILE *yyin;

ofstream logfile("log_error.txt");

void yyerror(const char *s) {
    logfile << "Syntax error at line " << line_no << ": " << s << endl;
}
%}

%union {
    int ival;
    char *sval;
}

%type <sval> type_spec func_decl
%type <ival> expr term decl_list

%token ASSIGNOP ADDOP SUBOP MULOP DIVOP LOGICOP NOT RELOP
%token LPAREN RPAREN LCURL RCURL LTHIRD RTHIRD COMMA SEMICOLON
%token CONST_INT CONST_FLOAT ID INT CHAR FLOAT DOUBLE VOID RETURN BREAK IF ELSE FOR WHILE DO CASE DEFAULT CONTINUE

%%

mul_stmt:
    mul_stmt func_decl { logfile << "Matched rule: mul_stmt -> mul_stmt func_decl" << endl; }
    | func_decl { logfile << "Matched rule: mul_stmt -> func_decl" << endl; }
    ;

func_decl:
    type_spec term LPAREN RPAREN LCURL stmt RCURL { logfile << "Matched rule: func_decl -> type_spec term () {}" << endl; }
    ;

stmt:
    stmt unit { logfile << "Matched rule: stmt -> stmt unit" << endl; }
    | unit { logfile << "Matched rule: stmt -> unit" << endl; }
    ;

unit:
    var_decl SEMICOLON { logfile << "Matched rule: unit -> var_decl ;" << endl; }
    | expr_decl SEMICOLON { logfile << "Matched rule: unit -> expr_decl ;" << endl; }
    ;

var_decl:
    type_spec decl_list { logfile << "Matched rule: var_decl -> type_spec decl_list" << endl; }
    ;

type_spec:
    INT { $$ = strdup("int"); }
    | FLOAT { $$ = strdup("float"); }
    | DOUBLE { $$ = strdup("double"); }
    ;

decl_list:
    decl_list COMMA term { logfile << "Matched rule: decl_list -> decl_list , term" << endl; }
    | term { logfile << "Matched rule: decl_list -> term" << endl; }
    | term LTHIRD CONST_INT RTHIRD { logfile << "Matched rule: decl_list -> term [ CONST_INT ]" << endl; }
    ;

expr_decl:
    term ASSIGNOP expr { logfile << "Matched rule: expr_decl -> term = expr" << endl; }
    ;

expr:
    CONST_INT { $$ = atoi(yytext); }
    | CONST_FLOAT { $$ = atof(yytext); }
    | expr ADDOP expr { $$ = $1 + $3; logfile << "Matched rule: expr -> expr + expr" << endl; }
    | expr MULOP expr { $$ = $1 * $3; logfile << "Matched rule: expr -> expr * expr" << endl; }
    | LPAREN expr RPAREN { $$ = $2; logfile << "Matched rule: expr -> ( expr )" << endl; }
    | term { $$ = $1; }
    ;

term:
    ID { $$ = atoi(yytext); if (s.lookup(yytext) == NULL) { insert_symbol("ID", yytext); } }
    ;

%%

int main() {
    return yyparse();
}

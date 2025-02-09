%{
#include <stdio.h>
#include <stdlib.h>

extern int yylex();
extern int yyparse();
extern FILE* yyin;

void yyerror(const char* s);
%}

%token NUMBER
%%
statements: expressions { printf("= %d\n",$1); }
	;
expressions: expressions '+' NUMBER { $$ = $1 + $3; }
	| expressions '-' NUMBER { $$ = $1 - $3; }
	| NUMBER { $$ = $1; }
	;
%%
int main(){
	yyin = stdin;
	do {
		yyparse();
	} while(!feof(yyin));

	return 0;
}

void yyerror(const char* s) {
	fprintf(stderr, "Parse error: %s\n", s);
	exit(1);
}

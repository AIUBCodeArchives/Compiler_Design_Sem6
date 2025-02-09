%{  
int n = 0 ;   
%}

%%
"while"|"if"|"else" {n++;printf("\t keywords : %s", yytext);}   
"int"|"float" {n++;printf("\t keywords : %s", yytext);}  
"<="|"=="|"="|"++"|"-"|"*"|"+" {n++;printf("\t operator : %s", yytext);} 
[a-zA-Z_][a-zA-Z0-9_]*	{n++;printf("\t identifier : %s", yytext);}
[(){}|, ;]	{n++;printf("\t separator : %s", yytext);}
[0-9]*"."[0-9]+	{n++;printf("\t float : %s", yytext);}
[0-9]+	{n++;printf("\t integer : %s", yytext);}
.	;
%%


int yywrap()
{
	return 1;
}
int main()

{

    yylex();
    printf("\n total no. of token = %d\n", n);

    return 0;

}

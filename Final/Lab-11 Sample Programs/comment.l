%{

%}

%%
^"//"	{printf("This is a single line comment\n");}
^"/*"[^*]*|[*]*"*/"	{printf("This is a Multiline Comment\n");}   
\n	;
%%


int yywrap()
{
    return 0;
}
int main()
{
    yylex();
}
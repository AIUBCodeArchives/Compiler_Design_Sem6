%{
 
 
/*USE OF REJECT STATEMENT*/
#undef yywrap
#define yywrap() 1
 
%}
 
 
%%
a     |
ab    |
abc   |
abcd  ECHO;printf("\nl: ");REJECT;
.|\n  printf("\ns: XX");
%%
 
 
int main()
{
 yylex();
}
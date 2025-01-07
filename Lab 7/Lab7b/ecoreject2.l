
%{
 
 
/*USE OF REJECT STATEMENT*/
#undef yywrap
#define yywrap() 1
 
%}
 
 
%%
 
 
[a-z]+ {
 printf("\ncontains only lowercase letters = ");
 ECHO;
 
 }
 
[a-zA-Z]+ {
 printf("\ncontains both uppercase and lowercase letters = ");
 ECHO;
 REJECT;
 
 }
 
. {
 printf("\ncontains mixed letters = ");
 ECHO;
 
 }
 
%%
 
 
 
int main()
{
 yylex();
}
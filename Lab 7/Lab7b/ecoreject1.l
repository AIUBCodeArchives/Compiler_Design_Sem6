%{
 
 
/*USE OF REJECT STATEMENT*/
#undef yywrap
#define yywrap() 1
 
%}
 
%s	one
%x	two
%%
abc     {printf("matched ");ECHO;BEGIN one;}
<one>def         {printf("matched ");ECHO;BEGIN two;}
<two>ghi         {printf("matched ");ECHO;BEGIN INITIAL;}
%%
 
 
int main()
{
 yylex();
}
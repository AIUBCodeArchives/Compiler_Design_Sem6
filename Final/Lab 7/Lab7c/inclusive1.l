
%{
 
/*Inclusive start condition*/
#undef yywrap
#define yywrap() 1 
 
%}
 
 
%s SM SMBG
 
 
%%
 
 
# BEGIN(SM);
## BEGIN(SMBG);
 
[0-9]+ {
 printf("Contains only digits");
}
 
<SMBG>[A-Z]+ {
 printf("Contains uppercase letters"); 
 }
 
<SM>. {
 printf("Exiting from # start condition"); 
 BEGIN(INITIAL); 
}
 
<SM,SMBG>[a-z]+ {
 printf("Contains lowercase letters");
 
}
 
<SMBG>.+ {
 printf("Exiting from ## start condition"); 
 BEGIN(INITIAL); 
}
 
.+ {
 printf("No action exexuted"); 
 
}
 
%%
 
 
int main()
{
 printf("Enter # when expecting digits or lowercase letters");
 printf(" Enter ## when expecting only lowercase and uppercase letters");
 yylex();
}
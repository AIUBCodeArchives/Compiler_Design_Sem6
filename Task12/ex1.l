/* Declaring counters: one for number of lines, 
   another for number of characters, and one for number of strings */
%{
int no_of_lines = 0;
int no_of_chars = 0;
int no_of_strings = 0;
%}

/*** rule 1 counts the number of lines,
     rule 2 counts the number of characters,
     rule 3 counts the number of strings,
     and rule 4 specifies when to stop taking input ***/
%%
\n              { ++no_of_lines; ++no_of_chars; }  // Increment both line and character count for newlines
[^\n\t ]+       { ++no_of_strings; no_of_chars += yyleng; }  // Match strings and update character count based on length of string
.               { ++no_of_chars; }  // Match any single character (spaces, tabs, punctuation, etc.)
end[\n\t ]    return 0;           // Stops when 'end' is encountered, followed by optional spaces, tabs, or newlines
%%

/*** User code section ***/
int yywrap() {}
int main(int argc, char **argv)
{
    yylex();
    printf("number of lines = %d, number of chars = %d, number of strings = %d\n",
           no_of_lines, no_of_chars, no_of_strings);
    return 0;
}
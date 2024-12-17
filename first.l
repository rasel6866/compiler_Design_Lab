
%{
   #include<stdio.h>
%}

%%
if |
else |
printf {printf ("%s is a keyword.", yytext);}
[0-9]+ {printf ("%s is a number.", yytext);}
[a-zA-Z]+ {printf ("%s is a identifier.", yytext);}
.|\n {ECHO;}
%%

int main()
{
    printf("Enter a String ");
    yylex();
}
int yywrap()
{
    return 1;
}

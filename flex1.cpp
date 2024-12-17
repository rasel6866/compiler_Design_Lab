%{
%include<stdio.h>
%}

%%
if|
else |
printf {printf ("% s is a keword." ,yytext);}
[0-9]+ {printf("% s is a number." ,yytext);}
[a-aA-Z]+ {printf("% s is a identifiers." ,yytext);}
.|\n {ECHO;}
%%
int main()
{

    printf("Enter a string ");
    yytext();



}
int yywrap()
{

    return 1;

}


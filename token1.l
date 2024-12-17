%{
#include<stdio.h>
int x=0,y=0,z=0,p=0,a=0,b=0,c=0,d=0,X=0;
%}
%%
auto|break|case|char|const|continue|default|do|double|else|enum|extern|float|for|goto|if|int|long|register|return|short|signed|sizeof|static|struct|switch|typedef|union|unsigned|void|volatile|while printf("\n %s is an Keyword",yytext);
[0-9]+ printf("\n %s is an Constants",yytext);
[+] {a++;x=1;}
[-] {b++;y=1;}
[*] {c++;z=1;}
[/] {d++;p=1;}
[a-zA-z]+ printf("\n %s is an Identifier",yytext);
[(){}();,.=*&^%$#@!'":|\/?><] {X++;}



%%
int main(void){
	yyin= fopen("file.txt","r");
	yylex();
	printf("\n Operators used:\n");
	if(x==1)
	printf("+\t");
	if (y==1)
	printf("-\t");
	if(z==1)
	printf("*\t");
	if(p==1)
	printf("/\n");
}
int yywrap(){
	return(1);
}

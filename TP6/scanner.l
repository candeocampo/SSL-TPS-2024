%{
#include "parser.h"
#include<stdio.h>
#include<string.h>
%}

%{
char buffer[200];
%}

%option header-file="scanner.h"
%option outfile="scanner.c"
%option noinput
%option nounput
%option yylineno

letra                 [a-zA-Z]
digito                [0-9]
identificador         {letra}({letra}|{digito})*
numero                {digito}+
espacio               [[:space:]]
operador              [+\-*/%]
caracter_puntuacion   [\(\),;]
asignacion            ":="
caracter_invalido  [[:punct:]]{-}[,;:=+\-*/%()]

%%

programa               return PROGRAMA;
fin                    return FIN;
entero                 return ENTERO;
escribir               return ESCRIBIR;
leer                   return LEER;
{identificador}        { yylval = strdup(yytext); return IDENTIFICADOR; }
{numero}               { yylval = strdup(yytext); return CONSTANTE; }
"+"                    return '+';
"-"                    return '-';
"*"                    return '*';
"/"                    return '/';
"%"                    return '%';
"("                    return '(';
")"                    return ')';
","                    return ',';
";"                    return ';';
{asignacion}           return ASIGNACION;
"//".*\n               ;

{identificador}{caracter_invalido}({letra}|{digito}|{caracter_invalido})* { sprintf(buffer, "Error léxico: identificador inválido: %s", yytext); yyerror(buffer); yylexerrs++; }
{digito}+{letra}({digito}|{letra})* { sprintf(buffer, "Error léxico: constante inválida: %s", yytext); yyerror(buffer); yylexerrs++; }
{caracter_invalido}+ { sprintf(buffer, "Error léxico: cadena desconocida: %s", yytext); yyerror(buffer); yylexerrs++; }
[:=] { sprintf(buffer, "Error léxico: asignación mal formada: %s", yytext); yyerror(buffer); yylexerrs++;}
.|\n                   ;

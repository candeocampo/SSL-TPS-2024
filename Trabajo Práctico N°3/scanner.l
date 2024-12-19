%{
#include "tokens.h"
%}

%option header-file="scanner.h"
%option outfile="scanner.c"
%option noinput
%option nounput

letra                 [a-zA-Z]
digito                [0-9]
identificador         {letra}({letra}|{digito})*
numero                {digito}+
espacio               " "|\t|\n
operador              [+\-*/%]
caracter_puntuacion   [\(\),;]
asignacion            ":="
caracter_invalido  [^a-zA-Z0-9+\-*/%\(\),;:= \t\n]

%%

programa               return PROGRAMA;
fin                    return FIN;
entero                 return ENTERO;
escribir               return ESCRIBIR;
leer                   return LEER;
{identificador}        return IDENTIFICADOR;
{numero}               return CONSTANTE;
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
{identificador}{caracter_invalido}({letra}|{digito}|{caracter_invalido})*   printf("Error léxico: identificador inválido: %s\n", yytext);
{digito}+{letra}({digito}|{letra})*   printf("Error léxico: constante inválida: %s\n", yytext);
[^a-zA-Z0-9+\-*/%\(\),; \t\n]+   printf("Error léxico: cadena desconocida: %s\n", yytext);
.|\n                   ;


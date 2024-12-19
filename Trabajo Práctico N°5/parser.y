%code top {
    #include <stdio.h>
    #include "scanner.h"
}

%code provides {
    void yyerror(const char *msg);
    extern int yylexerrs;
    extern int yynerrs;
}

%defines "parser.h"
%output "parser.c"
%start programa
%define parse.error verbose

%token PROGRAMA FIN IDENTIFICADOR CONSTANTE ENTERO ESCRIBIR LEER

// Precedencias y asociaciones
%token ASIGNACION ":="
%left '+' '-'
%left '*' '/' '%'
%precedence NEG

%define api.value.type {char *}

%%

programa : PROGRAMA IDENTIFICADOR {printf("programa: %s\n", $2);} listaSentencias FIN { if (yynerrs || yylexerrs) YYABORT;};
listaSentencias : sentencia
                  | listaSentencias sentencia
                  ;
sentencia : ENTERO IDENTIFICADOR ';' {printf("Sentencia declaración: %s\n", $2);}
            | IDENTIFICADOR ASIGNACION expresion ';' {printf("Sentencia asignación\n");}
            | LEER '(' listaIdentificadores ')' ';' {printf("Sentencia leer\n");}
            | ESCRIBIR '(' listaExpresiones ')' ';' {printf("Sentencia escribir\n");}
            | error ';'
            ;
listaIdentificadores : IDENTIFICADOR
                       | listaIdentificadores ',' IDENTIFICADOR
                       ;
listaExpresiones : expresion
                   | listaExpresiones ',' expresion
                   ;
expresion : primaria
            | expresion '+' expresion {printf("suma\n");}
            | expresion '-' expresion {printf("resta\n");}
            | expresion '*' expresion {printf("multiplicación\n");}
            | expresion '/' expresion {printf("división\n");}
            | expresion '%' expresion {printf("módulo\n");}
            | '(' {printf("abre paréntesis\n");} expresion ')' {printf("cierra paréntesis\n");}
            | '-' expresion %prec NEG {printf("inversión\n");}
            ;
primaria : IDENTIFICADOR
           | CONSTANTE

%%

int yylexerrs = 0;

void yyerror(const char *msg){
	printf("línea #%d: %s\n", yylineno, msg);
}
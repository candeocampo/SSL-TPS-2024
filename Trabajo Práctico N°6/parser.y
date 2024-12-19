%code top {
    #include <stdio.h>
    #include "scanner.h"
    #include "semantic.h"
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

programa : {comenzar();} PROGRAMA IDENTIFICADOR listaSentencias FIN { finalizar(); if (yynerrs || yylexerrs || errores_sem) YYABORT;};
listaSentencias : sentencia
                  | listaSentencias sentencia
                  ;
sentencia : ENTERO IDENTIFICADOR ';' {if (declarar($2)) YYERROR;}
            | identificador ASIGNACION expresion ';' {asignar($1, $3);}
            | LEER '(' listaIdentificadores ')' ';'
            | ESCRIBIR '(' listaExpresiones ')' ';'
            | error ';'
            ;
listaIdentificadores : identificador {leer($1);}
                       | listaIdentificadores ',' identificador {leer($3);}
                       ;
listaExpresiones : expresion {escribir($1);}
                   | listaExpresiones ',' expresion {escribir($3);}
                   ;
expresion : primaria
            | expresion '+' expresion {$$ = generar_infijo($1,'+',$3);}
            | expresion '-' expresion {$$ = generar_infijo($1,'-',$3);}
            | expresion '*' expresion {$$ = generar_infijo($1,'*',$3);}
            | expresion '/' expresion {$$ = generar_infijo($1,'/',$3);}
            | expresion '%' expresion {$$ = generar_infijo($1,'%',$3);}
            | '(' expresion ')' {$$ = $2;}
            | '-' expresion %prec NEG {$$ = generar_unario($2);}
            ;
primaria : identificador
           | CONSTANTE
           ;
identificador : IDENTIFICADOR {if (verificar_identificador($1)) YYERROR;};

%%

int yylexerrs = 0;

void yyerror(const char *msg){
	printf("Línea #%d: %s\n", yylineno, msg);
}
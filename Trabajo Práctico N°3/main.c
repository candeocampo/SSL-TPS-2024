#include <stdio.h>
#include "tokens.h"

extern int yylex();
extern char *yytext;

int main(){
    int token_leido;
    while((token_leido = yylex()) != FDT){
        switch (token_leido){
        case PROGRAMA:
            printf("Token: Programa\n");
            break;
        case FIN:
            printf("Token: Fin\n");
            break;
        case IDENTIFICADOR:
            printf("Token: Identificador        lexema: %s\n", yytext);
            break;
        case CONSTANTE:
            printf("Token: Constante        lexema: %s\n", yytext);
            break;
        case ENTERO:
            printf("Token: Entero\n");
            break;
        case ESCRIBIR:
            printf("Token: Escribir\n");
            break;
        case LEER:
            printf("Token: Leer\n");
            break;
        case ASIGNACION:
            printf("Token: Asignación\n");
            break;
        default:
            printf("Token: '%c'\n", token_leido);
            break;
        }
    }
    return 0;
}


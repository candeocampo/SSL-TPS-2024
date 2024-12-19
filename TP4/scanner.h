#ifndef SCANNER_H
#define SCANNER_H

#include <stdbool.h>

enum token{
    IDENTIFICADOR = 100,
    CONSTANTE,
    SUMA,
    RESTA,
    MULTIPLICACION,
    DIVISION,
    MODULO,
    PARENTESIS_ABRE,
    PARENTESIS_CIERRA,
    COMA,
    PUNTO_Y_COMA,
    ASIGNACION,
    PROGRAMA,
    ENTERO,
    LEER,
    ESCRIBIR,
    FIN,
    FDT = 199,
    ERROR_LEXICO
};

enum error_lexico {
    ERROR_GENERAL = 200,
    ERROR_N2 = 201,
    ERROR_N1 = 202
};

enum token prox_token(void);
void match(enum token tok);
int scanner(void);
void print_error_lexico(enum error_lexico token_error);
void print_error_sintactico(enum token tok);

extern char lexema[1000]; 

#endif


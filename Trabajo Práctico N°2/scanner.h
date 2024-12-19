#ifndef SCANNER_H
#define SCANNER_H

extern char lexema[1000];

enum tipo_token {
    IDENTIFICADOR = 100,
    CONSTANTE = 101,
    SUMA = 102,
    MENOS = 103,
    MULTIPLICACION = 104,
    DIVISION = 105,
    MODULO = 106,
    PARENTESIS_ABRE = 107,
    PARENTESIS_CIERRA = 108,
    COMA = 109,
    PUNTOYCOMA = 110,
    ASIGNACION = 111,
    FIN_ARCHIVO = 199,
    ERROR_GENERAL = 200,
    ERROR_N1 = 201,
    ERROR_N2 = 202
};

int scanner();

#endif // SCANNER_H
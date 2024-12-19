#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "scanner.h"

char lexema [1000];

enum tipo_char {
    C_LETRA,
    C_DIGITO,
    C_MAS,
    C_MENOS,
    C_MULTIPLICACION,
    C_DIVISION,
    C_MODULO,
    C_PARENTESIS_ABRE,
    C_PARENTESIS_CIERRA,
    C_COMA,
    C_PUNTO_Y_COMA,
    C_DOS_PUNTOS,
    C_IGUAL,
    C_FDT,
    C_ESPACIO,
    C_OTRO
};

int tabla_transicion[5][16] = {
//    L    D    +    -    *    /    %    (    )    ,    ;    :    =   fdt  esp  otro
    { 1 ,  2 , 102, 103, 104, 105, 106, 107, 108, 109, 110,  3 , 201, 199,  0 ,  4 }, // 0
    { 1 ,  1 , 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100}, // 1
    {101,  2 , 101, 101, 101, 101, 101, 101, 101, 101, 101, 101, 101, 101, 101, 101}, // 2
    {202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 111, 202, 202, 202}, // 3
    {200, 200, 200, 200, 200, 200, 200, 200, 200, 200, 200, 200, 200, 200, 200,  4 }  // 4
};


int debe_detenerse(int estado) {
    return estado >= 100;
}

enum tipo_char tipo_caracter(int caracter) {
    if (isalpha(caracter))
        return C_LETRA;
    if (isdigit(caracter))
        return C_DIGITO;
    if (caracter == '+')
        return C_MAS;
    if (caracter == '-')
        return C_MENOS;
    if (caracter == '*')
        return C_MULTIPLICACION;
    if (caracter == '/')
        return C_DIVISION;
    if (caracter == '%')
        return C_MODULO;
    if (caracter == '(')
        return C_PARENTESIS_ABRE;
    if (caracter == ')')
        return C_PARENTESIS_CIERRA;
    if (caracter == ',')
        return C_COMA;
    if (caracter == ';')
        return C_PUNTO_Y_COMA;
    if (caracter == ':')
        return C_DOS_PUNTOS;
    if (caracter == '=')
        return C_IGUAL;
    if (caracter == EOF)
        return C_FDT;
    if (isspace(caracter))
        return C_ESPACIO;
    return C_OTRO;
}


int usa_centinela(int estado) {
    return estado == 100 || estado == 101 || estado == 200;
}

int aceptor(int estado) {
    return 100 <= estado && estado < 200;
}




int scanner() {
    int estado = 0;
    int caracter;
    int contador = 0;

    while (!debe_detenerse(estado)) {
        
        caracter = getchar();
        enum tipo_char tipo_char = tipo_caracter(caracter);
        estado = tabla_transicion[estado][tipo_char];
        if (estado != 0)
        {
            lexema[contador] = caracter;
            contador++;
        }
        
        
    }


    if (usa_centinela(estado)) {
        ungetc(caracter, stdin);
        contador--;
    }

    lexema[contador] = '\0';

    return estado;
}
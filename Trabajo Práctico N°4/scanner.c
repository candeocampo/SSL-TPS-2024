
// falta agregarle las funciones match y prox_token

#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "scanner.h"

char lexema [1000];

static bool debo_escanear = true;
static enum token token_actual;

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

enum token buscar_lexema_en_tabla_palabras_reservadas();


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


bool usa_centinela(int estado) {
    return estado == 100 || estado == 101 || estado == 200;
}

bool aceptor(int estado) {
    return 100 <= estado && estado < 200;
}

bool estado_error(int estado) {
    return estado >= 200;
}


void print_error_lexico(enum error_lexico token_error) {
    switch (token_error) {
        case ERROR_GENERAL:
            printf("Error general '%s'\n", lexema);
            break;
        case ERROR_N1:
            printf("Error en asignación por : solo ':'\n");
            break;
        case ERROR_N2:
            printf("Error en asignación por = solo '='\n");
            break;
    }
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


enum token prox_token() {
    if (debo_escanear) {
        token_actual = scanner();
        while (estado_error(token_actual)) {
            print_error_lexico(token_actual);
            token_actual = scanner();
        }
        debo_escanear = false;
        if (token_actual == IDENTIFICADOR) {
            token_actual = buscar_lexema_en_tabla_palabras_reservadas();
        }
    }
    return token_actual;
}


void match(enum token tok) {
    if (tok != prox_token())
        print_error_sintactico(prox_token());
    debo_escanear = true;
}


enum token buscar_lexema_en_tabla_palabras_reservadas() {
    if (strcmp(lexema, "programa") == 0)
        return PROGRAMA;
    if (strcmp(lexema, "entero") == 0)
        return ENTERO;
    if (strcmp(lexema, "leer") == 0)
        return LEER;
    if (strcmp(lexema, "escribir") == 0)
        return ESCRIBIR;
    if (strcmp(lexema, "fin") == 0)
        return FIN;
    return IDENTIFICADOR;
}


void print_error_sintactico(enum token tok) {
    char *token_str;
    switch (tok) {
    case IDENTIFICADOR:
        token_str = "Identificador";
        break;
    case CONSTANTE:
        token_str = "Constante";
        break;
    case SUMA:
        token_str = "Más";
        break;
    case RESTA:
        token_str = "Menos";
        break;
    case MULTIPLICACION:
        token_str = "Por";
        break;
    case DIVISION:
        token_str = "Dividido";
        break;
    case MODULO:
        token_str = "Módulo";
        break;
    case PARENTESIS_ABRE:
        token_str = "Abrir Paréntesis";
        break;
    case PARENTESIS_CIERRA:
        token_str = "Cerrar Paréntesis";
        break;
    case COMA:
        token_str = "Coma";
        break;
    case PUNTO_Y_COMA:
        token_str = "Punto y Coma";
        break;
    case ASIGNACION:
        token_str = "Asignación";
        break;
    case PROGRAMA:
        token_str = "Programa";
        break;
    case ENTERO:
        token_str = "Entero";
        break;
    case LEER:
        token_str = "Leer";
        break;
    case ESCRIBIR:
        token_str = "Escribir";
        break;
    case FIN:
        token_str = "Fin";
        break;
    case FDT:
        token_str = "Fin de texto";
    default:
        token_str = "";
        break;
    }
    printf("Error Sintáctico, no se esperaba el token %s ('%s')\n", token_str, lexema); // Mostrar bien el token inesperado
}
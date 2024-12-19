
#include<stdio.h>
#include "scanner.h"
#include "parser.h"

void parse_lista_sentencias(void);
void parse_sentencia(void);
void parse_lista_identificadores(void);
void parse_lista_expresiones(void);
void parse_expresion(void);
void parse_termino(void);
void parse_primaria(void);

void parser(void){
    match(PROGRAMA);
    match(IDENTIFICADOR);
    printf("Programa: %s\n",lexema);
    parse_lista_sentencias();
    match(FIN);
    printf("fin\n");
}

void parse_lista_sentencias(void) {
    parse_sentencia();
    while (true) {
        switch (prox_token()) {
        case ENTERO:
        case IDENTIFICADOR:
        case LEER:
        case ESCRIBIR:
            parse_sentencia();
            break;
        default:
            return;
        }
    }
}

void parse_sentencia(void) {
    enum token t = prox_token();
    switch (t) {
    case ENTERO:
        printf("Sentencia declaración\n");
        match(ENTERO);
        match(IDENTIFICADOR);
        match(PUNTO_Y_COMA);
        break;
    case IDENTIFICADOR:
        printf("Sentencia asignación\n");
        match(IDENTIFICADOR);
        match(ASIGNACION);
        parse_expresion();
        match(PUNTO_Y_COMA);
        break;
    case LEER:
        printf("Sentencia leer\n");
        match(LEER);
        match(PARENTESIS_ABRE);
        parse_lista_identificadores();
        match(PARENTESIS_CIERRA);
        match(PUNTO_Y_COMA);
        break;
    case ESCRIBIR:
        printf("Sentencia escribir\n");
        match(ESCRIBIR);           
        match(PARENTESIS_ABRE);
        parse_lista_expresiones();   
        match(PARENTESIS_CIERRA); 
        match(PUNTO_Y_COMA);    
        break;
    default:
        print_error_sintactico(t);
        break;
    }
}


void parse_lista_identificadores(void) {
    match(IDENTIFICADOR);
    while (prox_token() == COMA) {
        match(COMA);
        match(IDENTIFICADOR);
    }
}


void parse_lista_expresiones(void) {
    parse_expresion();
    while (prox_token() == COMA) {
        match(COMA);
        parse_expresion();
    }
}


void parse_expresion(void) {
    parse_termino();
    while (prox_token() == SUMA || prox_token() == RESTA) {
        match(prox_token());
        parse_termino();
    }
}


void parse_termino(void) {
    parse_primaria();
    while (prox_token() == MULTIPLICACION || prox_token() == DIVISION || prox_token() == MODULO) {
        match(prox_token());
        parse_primaria();
    }
}


void parse_primaria(void) {
    enum token t = prox_token();
    switch (t) {
    case IDENTIFICADOR:
    case CONSTANTE:
        match(t);
        break;
    case PARENTESIS_ABRE:
        match(PARENTESIS_ABRE);
        parse_expresion();
        match(PARENTESIS_CIERRA);
        break;
    case RESTA:
        match(RESTA);
        parse_expresion();
        break;
    default:
        print_error_sintactico(t);
        break;
    }
}
#include <stdio.h>
#include "scanner.h"




int main() {
    enum tipo_token tokenLeido;
    do {
        tokenLeido = scanner();

        switch (tokenLeido) {
            case IDENTIFICADOR:
                printf("Identificador: '%s'\n", lexema);
                break;
            case CONSTANTE:
                printf("Constante: '%s'\n", lexema);
                break;
            case SUMA:
                printf("Operador suma: '+'\n");
                break;
            case MENOS:
                printf("Operador resta: '-'\n");
                break;
            case MULTIPLICACION:
                printf("Operador multiplicacion: '*'\n");
                break;
            case DIVISION:
                printf("Operador division: '/'\n");
                break;
            case MODULO:
                printf("Operador modulo: '%%'\n");
                break;
            case PARENTESIS_ABRE:
                printf("Parentesis que abre: '('\n");
                break;
            case PARENTESIS_CIERRA:
                printf("Parentesis que cierra: ')'\n");
                break;
            case COMA:
                printf("Coma: ','\n");
                break;
            case PUNTOYCOMA:
                printf("Punto y coma: ';'\n");
                break;
            case ASIGNACION:
                printf("Asignacion: ':='\n");
                break;
            case FIN_ARCHIVO:
                break;
            case ERROR_GENERAL:
                printf("Error general en el lexema: '%s'\n", lexema);
                break;
            case ERROR_N1:
                printf("Error de asignacion: se leyo ':' sin '='.\n");
                break;
            case ERROR_N2:
                printf("Error de asignacion: se leyo '=' sin ':' previo.\n");
                break;
            default:
                printf("Token no reconocido: '%s'\n", lexema);
                break;
        }
    } while (tokenLeido != FIN_ARCHIVO);

    return 0;
}





#include "semantic.h"
#include "symbol.h"
#include "parser.h"
#include <stdio.h>
#include <string.h>

int errores_sem = 0;
int nro_temp = 1;

void comenzar(void) {
    printf("#include <stdio.h>\n\n");
    printf("int main(void) {\n");
}



void finalizar(void) {
    printf("\treturn 0;\n}\n");
}

int declarar(char *identificador) {
    if (existe(identificador)) {
        errores_sem++;
        char buffer_error[200];
        sprintf(buffer_error, "Error semántico: identificador %s ya declarado", identificador);
        yyerror(buffer_error);
        return 1;
    }

    agregar(identificador);
    printf("\tint %s;\n", identificador);
    return 0;
}


void asignar(char *destino, char *origen) {
    printf("\t%s = %s;\n", destino, origen);
}

void leer(char *identificador) {
    printf("\tscanf(\"%%d\", &%s);\n", identificador);
}

void escribir(char *identificador) {
    printf("\tprintf(\"%%d\\n\", %s);\n", identificador);
}

int verificar_identificador(char *identificador) {
    if (!existe(identificador)) {
        errores_sem++;
        char buffer_error[200];
        sprintf(buffer_error, "Error semántico: identificador %s NO declarado", identificador);
        yyerror(buffer_error);
        return 1;
    }
    return 0;
}

char *generar_temporal(void) {
    char temp[200];
    sprintf(temp, "_Temp%i", nro_temp);
    nro_temp++;
    return strdup(temp);
}

char *generar_infijo(char *operando1, char operacion, char *operando2) {
    char *temp = generar_temporal();
    declarar(temp);
    printf("\t%s = %s %c %s;\n", temp, operando1, operacion, operando2);
    return temp;
}

char *generar_unario(char *operando) {
    char *temp = generar_temporal();
    declarar(temp);
    printf("\t%s = -%s;\n", temp, operando);
    return temp;
}
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "symbol.h"
#define MAX 200

char* tablaDeSimbolos[MAX];
int proximaPosDisp = 0;

int existe(char*cadena){
    for(int i=0;i<proximaPosDisp ; i++){
        if(!strcmp(tablaDeSimbolos[i],cadena))
        return 1;
    }
    return 0;
}

void agregar(char*cadena){
    if(proximaPosDisp < MAX){
        tablaDeSimbolos[proximaPosDisp] = cadena;
        proximaPosDisp ++;
    }else{
        printf("Se lleno la tabla de simbolos");
    }
}


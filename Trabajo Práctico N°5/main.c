#include <stdio.h>
#include "parser.h"
#include "scanner.h"

int main(){

    switch(yyparse()){
		case 0: printf("Compilación terminada con éxito");
			break;		
		case 1: printf("Errores de compilación");
			break;
		case 2: printf("No hay memoria suficiente");
			break;		
		}
    
    printf("\nErrores sintácticos:  %i\t - Errores léxicos:  %i\n", yynerrs, yylexerrs);
    
    return 0;

}

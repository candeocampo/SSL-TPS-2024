
#include <stdio.h>
#include "parser.h"
#include "scanner.h"
#include "symbol.h"
#include "semantic.h"

int main(void)
{	
	yyparse();
	if (yynerrs || yylexerrs || errores_sem)
		printf("Errores sintácticos: %d - Errores léxicos: %d - Errores semánticos: %d\n",yynerrs,yylexerrs,errores_sem);
	return 0;
}
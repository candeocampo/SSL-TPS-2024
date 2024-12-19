#ifndef SEMANTIC_H_INCLUDED
#define SEMANTIC_H_INCLUDED

extern int errores_sem;

int declarar(char*);
void comenzar(void);
void leer(char*);
void asignar(char*, char*);
void escribir(char*);
int verificar_identificador(char*);
char* generar_infijo(char*,char,char*);
char* generar_unario(char*);
char* generar_temporal(void);
void finalizar(void);

#endif // SEMANTIC_H_INCLUDED





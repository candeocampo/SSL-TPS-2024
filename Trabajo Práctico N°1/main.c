#include <stdio.h>
#include <stdlib.h>
#include "tabla.h"

int main(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Uso: %s inicio fin [incremento]\n", argv[0]);
        return 1;
    }

    double inicio = atof(argv[1]);
    double fin = atof(argv[2]);
    double incremento = (argc > 3) ? atof(argv[3]) : 1.0;

    if (incremento <= 0) {
        fprintf(stderr, "El incremento debe ser un valor positivo.\n");
        return 1;
    }

    crear_tabla(inicio, fin, incremento);

    return 0;
}
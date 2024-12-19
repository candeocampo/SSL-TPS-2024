#include "tabla.h"

void crear_tabla(double inicio, double fin, double incremento) {
    assert(inicio <= fin);
    assert(incremento > 0);

    printf("|      Nudos|       Km/h|\n");
    for (; inicio <= fin; inicio += incremento) {
        double convertido = conversion(inicio);
        printf("|%11g|%11g|\n", inicio, convertido);
    }
}
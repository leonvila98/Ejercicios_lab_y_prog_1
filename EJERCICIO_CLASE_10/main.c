#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pantalla.h"
#include "utn.h"

#define CANTIDAD_PANTALLAS 3
int main()
{
    Pantalla auxPantalla[CANTIDAD_PANTALLAS];
    int indicePantalla;

    pan_AltaPantalla(auxPantalla,CANTIDAD_PANTALLAS,&indicePantalla);
    pan_mostrarArrayPantalla(auxPantalla,CANTIDAD_PANTALLAS);

    return 0;
}

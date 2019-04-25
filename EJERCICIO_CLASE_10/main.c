#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pantalla.h"
#include "utn.h"

#define CANTIDAD_PANTALLAS 3
int main()
{
    Pantalla auxPantalla[CANTIDAD_PANTALLAS];

    auxPantalla[0].idPantalla=5;
    auxPantalla[1].idPantalla=10;
    auxPantalla[2].idPantalla=15;
    strncpy(auxPantalla[0].nombre,"juan",50);
    strncpy(auxPantalla[1].nombre,"carlos",50);
    strncpy(auxPantalla[2].nombre,"leon",50);

    pan_mostrarArrayPantalla(auxPantalla,CANTIDAD_PANTALLAS);
    return 0;
}

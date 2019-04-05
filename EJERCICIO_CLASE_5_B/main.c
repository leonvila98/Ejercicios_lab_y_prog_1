#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#define CANTIDAD_NUMEROS 5

int main()
{
    int array[CANTIDAD_NUMEROS]={5,4,3,2,1};
    burbujeoArrayInt(array,CANTIDAD_NUMEROS);
    mostrarArrayInt(array,CANTIDAD_NUMEROS);
}


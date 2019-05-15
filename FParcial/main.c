#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fantasma.h"
#include "utn.h"
#define QTY_FANTASMAS 10
#define SORT_UP 1
#define SORT_DOWN 0

int main()
{
    Fantasma arrayFantasma[QTY_FANTASMAS];
    int opcion=1;
    int i;
    fantasma_Inicializar(arrayFantasma,QTY_FANTASMAS);

    for(i=0;i<QTY_FANTASMAS;i++)
    {
        arrayFantasma[i].idUnico=i*2;
    }
    do
    {
        printf("\n1.Alta fantasma");
        printf("\n2.Baja fantasma");
        printf("\n3.Modificar fantasma");
        printf("\n4.Ver fantasma");
        printf("\n5.Salir");

        if(!utn_getInt("\nIngrese opcion:","\nOpcion invalida",1,5,2,&opcion))
        {
            switch(opcion)
            {
                case 1:
                    {
                        printf("\nAlta fantasma:\n");
                        if(!fantasma_alta(arrayFantasma,QTY_FANTASMAS))
                        {
                            printf("\nAlta con exito");
                        }
                        else
                        {
                            printf("\nNo hay lugar");
                        }
                        break;
                    }
                case 2:
                    {
                        printf("\nBaja fantasma:");
                        fantasma_listar(arrayFantasma,QTY_FANTASMAS);
                        if(!fantasma_baja(arrayFantasma,QTY_FANTASMAS))
                        {
                            printf("\nPantalla eliminada con exito");
                            break;
                        }
                        else
                        {
                            printf("\nERROR");
                        }
                    }
                case 3:
                    {
                        printf("\nModificar fantasma:\n");
                        fantasma_listar(arrayFantasma,QTY_FANTASMAS);
                        if(!fantasma_modificar(arrayFantasma,QTY_FANTASMAS))
                        {
                            printf("\nFantasma modificado con exito");
                            break;
                        }
                        else
                        {
                            printf("\nError");
                            break;
                        }
                    }
                case 4:
                    {
                        fantasma_listar(arrayFantasma,QTY_FANTASMAS);
                        break;
                    }

                case 5:
                    {
                        fantasma_ordenarPorDobleCriterio(arrayFantasma,QTY_FANTASMAS,SORT_UP,SORT_DOWN);
                    }
                default:
                    {
                        printf("\nError");
                        break;
                    }
            }
        }
        else
        {
            printf("ERROR");
        }
    }while(opcion!=5);

    return 0;
}

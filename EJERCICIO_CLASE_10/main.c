#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pantalla.h"
#include "publicidad.h"
#include "utn.h"

#define CANTIDAD_PANTALLAS 3
#define CANTIDAD_PUBLICIDADES 3
int main()
{
    Pantalla auxPantalla[CANTIDAD_PANTALLAS];
    Publicidad auxPublicidad[CANTIDAD_PUBLICIDADES];
    int indicePantalla;
    int indicePublicidad;
    int opcion=1;
    int i;
    int id;
    pan_initArray(auxPantalla,CANTIDAD_PANTALLAS);
    pub_initArray(auxPublicidad,CANTIDAD_PUBLICIDADES);

    strncpy(auxPantalla[0].nombre,"Pantalla1",50);
    strncpy(auxPantalla[0].direccion,"Calle 123",256);
    strncpy(auxPantalla[0].tipo,"LED",50);
    auxPantalla[0].isEmpty=0;
    strncpy(auxPantalla[1].nombre,"Pantalla2",50);
    strncpy(auxPantalla[1].direccion,"Calvo 321",256);
    strncpy(auxPantalla[1].tipo,"LCD",50);
    auxPantalla[1].isEmpty=0;
    strncpy(auxPantalla[2].nombre,"Pantalla3",50);
    strncpy(auxPantalla[2].direccion,"Primo 456",256);
    strncpy(auxPantalla[2].tipo,"LED",50);
    auxPantalla[2].isEmpty=0;

    for(i=0;i<CANTIDAD_PANTALLAS;i++)
    {
        auxPantalla[i].idPantalla=i*5;
    }

    do
    {
        printf("\n1.Alta pantalla");
        printf("\n2.Baja pantalla");
        printf("\n3.Modificar pantalla");
        printf("\n4.Contratar publicidad");
        printf("\n5.Modificar contratacion");
        printf("\n6.Cancelar contratacion");
        printf("\n7.Ver pantallas");
        printf("\n8.Salir");
        printf("\nIngrese opcion:");

        if(scanf("%d",&opcion))
        {
            switch(opcion)
            {
                case 1:
                    printf("\nAlta pantalla:\n");
                    if(pan_altaPantalla(auxPantalla,CANTIDAD_PANTALLAS,&indicePantalla)==0)
                    {
                        printf("Pantalla ingresada con exito\n");
                    }
                    else
                    {
                        printf("No hay lugar");
                    }
                    break;

                case 2:
                    printf("\nBaja pantalla:");
                    pan_mostrarArrayPantalla(auxPantalla,CANTIDAD_PANTALLAS);
                    getInt("\nIngrese id de pantalla:","ERROR",0,1000,2,&id);
                    if(pan_bajaPantalla(auxPantalla,id,CANTIDAD_PANTALLAS)==0)
                    {
                        printf("Pantalla eliminada con exito");
                    }
                    break;

                case 3:
                    printf("\nModificar pantalla:\n");
                    pan_mostrarArrayPantalla(auxPantalla,CANTIDAD_PANTALLAS);
                    printf("\nIngrese id de pantalla:");
                    scanf("%d",&id);
                    if(pan_modificarPantalla(auxPantalla,id,CANTIDAD_PANTALLAS))
                    {
                        printf("Pantalla modificada con exito");
                        break;
                    }
                    else
                    {
                        printf("Error");
                    }
                    break;

                case 4:
                    printf("\nContratar publicidad:\n");
                    pan_mostrarArrayPantalla(auxPantalla,CANTIDAD_PANTALLAS);
                    getInt("Ingrese id de pantalla a contratar:","Error",0,1000,2,&id);
                    if(pub_altaPublicidad(auxPublicidad,id,CANTIDAD_PUBLICIDADES,&indicePublicidad)==0)
                    {
                        printf("Publicidad contratada con exito");
                        break;
                    }
                    else
                    {
                        printf("Error");
                        break;
                    }
                    break;
                case 5:

                    break;
                case 6:
                    break;
                case 7:
                    printf("\nVer pantallas:\n");
                    if(pan_mostrarArrayPantalla(auxPantalla,CANTIDAD_PANTALLAS)==0)
                    {
                        break;
                    }
                    else
                    {
                        printf("No hay pantallas para mostrar\n");
                        break;
                    }
                default:
                    printf("\nError");
                    break;
            }
        }
        else
        {
            printf("ERROR");
        }
    }while(opcion!=8);

    return 0;
}

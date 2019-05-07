#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "Asociados.h"
#include "Llamadas.h"
#define QTY_ASOCIADOS 3
#define QTY_LLAMADAS 3

int main()
{
    Asociado auxAsociado[QTY_ASOCIADOS];
    Llamadas auxLlamada[QTY_LLAMADAS];
    int i;
    int opcion;
    int opcionInfo=0;
    int auxId;
    int indiceAsociado;
    int indiceLlamada;
    aso_initAsociado(auxAsociado,QTY_ASOCIADOS);
    lla_initLlamada(auxLlamada,QTY_LLAMADAS);

    for(i=0;i<QTY_ASOCIADOS;i++)
    {
        auxAsociado[i].idAsociado=i*5;
    }
    for(i=0;i<QTY_LLAMADAS;i++)
    {
        auxLlamada[i].idLlamada=i*2;
    }
    for(i=0;i<QTY_LLAMADAS;i++)
    {
        auxLlamada[i].idAmbulancia=i+1;
    }
    auxAsociado[0].estado=1;
    auxAsociado[0].edad=21;
    strncpy(auxAsociado[0].nombre,"Leon",50);
    strncpy(auxAsociado[0].apellido,"Vila",50);
    strncpy(auxAsociado[0].dni,"41236995",20);
    auxAsociado[1].estado=1;
    auxAsociado[1].edad=32;
    strncpy(auxAsociado[1].nombre,"Carlos",50);
    strncpy(auxAsociado[1].apellido,"Crack",50);
    strncpy(auxAsociado[1].dni,"40695327",20);
    auxAsociado[2].estado=1;
    auxAsociado[2].edad=27;
    strncpy(auxAsociado[2].nombre,"Estaban",50);
    strncpy(auxAsociado[2].apellido,"Quito",50);
    strncpy(auxAsociado[2].dni,"52392393",20);

    auxLlamada[0].estado=1;
    auxLlamada[0].tiempo=23;
    auxLlamada[0].idAsociado=0;
    auxLlamada[0].motivo=1;
    auxLlamada[1].estado=1;
    auxLlamada[1].tiempo=44;
    auxLlamada[1].idAsociado=5;
    auxLlamada[1].motivo=1;
    auxLlamada[2].estado=1;
    auxLlamada[2].tiempo=20;
    auxLlamada[2].idAsociado=0;
    auxLlamada[2].motivo=0;

    if(getInt("\n1-Alta de asociado\n2-Modificar datos del asociado\n3-Modificar estado del asociado\n"
              "4-Nueva llamada\n5-Asignar ambulancia\n6-Informes\n7-Salir\n","Error",1,7,2,&opcion)==0)
    {
        switch(opcion)
        {
            case 1:
            {
                aso_altaAsociado(auxAsociado,QTY_ASOCIADOS,&indiceAsociado);
                break;
            }
            case 2:
            {
                aso_modificar(auxAsociado,QTY_ASOCIADOS);
                break;
            }
            case 3:
            {
                aso_modificarEstado(auxAsociado,QTY_ASOCIADOS);
                break;
            }
            case 4:
            {
                aso_printAsociado(auxAsociado,QTY_ASOCIADOS);
                printf("\n0-Infarto\n1-ACV\n2-Gripe\n");
                lla_altaLlamada(auxLlamada,QTY_LLAMADAS,&indiceLlamada);
                //aso_printAsociado(auxAsociado,QTY_ASOCIADOS);
                break;
            }
            case 5:
            {
                lla_modificarLlamada(auxLlamada,QTY_LLAMADAS,&indiceLlamada);
                printf("\nID Ambulancia: %d",auxLlamada[indiceLlamada].idAmbulancia);
                printf("\nEstado cumplido");
                break;
            }
            case 6:
            {
                getInt("\n1-Asociado con mas llamados\n2-Motivos mas recurrentes\n","Error",1,2,2,&opcionInfo);
                if(opcionInfo==1)
                {
                    auxId=lla_asoMasLlamados(auxLlamada,auxAsociado,QTY_LLAMADAS,QTY_ASOCIADOS);
                    aso_printUnAsociado(auxAsociado,QTY_ASOCIADOS,auxId);
                    break;
                }
                else if(opcionInfo==2)
                {
                    printf("ENTRO2");
                }
                break;
            }
        }
        //aso_printAsociado(auxAsociado,QTY_ASOCIADOS);
    }
    return 0;
}


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"

#define CANTIDAD_PERSONAS 200

typedef struct{
    char nombre[50];
    char apellido[50];
    int legajo;
}Persona;

void inicializarArrayPersonas(Persona arrayPersonas[],int cantidadDeElementos,int valor);
int buscarPrimerOcurrencia(Persona arrayPersonas[],int cantidadDeElementos,int valor);

int main()
{
    Persona arrayPersonas[CANTIDAD_PERSONAS];
    Persona auxiliarCliente;

    char arrayNombres[50];
    char arrayApellidos[50];
    char arrayLegajostr[50];
    int arrayLegajos;

    int indiceLugarLibre;
    int indiceResultadoBusqueda;
    int opcion=0;

    int i;
    int j;

    inicializarArrayInt(arrayPersonas,CANTIDAD_PERSONAS,-1);
    while(opcion != 6)
    {
         getInt("\n\n\n1 - ALTA \n2 - BAJA \n3 - MODIFICACION\n4 - LISTAR\n5 - ORDENAR\n6 - SALIR\n\n\n","error",1,6,2,&opcion);
         switch(opcion)
         {
            case 1:

                indiceLugarLibre = buscarPrimerOcurrencia(arrayPersonas,QTY_PERSONAS,-1);
                if(indiceLugarLibre == -1)
                {
                    printf("\n\nNO QUEDAN LUGARES LIBRES!!!\n");
                    break;
                }

                printf("\nALTA\n");
                if (!getStringLetras("Ingrese el nombre: ",auxiliarNombreStr))
                {
                    printf ("El nombre debe estar compuesto solo por letras\n");
                    break;
                }

                if (!getStringLetras("Ingrese el apellido: ",auxiliarApellidoStr))
                {
                    printf ("El apellido debe estar compuesto solo por letras\n");
                    break;
                }

                if (!getStringNumeros("Ingrese el legajo: ",auxiliarLegajoStr))
                {
                    printf ("El legajo debe ser numerico\n");
                    break;
                }
                auxiliarLegajo = atoi(auxiliarLegajoStr);

                if(buscarPrimerOcurrencia(arrayPersonas,QTY_PERSONAS,auxiliarLegajo) != -1)
                {
                    printf("\n\nEL LEGAJO YA EXISTE!!!\n");
                    break;
                }


                strcpy(arrayPersonas[indiceLugarLibre].nombre,auxiliarNombreStr);
                strcpy(arrayPersonas[indiceLugarLibre].apellido,auxiliarApellidoStr);
                arrayPersonas[indiceLugarLibre].legajo = auxiliarLegajo;

                break;

            case 2:
                if (!getStringNumeros("Ingrese el legajo a dar de baja: ",auxiliarLegajoStr))
                {
                    printf ("El legajo debe ser numerico\n");
                    break;
                }
                indiceResultadoBusqueda = buscarPrimerOcurrencia(arrayPersonas,QTY_PERSONAS,atoi(auxiliarLegajoStr));

                if(indiceResultadoBusqueda == -1)
                {
                    printf("\n\nNO SE ENCUENTRA ESE LEGAJO\n");
                    break;
                }
                arrayPersonas[indiceResultadoBusqueda].legajo=-1;
                break;

            case 3:
                if (!getStringNumeros("Ingrese el legajo a modificar: ",auxiliarLegajoStr))
                {
                    printf ("El legajo debe ser numerico\n");
                    break;
                }

                indiceResultadoBusqueda = buscarPrimerOcurrencia(arrayPersonas,QTY_PERSONAS,atoi(auxiliarLegajoStr));

                if(indiceResultadoBusqueda == -1)
                {
                    printf("\n\nNO SE ENCUENTRA ESE LEGAJO\n");
                    break;
                }

                if (!getStringLetras("Ingrese el nombre: ",auxiliarNombreStr))
                {
                    printf ("El nombre debe estar compuesto solo por letras\n");
                    break;
                }

                if (!getStringLetras("Ingrese el apellido: ",auxiliarApellidoStr))
                {
                    printf ("El apellido debe estar compuesto solo por letras\n");
                    break;
                }

                strcpy(arrayPersonas[indiceResultadoBusqueda].nombre,auxiliarNombreStr);
                strcpy(arrayPersonas[indiceResultadoBusqueda].apellido,auxiliarApellidoStr);

                break;

            case 4:
                printf("\nLISTAR\n");
                for(i=0;i < QTY_PERSONAS; i++)
                {
                    if(arrayPersonas[i].legajo != -1)
                    {
                        printf("\n%s - %s - %d",arrayPersonas[i].nombre,arrayPersonas[i].apellido,arrayPersonas[i].legajo);
                    }
                }
                break;

            case 5:
                printf("\nORDENADO\n");

                for(i=0; i < QTY_PERSONAS - 1; i++)
                {
                    if(arrayPersonas[i].legajo == -1)
                    {
                        continue;
                    }
                    for(j=i+1; j < QTY_PERSONAS; j++)
                    {
                        if(arrayPersonas[j].legajo == -1)
                        {
                            continue;
                        }
                        if(strcmp(arrayPersonas[i].apellido,arrayPersonas[j].apellido) > 0)
                        {
                            auxiliarCliente = arrayPersonas[j];
                            arrayPersonas[j] = arrayPersonas[i];
                            arrayPersonas[i] = auxiliarCliente;
                        }
                    }
                }
                break;
         }
    }


    return 0;
}




/**
 * \brief Inicializa un array de enteros con el valor recibido
 * \param array Es el array a ser inicializado
 * \param cantidad_de_elementos Indica la logitud del array
 * \param valor Es el valor que sera cargado en cada posicion
 * \return -
 *
 */
void inicializarArrayInt(Persona arrayPersonas[],int cantidadDeElementos,int valor)
{
    int i;
    for(i=0;i < cantidadDeElementos; i++)
    {
        arrayPersonas[i].legajo = valor;
    }
}
/**
 * \brief Busca la primer ocurrencia de un valor en un array de enteros
 * \param array Es el array en el cual buscar
 * \param cantidad_de_elementos Indica la logitud del array
 * \param valor Es el valor que se busca
 * \return Si no hay ocurrencia (-1) y si la hay la posicion de la misma (i)
 *
 */
int buscarPrimerOcurrencia(Persona arrayPersonas[],int cantidadDeElementos,int valor)
{
    int i;
    for(i=0;i < cantidadDeElementos; i++)
    {
        if(arrayPersonas[i].legajo == valor)
        {
            return i;
        }
    }
    return -1;
}

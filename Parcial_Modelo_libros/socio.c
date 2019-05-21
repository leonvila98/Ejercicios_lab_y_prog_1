#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "socio.h"


/** \brief  To indicate that all position in the array are empty,
*          this function put the flag (isEmpty) in TRUE in all
*          position of the array
* \param array socio Array of socio
* \param size int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int socio_Inicializar(Socio array[], int size)                                    //cambiar socio
{
    int retorno=-1;
    if(array!= NULL && size>0)
    {
        for(;size>0;size--)
        {
            array[size-1].isEmpty=1;
        }
        retorno=0;
    }
    return retorno;
}

//*****************************************
//Buscar
//Int
/** \brief Busca el primer lugar vacio en un array
* \param array socio Array de socio
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra un lugar vacio o Error [Invalid length or NULL pointer] - (0) si encuentra una posicion vacia
*
*/
int socio_buscarEmpty(Socio array[], int size, int* posicion)                    //cambiar socio
{
    int retorno=-1;
    int i;
    if(array!= NULL && size>=0 && posicion!=NULL)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
            {
                retorno=0;
                *posicion=i;
                break;
            }
        }
    }
    return retorno;
}

/** \brief Busca un ID en un array y devuelve la posicion en que se encuentra
* \param array socio Array de socio
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int socio_buscarID(Socio array[], int size, int valorBuscado, int* posicion)
{
    int retorno=-1;
    int i;
    if(array!= NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==0)
            {
                if(array[i].idUnico==valorBuscado)
                {
                    retorno=0;
                    *posicion=i;
                    break;
                }
            }
        }
    }
    return retorno;
}
/** \brief Busca un int en un array y devuelve la posicion en que se encuentra
* \param array socio Array de socio
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
/*int socio_buscarInt(Socio array[], int size, int valorBuscado, int* posicion)                    //cambiar socio
{
    int retorno=-1;
    int i;
    if(array!= NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else if(array[i].varInt==valorBuscado)                                                   //cambiar campo varInt
            {
                retorno=0;
                *posicion=i;
                break;
            }
        }
    }
    return retorno;
}
*/
//String
/** \brief Busca un string en un array
* \param array socio Array de socio
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int socio_buscarString(Socio array[], int size, char* valorBuscado, int* indice)                    //cambiar socio
{
    int retorno=-1;
    int i;
    if(array!=NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else if(strcmp(array[i].nombre,valorBuscado)==0)                                        //cambiar campo nombre
            {
                *indice=i;
                retorno=0;
                break;
            }
        }
    }
    return retorno;
}

//*****************************************
//Alta
/** \brief Solicita los datos para completar la primer posicion vacia de un array
* \param array socio Array de socio
* \param size int Tamaño del array
* \param contadorID int* Puntero al ID unico que se va a asignar al nuevo elemento
* \return int Return (-1) si Error [largo no valido o NULL pointer o no hay posiciones vacias] - (0) si se agrega un nuevo elemento exitosamente
*
*/
int socio_alta(Socio array[], int size)
{
    int retorno=-1;
    int posicion;
    if(array!=NULL && size>0 )
    {
        if(socio_buscarEmpty(array,size,&posicion)==-1)
        {
            printf("\nNo hay lugares vacios");
        }
        else
        {
            array[posicion].isEmpty=0;
            utn_getName("\nNombre: ","\nError",1,TEXT_SIZE,1,array[posicion].nombre);
            utn_getTexto("\nApellido: ","\nError",1,TEXT_SIZE,1,array[posicion].apellido);
            printf("\n Posicion: %d\n ID: %d\n nombre: %s\n apellido: %s",
                   posicion, array[posicion].idUnico,array[posicion].nombre,array[posicion].apellido);
            retorno=0;
        }
    }
    return retorno;
}

//*****************************************
//Baja valor unico
/** \brief Borra un elemento del array por ID
* \param array socio Array de socio
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se elimina el elemento exitosamente
*
*/
int socio_baja(Socio array[], int sizeArray)                                      //cambiar socio
{
    int retorno=-1;
    int posicion;
    int id;
    if(array!=NULL && sizeArray>0)
    {
        utn_getInt("\nID a cancelar: ","\nError",1,sizeArray+1,1,&id);          //cambiar si no se busca por ID
        if(socio_buscarID(array,sizeArray,id,&posicion)==-1)                                   //cambiar si no se busca por ID
        {
            printf("\nNo existe este ID");                                                          //cambiar si no se busca por ID
        }
        else
        {
            array[posicion].isEmpty=1;
            array[posicion].idUnico=0;                                                                   //cambiar campo id                                                             //cambiar campo varFloat
            strcpy(array[posicion].nombre,"");                                                   //cambiar campo nombre
            strcpy(array[posicion].apellido,"");                                               //cambiar campo apellido
            retorno=0;
        }
    }
    return retorno;
}

//Baja valor repetido
/** \brief Borra todos los elemento del array que contengan el valor buscado
* \param array socio Array de socio
* \param size int Tamaño del array
* \param valorBuscado int Valor a buscar en el array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se elimina el elemento exitosamente
*
*/
int socio_bajaValorRepetidoInt(Socio array[], int sizeArray, int valorBuscado) //cuando hay que dar de baja todas las posiciones en las que se encuentra ese int
{
    int retorno=-1;
    int i;
    if(array!=NULL && sizeArray>0)
    {
        for(i=0;i<sizeArray;i++)
        {
            if(array[i].idUnico==valorBuscado)                                                        //cambiar si no se busca por ID
            {
                array[i].isEmpty=1;
                array[i].idUnico=0;                                                                   //cambiar campo id                                                         //cambiar campo varFloat
                strcpy(array[i].nombre,"");                                                   //cambiar campo nombre
                strcpy(array[i].apellido,"");                                               //cambiar campo apellido
            }
        }
        retorno=0;
    }
    return retorno;
}



//*****************************************
//Modificar
/** \brief Busca un elemento por ID y modifica sus campos
* \param array socio Array de socio
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se modifica el elemento exitosamente
*
*/
int socio_modificar(Socio array[], int sizeArray)                                //cambiar socio
{
    int retorno=-1;
    int posicion;
    int id;                                                                                         //cambiar si no se busca por ID
    int opcion;
    int opcionSexo;
    if(array!=NULL && sizeArray>0)
    {
        utn_getInt("\nID a modificar: ","\nError",1,sizeArray+1,1,&id);         //cambiar si no se busca por ID
        if(socio_buscarID(array,sizeArray,id,&posicion)==-1)                                   //cambiar si no se busca por ID
        {
            printf("\nNo existe este ID");                                                          //cambiar si no se busca por ID
        }
        else
        {
            do
            {
                printf("\n Posicion: %d\n ID: %d\n nombre: %s\n apellido: %s",
						posicion, array[posicion].idUnico,array[posicion].nombre,array[posicion].apellido);
                utn_getInt("\nModificar:\n1-Nombre\n2-Apellido\n3-Sexo\n4-Telefono\n5-Email","\nError",1,6,2,&opcion);
                switch(opcion)
                {
                    case 1:
					{
						utn_getName("\nNuevo nombre: ","\nError",1,TEXT_SIZE,1,array[posicion].nombre);
					}
					break;
                    case 2:
                    {
						utn_getName("\nNuevo apellido: ","\nError",1,TEXT_SIZE,1,array[posicion].apellido);
                    }
					break;
                    case 3:
                    {
						utn_getInt("\nNuevo sexo: \n1-Femenino\n2-Masculino","Error",1,2,2,&opcionSexo);
                    }
					break;
                    case 4:
                        utn_getTexto("\n: ","\nError",1,TEXT_SIZE,1,array[posicion].apellido);             //mensaje + cambiar campo apellido
                        break;
                    case 5:
                        break;
                    default:
                        printf("\nOpcion no valida");
                }
            }while(opcion!='S');
            retorno=0;
        }
    }
    return retorno;
}

//*****************************************
//Ordenar
/** \brief Ordena por campo XXXXX los elementos de un array ante la igualdad de estos ordena por el campo ZZZZZZ
* \param array socio Array de socio
* \param size int Tamaño del array
* \param orderFirst int Determina si el orden del primer criterio es ascendete o descendente
* \param orderSecond int Determina si el orden del segunbdo criterio es ascendete o descendente
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer] - (0) si se ordena exitosamente
*
*/
int socio_ordenarPorDobleCriterio(Socio array[],int size, int orderFirst, int orderSecond)                              //cambiar socio
{
    int retorno=-1;
    int i;
    Socio buffer;
    int flagSwap;

    if(array!=NULL && size>=0)
    {
        do
        {
            flagSwap=0;
            for (i = 1; i < size-1; i++)
            {
                if( ((strcmp(array[i].nombre,array[i+1].nombre) < 0) && orderFirst) ||
                    ((strcmp(array[i].nombre,array[i+1].nombre) > 0) && !orderFirst) )
                {
                    flagSwap=1;
                    buffer = array[i];
                    array[i] = array[i+1];
                    array[i+1] = buffer;
                }
                /*else if(strcmp(array[i].nombre,array[i+1].nombre) == 0)
                {
                    if( ((array[i].varFloat < array[i+1].varFloat) && orderSecond) ||
                        ((array[i].varFloat > array[i+1].varFloat) && !orderSecond) )
                    {
                        flagSwap=1;
                        buffer = array[i];
                        array[i] = array[i+1];
                        array[i+1] = buffer;
                    }
                }*/
            }
        }while(flagSwap);
        retorno=0;
    }
    return retorno;
}

//*****************************************
//Listar
/** \brief Lista los elementos de un array
* \param array socio Array de socio
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer] - (0) si se lista exitosamente
*
*/
int socio_listar(Socio array[], int size)                      //cambiar socio
{
    int retorno=-1;
    int i;
    if(array!=NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else
                printf("\n Posicion: %d\n ID: %d\n nombre: %s\n apellido: %s\n",
                   i, array[i].idUnico,array[i].nombre,array[i].apellido);
        }
        retorno=0;
    }
    return retorno;
}
int socio_printPorId(Socio array[], int size, int id)
{
    int retorno=-1;
    int i;
    if(array!= NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==0)
            {
                if(array[i].idUnico==id)
                {
                    retorno=0;
                    printf("\n Posicion: %d\n ID: %d\n nombre: %s\n apellido: %s\n",
                    i, array[i].idUnico,array[i].nombre,array[i].apellido);
                    break;
                }
            }
        }
    }
    return retorno;
}


void socio_mock(Socio arraySocio[], int size)                      //cambiar socio
{
    //*******************************************************************
    arraySocio[0].idUnico=0;
    arraySocio[0].isEmpty=0;
    strcpy(arraySocio[0].apellido,"Armani");
    strcpy(arraySocio[0].nombre,"Giorgio");
    arraySocio[1].idUnico=1;
    arraySocio[1].isEmpty=0;
    strcpy(arraySocio[1].apellido,"Vila");
    strcpy(arraySocio[1].nombre,"Leon");
    arraySocio[2].idUnico=2;
    arraySocio[2].isEmpty=0;
    strcpy(arraySocio[2].apellido,"Suarez");
    strcpy(arraySocio[2].nombre,"Matias");
    arraySocio[3].idUnico=3;
    arraySocio[3].isEmpty=0;
    strcpy(arraySocio[3].apellido,"Ponzio");
    strcpy(arraySocio[3].nombre,"Leo");
}


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Venta.h"
#include "utn.h"

/** \brief Crea un espacio de memoria con espacio para un Venta.
 *
 * \param void
 * \return Venta* Puntero a la primera posicion del espacio de memoria creado.
 *
 */
Venta* venta_new(void)
{
	return (Venta*) malloc(sizeof(Venta));
}

/** \brief Crea un espacio de memoria con espacio para un Venta y lo crea mediante
 *         los parametros pasados.
 *
 * \param char* id (del Venta a crear).
 * \param char* nombre (del Venta a crear).
 * \param char* numeroInt trabajadas (del Venta a crear).
 * \param char* numeroIntDos (del Venta a crear).
 * \return Venta* Puntero a la primera posicion del espacio de memoria creado.
 *
 */
Venta* venta_newParametros(char* idStr,char* idClienteStr,char* codigoProductoStr,char* cantidadStr,char* precioUnidad)
{
	Venta* retorno=NULL;
	Venta* pAuxVenta;

	if(idStr!=NULL &&
	   idClienteStr!=NULL &&
	   codigoProductoStr!=NULL &&
	   cantidadStr!=NULL &&
	   precioUnidad!=NULL)
	{
		pAuxVenta=venta_new();
		if(pAuxVenta!=NULL)
		{
			if(	!venta_setIdStr(pAuxVenta,idStr) &&
				!venta_setIdClienteStr(pAuxVenta,idClienteStr) &&
				!venta_setCodigoProducto(pAuxVenta,codigoProductoStr) &&
				!venta_setCantidadStr(pAuxVenta,cantidadStr) &&
                !venta_setPrecioUnidadStr(pAuxVenta,precioUnidad))
			{
				retorno=pAuxVenta;
			}
			else
			{
				venta_delete(pAuxVenta);
			}
		}
	}
	return retorno;
}

/** \brief Crea un espacio de memoria con espacio para un Venta, lo crea
 *         mediante la estructrura pasada y lo guarda en una LinkedList.
 *
 * \param LinkedList* lista (LinkedList a guardar el Venta creado).
 * \param Venta cli (Venta a guardar en la LinkedList).
 * \return Int retorno (0-Pudo crear y guardar el Venta)((-1)-No pudo crear o guardar el Venta).
 *
 */
/*int venta_newByStruct(LinkedList* lista,Venta cli)
{
    Venta* pCli;
    int retorno=-1;

    pCli=venta_new();
    if(	!venta_setNombre(pCli,cli.nombre)&&
        !venta_setId(pCli,cli.id)&&
        !venta_setApellido(pCli,cli.apellido)&&
        !venta_setDni(pCli,cli.dni))
    {
        ll_add(lista,pCli);
        retorno=0;
    }
    else
    {
        venta_delete(pCli);
    }
    return retorno;
}*/

/** \brief Libera el espacio en memoria ocupado por un Venta(Delete).
 *
 * \param void
 * \return Venta* Puntero a la primera posicion del espacio de memoria creado.
 *
 */
void venta_delete(Venta* this)
{
    if(this != NULL)
    {
        free(this);
    }
}

/** \brief Set del id en un Venta.
 *
 * \param Venta* Puntero del Venta
 * \param int id del Venta
 * \return int retorno (0-Pudo hacer el set)((-1)-No pudo hacer el set).
 *
 */
int venta_setId(Venta* this,int id)
{
	int retorno = -1;
    if(this != NULL && isValidInt(id,10000,0))
    {
        this->id = id;
        retorno = 0;
    }
    return retorno;
}

/** \brief Obtiene el id de un Venta.
 *
 * \param Venta* Puntero del Venta
 * \param int* id del Venta
 * \return int retorno (0-Pudo obtener)((-1)-No pudo obtener).
 *
 */
int venta_getId(Venta* this,int* id)
{
	int retorno = -1;
    if(this != NULL && id != NULL)
    {
        *id = this->id;
        retorno = 0;
    }
    return retorno;
}
/** \brief Set del precioUnidad en un Venta.
 *
 * \param Venta* Puntero del Venta
 * \param float precioUnidad del Venta
 * \return int retorno (0-Pudo hacer el set)((-1)-No pudo hacer el set).
 *
 */
int venta_setPrecioUnidad(Venta* this,float precioUnidad)
{
	int retorno = -1;
    if( this != NULL)
    {
        this->precioUnidad = precioUnidad;
        retorno = 0;
    }
    return retorno;
}

/** \brief Obtiene el precioUnidad de un Venta.
 *
 * \param Venta* Puntero del Venta
 * \param int* precioUnidad del Venta
 * \return int retorno (0-Pudo obtener)((-1)-No pudo obtener).
 *
 */
int venta_getPrecioUnidad(Venta* this,float* precioUnidad)
{
	int retorno = -1;
    if(this != NULL && precioUnidad != NULL)
    {
        *precioUnidad = this->precioUnidad;
        retorno = 0;
    }
    return retorno;
}
/** \brief Set del idCliente en un Venta.
 *
 * \param Venta* Puntero del Venta
 * \param int idCliente del Venta
 * \return int retorno (0-Pudo hacer el set)((-1)-No pudo hacer el set).
 *
 */
int venta_setIdCliente(Venta* this,int idCliente)
{
	int retorno = -1;
    if(this != NULL && isValidInt(idCliente,10000,0))
    {
        this->idCliente = idCliente;
        retorno = 0;
    }
    return retorno;
}

/** \brief Obtiene el idCliente de un Venta.
 *
 * \param Venta* Puntero del Venta
 * \param int* idCliente del Venta
 * \return int retorno (0-Pudo obtener)((-1)-No pudo obtener).
 *
 */
int venta_getIdCliente(Venta* this,int* idCliente)
{
	int retorno = -1;
    if(this != NULL && idCliente != NULL)
    {
        *idCliente = this->idCliente;
        retorno = 0;
    }
    return retorno;
}
/** \brief Set del codigoProducto en un Venta.
 *
 * \param Venta* Puntero del Venta
 * \param char* codigoProducto del Venta
 * \return int retorno (0-Pudo hacer el set)((-1)-No pudo hacer el set).
 *
 */
int venta_setCodigoProducto(Venta* this,char* codigoProducto)
{
    int retorno = -1;
    if(this != NULL &&
       (strcmp(codigoProducto,"1000")==0 ||
        strcmp(codigoProducto,"1001")==0 ||
        strcmp(codigoProducto,"1002")==0))
    {
        strncpy(this->codigoProducto,codigoProducto,sizeof(this->codigoProducto));
        retorno = 0;
    }
    return retorno;
}
/** \brief Obtiene el codigo de producto de un Venta.
 *
 * \param Venta* Puntero del Venta
 * \param char* codigoProducto del Venta
 * \return int retorno (0-Pudo obtener)((-1)-No pudo obtener).
 *
 */
int venta_getCodigoProducto(Venta* this,char* codigoProducto)
{
    int retorno = -1;
    if(this != NULL && codigoProducto != NULL)
    {
        strncpy(codigoProducto,this->codigoProducto,sizeof(this->codigoProducto));
        retorno = 0;
    }
    return retorno;
}
/** \brief Set del cantidad en un Venta.
 *
 * \param Venta* Puntero del Venta
 * \param int cantidad del Venta
 * \return int retorno (0-Pudo hacer el set)((-1)-No pudo hacer el set).
 *
 */
int venta_setCantidad(Venta* this,int cantidad)
{
	int retorno = -1;
    if(this != NULL && isValidInt(cantidad,10000,0))
    {
        this->cantidad = cantidad;
        retorno = 0;
    }
    return retorno;
}

/** \brief Obtiene el cantidad de un Venta.
 *
 * \param Venta* Puntero del Venta
 * \param int* cantidad del Venta
 * \return int retorno (0-Pudo obtener)((-1)-No pudo obtener).
 *
 */
int venta_getCantidad(Venta* this,int* cantidad)
{
	int retorno = -1;
    if(this != NULL && cantidad != NULL)
    {
        *cantidad = this->cantidad;
        retorno = 0;
    }
    return retorno;
}

/** \brief Set del id en string en un Venta.
 *
 * \param Venta* Puntero del Venta
 * \param char* id del Venta
 * \return int retorno (0-Pudo hacer el set)((-1)-No pudo hacer el set).
 *
 */
int venta_setIdStr(Venta* this, char* id)
{
    int retorno = -1;
    if(this != NULL)
    {
        retorno = venta_setId(this,atoi(id));
    }
    return retorno;
}

/** \brief Obtiene el id en string de un Venta.
 *
 * \param Venta* Puntero del Venta
 * \param char* id del Venta
 * \return int retorno (0-Pudo obtener)((-1)-No pudo obtener).
 *
 */
int venta_getIdStr(Venta* this, char* id)
{
    int retorno = -1;
    int bufferInt;
    if(this != NULL && id != NULL)
    {
        venta_getId(this,&bufferInt);
        sprintf(id,"%d",bufferInt);
        retorno = 0;
    }
    return retorno;
}
/** \brief Set del precioUnidad en string en un Venta.
 *
 * \param Venta* Puntero del Venta
 * \param char* precioUnidad del Venta
 * \return int retorno (0-Pudo hacer el set)((-1)-No pudo hacer el set).
 *
 */
int venta_setPrecioUnidadStr(Venta* this, char* precioUnidad)
{
    int retorno = -1;
    if(this != NULL)
    {
        retorno = venta_setPrecioUnidad(this,atof(precioUnidad));
    }
    return retorno;
}

/** \brief Obtiene el precioUnidad en string de un Venta.
 *
 * \param Venta* Puntero del Venta
 * \param char* precioUnidad del Venta
 * \return int retorno (0-Pudo obtener)((-1)-No pudo obtener).
 *
 */
int venta_getPrecioUnidadStr(Venta* this, char* precioUnidad)
{
    int retorno = -1;
    float bufferFloat;
    if(this != NULL && precioUnidad != NULL)
    {
        venta_getPrecioUnidad(this,&bufferFloat);
        sprintf(precioUnidad,"%.2f",bufferFloat);
        retorno = 0;
    }
    return retorno;
}

/** \brief Set del idCliente en string en un Venta.
 *
 * \param Venta* Puntero del Venta
 * \param char* idCliente del Venta
 * \return int retorno (0-Pudo hacer el set)((-1)-No pudo hacer el set).
 *
 */
int venta_setIdClienteStr(Venta* this, char* idCliente)
{
    int retorno = -1;
    if(this != NULL)
    {
        retorno = venta_setIdCliente(this,atoi(idCliente));
    }
    return retorno;
}

/** \brief Obtiene el idCliente en string de un Venta.
 *
 * \param Venta* Puntero del Venta
 * \param char* idCliente del Venta
 * \return int retorno (0-Pudo obtener)((-1)-No pudo obtener).
 *
 */
int venta_getIdClienteStr(Venta* this, char* idCliente)
{
    int retorno = -1;
    int bufferInt;
    if(this != NULL && idCliente != NULL)
    {
        venta_getId(this,&bufferInt);
        sprintf(idCliente,"%d",bufferInt);
        retorno = 0;
    }
    return retorno;
}
/** \brief Set del cantidad en string en un Venta.
 *
 * \param Venta* Puntero del Venta
 * \param char* cantidad del Venta
 * \return int retorno (0-Pudo hacer el set)((-1)-No pudo hacer el set).
 *
 */
int venta_setCantidadStr(Venta* this, char* cantidad)
{
    int retorno = -1;
    if(this != NULL)
    {
        retorno = venta_setCantidad(this,atoi(cantidad));
    }
    return retorno;
}

/** \brief Obtiene el cantidad en string de un Venta.
 *
 * \param Venta* Puntero del Venta
 * \param char* cantidad del Venta
 * \return int retorno (0-Pudo obtener)((-1)-No pudo obtener).
 *
 */
int venta_getCantidadStr(Venta* this, char* cantidad)
{
    int retorno = -1;
    int bufferInt;
    if(this != NULL && cantidad != NULL)
    {
        venta_getCantidad(this,&bufferInt);
        sprintf(cantidad,"%d",bufferInt);
        retorno = 0;
    }
    return retorno;
}
/** \brief Obtiene el id maximo de un Venta en una LinkedList.
 *
 * \param LinkedList* pArray .
 * \return int max retorna el id mas grande.
 *
 */
int venta_getIdMax(LinkedList* pArray)
{
	int i;
	int id;
	int max;
	int flag=0;
	Venta* pAux;
	if(pArray!=NULL)
	{
		for(i=0;i<ll_len(pArray);i++)
		{
			pAux=ll_get(pArray,i);
			venta_getId(pAux,&id);
			if(flag==0 || id>max)
			{
				max=id;
				flag=1;
			}
		}
	}
	return max;
}

/** \brief Obtiene el indice de un Venta mediante su id.
 *
 * \param LinkedList* pArray.
 * \param int id del Venta
 * \param int* indice del Venta buscado.
 * \return int retorno (0-Si lo encontro)((-1)-No lo encontro).
 *
 */
int venta_getVenById(LinkedList* pArray,int id,int* indice)
{
	int i;
	Venta* pAuxCli;
	int bufferId;
	int retorno=-1;

	if(pArray!=NULL)
	{
		for(i=0;i<ll_len(pArray);i++)
		{
			pAuxCli=ll_get(pArray,i);
			if(!venta_getId(pAuxCli,&bufferId))
            {
                if(id==bufferId)
                {
                    *indice=i;
                    retorno=0;
                    break;
                }
            }
		}
	}
	return retorno;
}

/** \brief Obtiene el indice de un Venta mediante su id.
 *
 * \param LinkedList* pArray.
 * \param int id del Venta
 * \param int* indice del Venta buscado.
 * \return int retorno (0-Si lo encontro)((-1)-No lo encontro).
 *
 */
int venta_getCliById(LinkedList* pArray,int idCliente)
{
	int i;
	Venta* pAuxCli;
	int bufferIdCliente;
	int retorno=-1;

	if(pArray!=NULL)
	{
		for(i=0;i<ll_len(pArray);i++)
		{
			pAuxCli=ll_get(pArray,i);
			if(!venta_getIdCliente(pAuxCli,&bufferIdCliente))
            {
                if(idCliente==bufferIdCliente)
                {
                    retorno=0;
                    break;
                }
            }
		}
	}
	return retorno;
}
/** \brief Compara por nombre dos Venta.
 *
 * \param void* this1.
 * \param void* this2.
 * \return int retorno (0-Si son iguales)(1-si this1 es mas grande que this2)
 *                      ((-1)-si this1 es mas chico que this2).
 *
 */
/*int venta_compararPorNombre(void* this1,void* this2)//recibe dos void
{
	char bufferA[4096];
	char bufferB[4096];

	venta_getNombre((Venta*)this1,bufferA);
	venta_getNombre((Venta*)this2,bufferB);
	if(strcmp(bufferA,bufferB)>0)
		return 1;
	else if(strcmp(bufferA,bufferB)<0)
		return -1;
	return 0;
}*/

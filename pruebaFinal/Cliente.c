#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Cliente.h"
#include "utn.h"

/** \brief Crea un espacio de memoria con espacio para un Cliente.
 *
 * \param void
 * \return Cliente* Puntero a la primera posicion del espacio de memoria creado.
 *
 */
Cliente* cliente_new(void)
{
	return (Cliente*) malloc(sizeof(Cliente));
}

/** \brief Crea un espacio de memoria con espacio para un Cliente y lo crea mediante
 *         los parametros pasados.
 *
 * \param char* id (del Cliente a crear).
 * \param char* nombre (del Cliente a crear).
 * \param char* numeroInt trabajadas (del Cliente a crear).
 * \param char* numeroIntDos (del Cliente a crear).
 * \return Cliente* Puntero a la primera posicion del espacio de memoria creado.
 *
 */
Cliente* cliente_newParametros(char* idStr,char* nombreStr,char* apellidoStr,char* dniStr)
{
	Cliente* retorno=NULL;
	Cliente* pAuxCliente;

	if(idStr!=NULL &&
	   nombreStr!=NULL &&
	   apellidoStr!=NULL &&
	   dniStr!=NULL)
	{
		pAuxCliente=cliente_new();
		if(pAuxCliente!=NULL)
		{
			if(	!cliente_setIdStr(pAuxCliente,idStr) &&
				!cliente_setNombre(pAuxCliente,nombreStr) &&
				!cliente_setApellido(pAuxCliente,apellidoStr) &&
				!cliente_setDni(pAuxCliente,dniStr))
			{
				retorno=pAuxCliente;
			}
			else
			{
				cliente_delete(pAuxCliente);
			}
		}
	}
	return retorno;
}

/** \brief Crea un espacio de memoria con espacio para un Cliente, lo crea
 *         mediante la estructrura pasada y lo guarda en una LinkedList.
 *
 * \param LinkedList* lista (LinkedList a guardar el Cliente creado).
 * \param Cliente cli (Cliente a guardar en la LinkedList).
 * \return Int retorno (0-Pudo crear y guardar el Cliente)((-1)-No pudo crear o guardar el Cliente).
 *
 */
int cliente_newByStruct(LinkedList* lista,Cliente cli)
{
    Cliente* pCli;
    int retorno=-1;

    pCli=cliente_new();
    if(	!cliente_setNombre(pCli,cli.nombre)&&
        !cliente_setId(pCli,cli.id)&&
        !cliente_setApellido(pCli,cli.apellido)&&
        !cliente_setDni(pCli,cli.dni))
    {
        ll_add(lista,pCli);
        retorno=0;
    }
    else
    {
        cliente_delete(pCli);
    }
    return retorno;
}

/** \brief Libera el espacio en memoria ocupado por un Cliente(Delete).
 *
 * \param void
 * \return Cliente* Puntero a la primera posicion del espacio de memoria creado.
 *
 */
void cliente_delete(Cliente* this)
{
    if(this != NULL)
    {
        free(this);
    }
}

/** \brief Set del id en un Cliente.
 *
 * \param Cliente* Puntero del Cliente
 * \param int id del Cliente
 * \return int retorno (0-Pudo hacer el set)((-1)-No pudo hacer el set).
 *
 */
int cliente_setId(Cliente* this,int id)
{
	int retorno = -1;
    if(this != NULL && isValidInt(id,10000,0))
    {
        this->id = id;
        retorno = 0;
    }
    return retorno;
}

/** \brief Obtiene el id de un Cliente.
 *
 * \param Cliente* Puntero del Cliente
 * \param int* id del Cliente
 * \return int retorno (0-Pudo obtener)((-1)-No pudo obtener).
 *
 */
int cliente_getId(Cliente* this,int* id)
{
	int retorno = -1;
    if(this != NULL && id != NULL)
    {
        *id = this->id;
        retorno = 0;
    }
    return retorno;
}

/** \brief Set del nombre en un Cliente.
 *
 * \param Cliente* Puntero del Cliente
 * \param char* nombre del Cliente
 * \return int retorno (0-Pudo hacer el set)((-1)-No pudo hacer el set).
 *
 */
int cliente_setNombre(Cliente* this,char* nombre)
{
	int retorno = -1;
    if(this != NULL && !isValidName(nombre))
    {
        strncpy(this->nombre,nombre,sizeof(this->nombre));
        retorno = 0;
    }
    return retorno;
}

/** \brief Obtiene el nombre de un Cliente.
 *
 * \param Cliente* Puntero del Cliente
 * \param char* nombre del Cliente
 * \return int retorno (0-Pudo obtener)((-1)-No pudo obtener).
 *
 */
int cliente_getNombre(Cliente* this,char* nombre)
{
	int retorno = -1;
    if(this != NULL && nombre != NULL)
    {
        strncpy(nombre,this->nombre,sizeof(this->nombre));
        retorno = 0;
    }
    return retorno;
}
/** \brief Set del apellido en un Cliente.
 *
 * \param Cliente* Puntero del Cliente
 * \param char* apellido del Cliente
 * \return int retorno (0-Pudo hacer el set)((-1)-No pudo hacer el set).
 *
 */
int cliente_setApellido(Cliente* this,char* apellido)
{
    int retorno = -1;
    if(this != NULL && !isValidName(apellido))
    {
        strncpy(this->apellido,apellido,sizeof(this->apellido));
        retorno = 0;
    }
    return retorno;
}
/** \brief Obtiene el apeliido de un Cliente.
 *
 * \param Cliente* Puntero del Cliente
 * \param char* apellido del Cliente
 * \return int retorno (0-Pudo obtener)((-1)-No pudo obtener).
 *
 */
int cliente_getApellido(Cliente* this,char* apellido)
{
    int retorno = -1;
    if(this != NULL && apellido != NULL)
    {
        strncpy(apellido,this->apellido,sizeof(this->apellido));
        retorno = 0;
    }
    return retorno;
}
/** \brief Set del dni en un Cliente.
 *
 * \param Cliente* Puntero del Cliente
 * \param char* dni del Cliente
 * \return int retorno (0-Pudo hacer el set)((-1)-No pudo hacer el set).
 *
 */
int cliente_setDni(Cliente* this,char* dni)
{
	int retorno = -1;
    if(this != NULL && !isValidDNI(dni))
    {
        strncpy(this->dni,dni,sizeof(this->dni));
        retorno = 0;
    }
    return retorno;
}
/** \brief Obtiene el dni de un Cliente.
 *
 * \param Cliente* Puntero del Cliente
 * \param char* dni del Cliente
 * \return int retorno (0-Pudo obtener)((-1)-No pudo obtener).
 *
 */
int cliente_getDni(Cliente* this,char* dni)
{
    int retorno = -1;
    if(this != NULL && dni != NULL)
    {
        strncpy(dni,this->dni,sizeof(this->dni));
        retorno = 0;
    }
    return retorno;
}

/** \brief Set del id en string en un Cliente.
 *
 * \param Cliente* Puntero del Cliente
 * \param char* id del Cliente
 * \return int retorno (0-Pudo hacer el set)((-1)-No pudo hacer el set).
 *
 */
int cliente_setIdStr(Cliente* this, char* id)
{
    int retorno = -1;
    if(this != NULL)
    {
        retorno = cliente_setId(this,atoi(id));
    }
    return retorno;
}

/** \brief Obtiene el id en string de un Cliente.
 *
 * \param Cliente* Puntero del Cliente
 * \param char* id del Cliente
 * \return int retorno (0-Pudo obtener)((-1)-No pudo obtener).
 *
 */
int cliente_getIdStr(Cliente* this, char* id)
{
    int retorno = -1;
    int bufferInt;
    if(this != NULL && id != NULL)
    {
        cliente_getId(this,&bufferInt);
        sprintf(id,"%d",bufferInt);
        retorno = 0;
    }
    return retorno;
}

/** \brief Obtiene el id maximo de un Cliente en una LinkedList.
 *
 * \param LinkedList* pArray .
 * \return int max retorna el id mas grande.
 *
 */
int cliente_getIdMax(LinkedList* pArray)
{
	int i;
	int id;
	int max;
	int flag=0;
	Cliente* pAux;
	if(pArray!=NULL)
	{
		for(i=0;i<ll_len(pArray);i++)
		{
			pAux=ll_get(pArray,i);
			cliente_getId(pAux,&id);
			if(flag==0 || id>max)
			{
				max=id;
				flag=1;
			}
		}
	}
	return max;
}

/** \brief Obtiene el indice de un Cliente mediante su id.
 *
 * \param LinkedList* pArray.
 * \param int id del Cliente
 * \param int* indice del Cliente buscado.
 * \return int retorno (0-Si lo encontro)((-1)-No lo encontro).
 *
 */
int cliente_getCliById(LinkedList* pArray,int id,int* indice)
{
	int i;
	Cliente* pAuxCli;
	int bufferId;
	int retorno=-1;

	if(pArray!=NULL)
	{
		for(i=0;i<ll_len(pArray);i++)
		{
			pAuxCli=ll_get(pArray,i);
			if(!cliente_getId(pAuxCli,&bufferId))
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

/** \brief Compara por nombre dos Cliente.
 *
 * \param void* this1.
 * \param void* this2.
 * \return int retorno (0-Si son iguales)(1-si this1 es mas grande que this2)
 *                      ((-1)-si this1 es mas chico que this2).
 *
 */
int cliente_compararPorNombre(void* this1,void* this2)//recibe dos void
{
	char bufferA[4096];
	char bufferB[4096];

	cliente_getNombre((Cliente*)this1,bufferA);
	cliente_getNombre((Cliente*)this2,bufferB);
	if(strcmp(bufferA,bufferB)>0)
		return 1;
	else if(strcmp(bufferA,bufferB)<0)
		return -1;
	return 0;
}
/*
int cliente_calcularNumeroIntDos(Cliente* this)
{
	int retorno=-1;
	int bufferNumeroInt;

	if(this!=NULL)
	{
		cliente_getNumeroInt(this,&bufferNumeroInt);
		if(bufferNumeroInt<=120)
		{
			cliente_setNumeroIntDos(this,bufferNumeroInt*180);
		}
		else if(bufferNumeroInt>120 && bufferNumeroInt<=160)
		{
			cliente_setNumeroIntDos(this,bufferNumeroInt*240);
		}
		else if(bufferNumeroInt>160 && bufferNumeroInt<240)
		{
			cliente_setNumeroIntDos(this,bufferNumeroInt*350);
		}
	}
	return retorno;
}
*/
//int fun(int indice,int (*pFun) (void*,void*),float peso)


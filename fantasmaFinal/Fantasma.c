#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Fantasma.h"
#include "utn.h"

/** \brief Crea un espacio de memoria con espacio para un Fantasma.
 *
 * \param void
 * \return Fantasma* Puntero a la primera posicion del espacio de memoria creado.
 *
 */
Fantasma* fantasma_new(void)
{
	return (Fantasma*) malloc(sizeof(Fantasma));
}

/** \brief Crea un espacio de memoria con espacio para un Fantasma y lo crea mediante
 *         los parametros pasados.
 *
 * \param char* id (del Fantasma a crear).
 * \param char* nombre (del Fantasma a crear).
 * \param char* numeroInt trabajadas (del Fantasma a crear).
 * \param char* numeroIntDos (del Fantasma a crear).
 * \return Fantasma* Puntero a la primera posicion del espacio de memoria creado.
 *
 */
Fantasma* fantasma_newParametros(char* idStr,char* nombreStr,char* numeroIntStr,char* numeroIntDosStr)
{
	Fantasma* retorno=NULL;
	Fantasma* pAuxFantasma;

	if(idStr!=NULL &&
	   nombreStr!=NULL &&
	   numeroIntStr!=NULL &&
	   numeroIntDosStr!=NULL)
	{
		pAuxFantasma=fantasma_new();
		if(pAuxFantasma!=NULL)
		{
			if(	!fantasma_setIdStr(pAuxFantasma,idStr) &&
				!fantasma_setNombre(pAuxFantasma,nombreStr) &&
				!fantasma_setNumeroIntStr(pAuxFantasma,numeroIntStr) &&
				!fantasma_setNumeroIntDosStr(pAuxFantasma,numeroIntDosStr))
			{
				retorno=pAuxFantasma;
			}
			else
			{
				fantasma_delete(pAuxFantasma);
			}
		}
	}
	return retorno;
}

/** \brief Crea un espacio de memoria con espacio para un Fantasma, lo crea
 *         mediante la estructrura pasada y lo guarda en una LinkedList.
 *
 * \param LinkedList* lista (LinkedList a guardar el Fantasma creado).
 * \param Fantasma emp (Fantasma a guardar en la LinkedList).
 * \return Int retorno (0-Pudo crear y guardar el Fantasma)((-1)-No pudo crear o guardar el Fantasma).
 *
 */
int fantasma_newByStruct(LinkedList* lista,Fantasma emp)
{
    Fantasma* pEmp;
    int retorno=-1;

    pEmp=fantasma_new();
    if(	!fantasma_setNombre(pEmp,emp.nombre)&&
        !fantasma_setId(pEmp,emp.id)&&
        !fantasma_setNumeroInt(pEmp,emp.numeroInt)&&
        !fantasma_setNumeroIntDos(pEmp,emp.numeroIntDos))
    {
        ll_add(lista,pEmp);
        retorno=0;
    }
    else
    {
        fantasma_delete(pEmp);
    }
    return retorno;
}

/** \brief Libera el espacio en memoria ocupado por un Fantasma(Delete).
 *
 * \param void
 * \return Fantasma* Puntero a la primera posicion del espacio de memoria creado.
 *
 */
void fantasma_delete(Fantasma* this)
{
    if(this != NULL)
    {
        free(this);
    }
}

/** \brief Set del id en un Fantasma.
 *
 * \param Fantasma* Puntero del Fantasma
 * \param int id del Fantasma
 * \return int retorno (0-Pudo hacer el set)((-1)-No pudo hacer el set).
 *
 */
int fantasma_setId(Fantasma* this,int id)
{
	int retorno = -1;
    if(this != NULL && !isValidInt(id,10000,0))
    {
        this->id = id;
        retorno = 0;
    }
    return retorno;
}

/** \brief Obtiene el id de un Fantasma.
 *
 * \param Fantasma* Puntero del Fantasma
 * \param int* id del Fantasma
 * \return int retorno (0-Pudo obtener)((-1)-No pudo obtener).
 *
 */
int fantasma_getId(Fantasma* this,int* id)
{
	int retorno = -1;
    if(this != NULL && id != NULL)
    {
        *id = this->id;
        retorno = 0;
    }
    return retorno;
}

/** \brief Set del nombre en un Fantasma.
 *
 * \param Fantasma* Puntero del Fantasma
 * \param char* nombre del Fantasma
 * \return int retorno (0-Pudo hacer el set)((-1)-No pudo hacer el set).
 *
 */
int fantasma_setNombre(Fantasma* this,char* nombre)
{
	int retorno = -1;
    if(this != NULL && !isValidName(nombre))
    {
        strncpy(this->nombre,nombre,sizeof(this->nombre));
        retorno = 0;
    }
    return retorno;
}

/** \brief Obtiene el nombre de un Fantasma.
 *
 * \param Fantasma* Puntero del Fantasma
 * \param char* nombre del Fantasma
 * \return int retorno (0-Pudo obtener)((-1)-No pudo obtener).
 *
 */
int fantasma_getNombre(Fantasma* this,char* nombre)
{
	int retorno = -1;
    if(this != NULL && nombre != NULL)
    {
        strncpy(nombre,this->nombre,sizeof(this->nombre));
        retorno = 0;
    }
    return retorno;
}
/** \brief Set del apellido en un Fantasma.
 *
 * \param Fantasma* Puntero del Fantasma
 * \param char* apellido del Fantasma
 * \return int retorno (0-Pudo hacer el set)((-1)-No pudo hacer el set).
 *
 */
int fantasma_setApellido(Fantasma* this,char* apellido)
{
    int retorno = -1;
    if(this != NULL && !isValidName(apellido))
    {
        strncpy(this->apellido,apellido,sizeof(this->apellido));
        retorno = 0;
    }
    return retorno;
}
/** \brief Obtiene el apeliido de un Fantasma.
 *
 * \param Fantasma* Puntero del Fantasma
 * \param char* apellido del Fantasma
 * \return int retorno (0-Pudo obtener)((-1)-No pudo obtener).
 *
 */
int fantasma_getApellido(Fantasma* this,char* apellido)
{
    int retorno = -1;
    if(this != NULL && apellido != NULL)
    {
        strncpy(apellido,this->apellido,sizeof(this->apellido));
        retorno = 0;
    }
    return retorno;
}

/** \brief Set de numeroInt trabajadas en un Fantasma.
 *
 * \param Fantasma* Puntero del Fantasma
 * \param int numeroInt trabajadas del Fantasma
 * \return int retorno (0-Pudo hacer el set)((-1)-No pudo hacer el set).
 *
 */
int fantasma_setNumeroInt(Fantasma* this,int numeroInt)
{
	int retorno = -1;
    if(this != NULL)
    {
        this->numeroInt=numeroInt;
        retorno = 0;
    }
    return retorno;
}

/** \brief Obtiene numeroInt trabajadas de un Fantasma.
 *
 * \param Fantasma* Puntero del Fantasma
 * \param int* numeroInt del Fantasma
 * \return int retorno (0-Pudo obtener)((-1)-No pudo obtener).
 *
 */
int fantasma_getNumeroInt(Fantasma* this,int* numeroInt)
{
	int retorno = -1;
    if(this != NULL && numeroInt != NULL)
    {
        *numeroInt = this->numeroInt;
        retorno = 0;
    }
    return retorno;
}

/** \brief Set del numeroIntDos en un Fantasma.
 *
 * \param Fantasma* Puntero del Fantasma
 * \param int numeroIntDos del Fantasma
 * \return int retorno (0-Pudo hacer el set)((-1)-No pudo hacer el set).
 *
 */
int fantasma_setNumeroIntDos(Fantasma* this,int numeroIntDos)
{
	int retorno = -1;
    if(this != NULL)
    {
        this->numeroIntDos=numeroIntDos;
        retorno = 0;
    }
    return retorno;
}

/** \brief Obtiene el numeroIntDos de un Fantasma.
 *
 * \param Fantasma* Puntero del Fantasma
 * \param int* numeroIntDos del Fantasma
 * \return int retorno (0-Pudo obtener)((-1)-No pudo obtener).
 *
 */
int fantasma_getNumeroIntDos(Fantasma* this,int* numeroIntDos)
{
	int retorno = -1;
    if(this != NULL && numeroIntDos != NULL)
    {
        *numeroIntDos = this->numeroIntDos;
        retorno = 0;
    }
    return retorno;
}

/** \brief Set del id en string en un Fantasma.
 *
 * \param Fantasma* Puntero del Fantasma
 * \param char* id del Fantasma
 * \return int retorno (0-Pudo hacer el set)((-1)-No pudo hacer el set).
 *
 */
int fantasma_setIdStr(Fantasma* this, char* id)
{
    int retorno = -1;
    if(this != NULL)
    {
        retorno = fantasma_setId(this,atoi(id));
    }
    return retorno;
}

/** \brief Obtiene el id en string de un Fantasma.
 *
 * \param Fantasma* Puntero del Fantasma
 * \param char* id del Fantasma
 * \return int retorno (0-Pudo obtener)((-1)-No pudo obtener).
 *
 */
int fantasma_getIdStr(Fantasma* this, char* id)
{
    int retorno = -1;
    int bufferInt;
    if(this != NULL && id != NULL)
    {
        fantasma_getId(this,&bufferInt);
        sprintf(id,"%d",bufferInt);
        retorno = 0;
    }
    return retorno;
}

/** \brief Set de numeroInt trabajadas en string en un Fantasma.
 *
 * \param Fantasma* Puntero del Fantasma
 * \param char* numeroInt del Fantasma
 * \return int retorno (0-Pudo hacer el set)((-1)-No pudo hacer el set).
 *
 */
int fantasma_setNumeroIntStr(Fantasma* this, char* numeroInt)
{
    int retorno = -1;
    if(this != NULL)
    {
        retorno = fantasma_setNumeroInt(this,atoi(numeroInt));
    }
    return retorno;
}

/** \brief Obtiene numeroInt trabajadas en string de un Fantasma.
 *
 * \param Fantasma* Puntero del Fantasma
 * \param char* numeroInt del Fantasma
 * \return int retorno (0-Pudo obtener)((-1)-No pudo obtener).
 *
 */
int fantasma_getNumeroIntStr(Fantasma* this, char* numeroInt)
{
    int retorno = -1;
    int bufferInt;
    if(this != NULL && numeroInt != NULL)
    {
        fantasma_getNumeroInt(this,&bufferInt);
        sprintf(numeroInt,"%d",bufferInt);
        retorno = 0;
    }
    return retorno;
}

/** \brief Set del numeroIntDos en string en un Fantasma.
 *
 * \param Fantasma* Puntero del Fantasma
 * \param char* numeroIntDos del Fantasma
 * \return int retorno (0-Pudo hacer el set)((-1)-No pudo hacer el set).
 *
 */
int fantasma_setNumeroIntDosStr(Fantasma* this, char* numeroIntDos)
{
    int retorno = -1;
    if(this != NULL)
    {
        retorno = fantasma_setNumeroIntDos(this,atoi(numeroIntDos));
    }
    return retorno;
}

/** \brief Obtiene el numeroIntDos en string de un Fantasma.
 *
 * \param Fantasma* Puntero del Fantasma
 * \param char* numeroIntDos del Fantasma
 * \return int retorno (0-Pudo obtener)((-1)-No pudo obtener).
 *
 */
int fantasma_getNumeroIntDosStr(Fantasma* this, char* numeroIntDos)
{
    int retorno = -1;
    int bufferInt;
    if(this != NULL && numeroIntDos != NULL)
    {
        fantasma_getNumeroIntDos(this,&bufferInt);
        sprintf(numeroIntDos,"%d",bufferInt);
        retorno = 0;
    }
    return retorno;
}

/** \brief Obtiene el id maximo de un Fantasma en una LinkedList.
 *
 * \param LinkedList* pArray .
 * \return int max retorna el id mas grande.
 *
 */
int fantasma_getIdMax(LinkedList* pArray)
{
	int i;
	int id;
	int max;
	int flag=0;
	Fantasma* pAux;
	if(pArray!=NULL)
	{
		for(i=0;i<ll_len(pArray);i++)
		{
			pAux=ll_get(pArray,i);
			fantasma_getId(pAux,&id);
			if(flag==0 || id>max)
			{
				max=id;
				flag=1;
			}
		}
	}
	return max;
}

/** \brief Obtiene el indice de un Fantasma mediante su id.
 *
 * \param LinkedList* pArray.
 * \param int id del Fantasma
 * \param int* indice del Fantasma buscado.
 * \return int retorno (0-Si lo encontro)((-1)-No lo encontro).
 *
 */
int fantasma_getEmpById(LinkedList* pArray,int id,int* indice)
{
	int i;
	Fantasma* pAuxEmp;
	int bufferId;
	int retorno=-1;

	if(pArray!=NULL)
	{
		for(i=0;i<ll_len(pArray);i++)
		{
			pAuxEmp=ll_get(pArray,i);
			if(!fantasma_getId(pAuxEmp,&bufferId))
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

/** \brief Compara por nombre dos Fantasma.
 *
 * \param void* this1.
 * \param void* this2.
 * \return int retorno (0-Si son iguales)(1-si this1 es mas grande que this2)
 *                      ((-1)-si this1 es mas chico que this2).
 *
 */
int fantasma_compararPorNombre(void* this1,void* this2)//recibe dos void
{
	char bufferA[4096];
	char bufferB[4096];

	fantasma_getNombre((Fantasma*)this1,bufferA);
	fantasma_getNombre((Fantasma*)this2,bufferB);
	if(strcmp(bufferA,bufferB)>0)
		return 1;
	else if(strcmp(bufferA,bufferB)<0)
		return -1;
	return 0;
}

int fantasma_calcularNumeroIntDos(Fantasma* this)
{
	int retorno=-1;
	int bufferNumeroInt;

	if(this!=NULL)
	{
		fantasma_getNumeroInt(this,&bufferNumeroInt);
		if(bufferNumeroInt<=120)
		{
			fantasma_setNumeroIntDos(this,bufferNumeroInt*180);
		}
		else if(bufferNumeroInt>120 && bufferNumeroInt<=160)
		{
			fantasma_setNumeroIntDos(this,bufferNumeroInt*240);
		}
		else if(bufferNumeroInt>160 && bufferNumeroInt<240)
		{
			fantasma_setNumeroIntDos(this,bufferNumeroInt*350);
		}
	}
	return retorno;
}

//int fun(int indice,int (*pFun) (void*,void*),float peso)


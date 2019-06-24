#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Fantasma.h"
#include "parser.h"
#include "utn.h"


/** \brief Carga los datos de los fantasmas desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListFantasma LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListFantasma)
{
    FILE* pFile;
    int retorno=-1;
    if(path!=NULL && pArrayListFantasma!=NULL)
    {
		pFile=fopen(path,"r");
		if(pFile!=NULL)
		{
			parser_FantasmaFromText(pFile,pArrayListFantasma);
			retorno=0;
		}
    }
    fclose(pFile);
    return retorno;
}

/** \brief Carga los datos de los fantasmas desde el archivo data.bin (modo binario).
 *
 * \param path char*
 * \param pArrayListFantasma LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListFantasma)
{
	FILE* pFile;
    int retorno=-1;
    Fantasma fan;
    if(path!=NULL && pArrayListFantasma!=NULL)
    {
		pFile=fopen(path,"r");
		if(pFile!=NULL)
		{
			while(!feof(pFile))
			{
				fread(&fan,sizeof(Fantasma),1,pFile);
				if(!fantasma_newByStruct(pArrayListFantasma,fan))
				{
					retorno=0;
				}
			}
		}
    }
    fclose(pFile);
    return retorno;
}

/** \brief Alta de fantasmas
 *
 * \param path char*
 * \param pArrayListFantasma LinkedList*
 * \return int
 *
 */
int controller_addFantasma(LinkedList* pArrayListFantasma)
{
    char bufferName[128];
    char bufferNumeroInt[128];
    char bufferNumeroIntDos[128];
    char bufferId[128];
    int retorno=-1;
    int id;
    Fantasma* pAux;

    if(pArrayListFantasma!=NULL)
    {
		if(	!utn_getName("\nIngrese nombre: ","ERROR",1,128,2,bufferName) &&
			!utn_getIntStr("\nIngrese horas trabajadas: ","ERROR",1,6,1,100000,2,bufferNumeroInt) &&
			!utn_getIntStr("\nIngrese numeroIntDos: ","ERROR",1,7,1,1000000,2,bufferNumeroIntDos))
		{
			id=fantasma_getIdMax(pArrayListFantasma);
			sprintf(bufferId,"%d",id+1);
			pAux=fantasma_newParametros(bufferId,bufferName,bufferNumeroInt,bufferNumeroIntDos);
			ll_add(pArrayListFantasma,pAux);
			retorno=0;
		}

    }
    return retorno;
}

/** \brief Modificar datos de fantasma
 *
 * \param path char*
 * \param pArrayListFantasma LinkedList*
 * \return int
 *
 */
int controller_editFantasma(LinkedList* pArrayListFantasma)
{
    char bufferNombre[128];
    char bufferNumeroInt[128];
    char bufferNumeroIntDos[128];
	int idMod;
	int indice;
	int llSize=ll_len(pArrayListFantasma);
	Fantasma* pAux;
	int retorno=-1;

	if(	!utn_getInt("\nIngrese id del fantasma:","ERROR",1,llSize,2,&idMod) &&
		!fantasma_getEmpById(pArrayListFantasma,idMod,&indice) &&
        indice<=llSize)
	{
        pAux=ll_get(pArrayListFantasma,indice);
        if(	!utn_getName("\nIngrese nombre: ","ERROR",1,128,2,bufferNombre) &&
            !utn_getIntStr("\nIngrese horas trabajadas: ","ERROR",1,6,1,100000,2,bufferNumeroInt) &&
            !utn_getIntStr("\nIngrese numeroIntDos: ","ERROR",1,7,1,1000000,2,bufferNumeroIntDos))
		{
			if(	!fantasma_setNombre(pAux,bufferNombre) &&
				!fantasma_setNumeroIntStr(pAux,bufferNumeroInt) &&
				!fantasma_setNumeroIntDosStr(pAux,bufferNumeroIntDos))
			{
				retorno=0;
			}
		}
	}
    return retorno;
}

/** \brief Baja de fantasma
 *
 * \param path char*
 * \param pArrayListFantasma LinkedList*
 * \return int
 *
 */
int controller_removeFantasma(LinkedList* pArrayListFantasma)
{
    int retorno=-1;
    Fantasma* pEmpDel;
    int indice;
    int id;
    int llSize=ll_len(pArrayListFantasma);

    if(pArrayListFantasma!=NULL)
    {
        if(	!utn_getInt("\nIngrese id del fantasma:","ERROR",1,llSize,2,&id) &&
            !fantasma_getEmpById(pArrayListFantasma,id,&indice))
        {
            pEmpDel=ll_pop(pArrayListFantasma,indice);
            fantasma_delete(pEmpDel);
            retorno=0;
        }
    }
    return retorno;
}

/** \brief Listar fantasmas
 *
 * \param path char*
 * \param pArrayListFantasma LinkedList*
 * \return int
 *
 */
int controller_ListFantasma(LinkedList* pArrayListFantasma)
{
	int bufferId;
    char bufferNombre[4096];
    int bufferNumeroInt;
    int bufferNumeroIntDos;

    int i;
    int len;
    int retorno=-1;
    Fantasma* pAux;
    len=ll_len(pArrayListFantasma);
    printf("len ll:%d",len);
    for(i=0;i<len;i++)
    {
        if(pArrayListFantasma!=NULL)
		{
			pAux=ll_get(pArrayListFantasma,i);
		}
		if(	!fantasma_getId(pAux,&bufferId) &&
			!fantasma_getNombre(pAux,bufferNombre) &&
			!fantasma_getNumeroInt(pAux,&bufferNumeroInt) &&
			!fantasma_getNumeroIntDos(pAux,&bufferNumeroIntDos))
		{
			printf("\nID:%d\nNombre:%s\nNumeroInt:%d\nNumeroIntDos:%d\n", bufferId,
                                                                bufferNombre,
                                                                bufferNumeroInt,
                                                                bufferNumeroIntDos);
			retorno=0;
		}
    }
    return retorno;
}

/** \brief Ordenar fantasmas
 *
 * \param path char*
 * \param pArrayListFantasma LinkedList*
 * \return int
 *
 */
int controller_sortFantasma(LinkedList* pArrayListFantasma)
{
    int retorno=-1;
    if(pArrayListFantasma!=NULL)
    {
        ll_sort(pArrayListFantasma,fantasma_compararPorNombre,1);
        retorno=0;
    }
    return retorno;
}

/** \brief Guarda los datos de los fantasmas en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListFantasma LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListFantasma)
{
    char bufferId[128];
    char bufferNombre[128];
    char bufferNumeroInt[128];
    char bufferNumeroIntDos[128];
    int retorno=-1;
    int i;

	Fantasma* pAux=NULL;
	FILE* pFile=NULL;

    if(path!=NULL && pArrayListFantasma!=NULL)
    {
		pFile=fopen(path,"w");
		if(pFile!=NULL)
		{
			for(i=0;i<ll_len(pArrayListFantasma);i++)
            {
                pAux=ll_get(pArrayListFantasma,i);
                if(	pAux !=NULL &&
                    !fantasma_getIdStr(pAux,bufferId) &&
                    !fantasma_getNombre(pAux,bufferNombre) &&
                    !fantasma_getNumeroIntStr(pAux,bufferNumeroInt) &&
                    !fantasma_getNumeroIntDosStr(pAux,bufferNumeroIntDos))
                {
                    fprintf(pFile,"%s,%s,%s,%s\n",  bufferId,
                                                    bufferNombre,
                                                    bufferNumeroInt,
                                                    bufferNumeroIntDos);
                    retorno=0;
                }
            }
		}
    }
    fclose(pFile);
    return retorno;
}

/** \brief Guarda los datos de los fantasmas en el archivo data.bin (modo binario).
 *
 * \param path char*
 * \param pArrayListFantasma LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListFantasma)
{
	int i;
	Fantasma* pEmp=NULL;
	FILE* pFile=NULL;
    int retorno=-1;
    if(path!=NULL && pArrayListFantasma!=NULL)
    {
		pFile=fopen(path,"w");
		if(pFile!=NULL)
		{
			for(i=0;i<ll_len(pArrayListFantasma);i++)
			{
				pEmp=ll_get(pArrayListFantasma,i);
				fwrite(pEmp,sizeof(Fantasma),1,pFile);
				retorno=0;
			}
		}
    }
    fclose(pFile);
    return retorno;
}


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Cliente.h"
#include "Venta.h"
#include "utn.h"

/** \brief Parsea los datos los datos de los clientes desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListCliente LinkedList*
 * \return int
 *
 */
int parser_ClienteFromText(FILE* pFile , LinkedList* pArrayListCliente)
{
	char salto[512];
	int retorno=-1;

	char bufferId[128];
    char bufferNombre[128];
    char bufferApellido[128];
    char bufferDni[9];
    Cliente* pAux;

    if(pFile!=NULL)
    {
		fscanf(pFile,"%[^\n]\n",salto);
		while(!feof(pFile))
		{
			fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",bufferId,bufferNombre,bufferApellido,bufferDni);
            pAux=cliente_newParametros(bufferId,bufferNombre,bufferApellido,bufferDni);
            if(pAux!=NULL)
            {
				ll_add(pArrayListCliente,pAux);
				retorno=0;
            }
		}
	}
    return retorno;
}
/** \brief Parsea los datos los datos de los clientes desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayVentas LinkedList*
 * \return int
 *
 */
int parser_VentasFromText(FILE* pFile , LinkedList* pArrayVentas)
{
	char salto[512];
	int retorno=-1;

	char bufferId[128];
    char bufferIdCliente[128];
    char bufferCodProducto[128];
    char bufferCantidad[128];
    char bufferPrecioUnidad[128];
    Venta* pAux;

    if(pFile!=NULL)
    {
		fscanf(pFile,"%[^\n]\n",salto);
		while(!feof(pFile))
		{
			fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",bufferId,
                                                            bufferIdCliente,
                                                            bufferCodProducto,
                                                            bufferCantidad,
                                                            bufferPrecioUnidad);

            pAux=venta_newParametros(bufferId,
                                     bufferIdCliente,
                                     bufferCodProducto,
                                     bufferCantidad,
                                     bufferPrecioUnidad);
            if(pAux!=NULL)
            {
				ll_add(pArrayVentas,pAux);
				retorno=0;
            }
		}
	}
    return retorno;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Cliente.h"
#include "Venta.h"
#include "parser.h"
#include "utn.h"

/** \brief Carga los datos de los clientes desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayClientes LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* pathClientes, LinkedList* pArrayClientes)
{
    FILE* pFileClientes;
    int retorno=-1;
    if(pathClientes!=NULL &&
       pArrayClientes!=NULL)
    {
		pFileClientes=fopen(pathClientes,"r");
		if(pFileClientes!=NULL)
		{
			parser_ClienteFromText(pFileClientes,pArrayClientes);
			retorno=0;
		}
    }
    fclose(pFileClientes);
    return retorno;
}

/** \brief Carga los datos de los ventas desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayVentas LinkedList*
 * \return int
 *
 */
int controller_ventasLoadFromText(char* pathVentas, LinkedList* pArrayVentas)
{
    FILE* pFileVentas;
    int retorno=-1;
    if(pathVentas!=NULL &&
       pArrayVentas!=NULL)
    {
		pFileVentas=fopen(pathVentas,"r");
		if(pFileVentas!=NULL)
		{
			parser_VentasFromText(pFileVentas,pArrayVentas);
			retorno=0;
		}
    }
    fclose(pFileVentas);
    return retorno;
}

/** \brief Alta de clientes
 *
 * \param path char*
 * \param pArrayListCliente LinkedList*
 * \return int
 *
 */
int controller_addCliente(LinkedList* pArrayListCliente)
{
    char bufferName[128];
    char bufferApellido[128];
    char bufferDni[9];
    char bufferId[128];
    int retorno=-1;
    int id;
    Cliente* pAux;

    if(pArrayListCliente!=NULL)
    {
		if(	!utn_getName("\nIngrese nombre: ","ERROR",1,128,2,bufferName) &&
			!utn_getName("\nIngrese apellido: ","ERROR",1,128,2,bufferApellido) &&
			!utn_getDNI("\nIngrese DNI: ","ERROR",2,bufferDni))
		{
			id=cliente_getIdMax(pArrayListCliente);
			sprintf(bufferId,"%d",id+1);
			pAux=cliente_newParametros(bufferId,bufferName,bufferApellido,bufferDni);
			ll_add(pArrayListCliente,pAux);
			retorno=0;
		}

    }
    return retorno;
}
/** \brief Alta de clientes
 *
 * \param path char*
 * \param pArrayListCliente LinkedList*
 * \return int
 *
 */
int controller_addVenta(LinkedList* pArrayVentas,LinkedList* pArrayClientes)
{
    int bufferIdCliente;
    int cantidad;
    int codigo;
    int aux;
    int id;
    char bufferPrecioU[128];
    char bufferCodigoStr[128];
    char bufferIdStr[128];
    char bufferCantidadStr[128];
    char bufferIdClienteStr[128];
    int retorno=-1;
    Venta* pAux;

    if(pArrayClientes!=NULL &&
       pArrayVentas!=NULL)
    {
		if(	!utn_getInt("\nIngrese ID de cliente:","ERROR",1,ll_len(pArrayClientes),2,&bufferIdCliente) &&
            !cliente_getCliById(pArrayClientes,bufferIdCliente,&aux) &&
			!utn_getInt("\n1000-TV_LG_32\n1001-PS4\n1002-IPHONE7\nIngrese codigo de producto: ","ERROR",
                                                                                                1000,
                                                                                                1002,
                                                                                                2,
                                                                                                &codigo) &&
			!utn_getInt("\nIngrese Cantidad: ","ERROR",1,10000,2,&cantidad))
		{
			if(codigo==1000)
            {
                strcpy(bufferPrecioU,"8999.99");
            }
            else if(codigo==1001)
            {
                strcpy(bufferPrecioU,"12999.99");
            }
            else if(codigo==1002)
            {
                strcpy(bufferPrecioU,"19480.99");
            }
			id=venta_getIdMax(pArrayVentas);
			sprintf(bufferIdStr,"%d",id+1);
			sprintf(bufferCodigoStr,"%d",codigo);
			sprintf(bufferCantidadStr,"%d",cantidad);
			sprintf(bufferIdClienteStr,"%d",bufferIdCliente);
			pAux=venta_newParametros(bufferIdStr,bufferIdClienteStr,bufferCodigoStr,bufferCantidadStr,bufferPrecioU);
			ll_add(pArrayVentas,pAux);
			retorno=0;
		}

    }
    return retorno;
}
/** \brief Modificar datos de cliente
 *
 * \param path char*
 * \param pArrayListCliente LinkedList*
 * \return int
 *
 */
int controller_editCliente(LinkedList* pArrayListCliente)
{
    char bufferNombre[128];
    char bufferApellido[128];
    char bufferDni[9];
	int idMod;
	int indice;
	int llSize=ll_len(pArrayListCliente);
	Cliente* pAux;
	int retorno=-1;

	if(	!utn_getInt("\nIngrese id del cliente:","ERROR",1,llSize,2,&idMod) &&
		!cliente_getCliById(pArrayListCliente,idMod,&indice) &&
        indice<=llSize)
	{
        pAux=ll_get(pArrayListCliente,indice);
        if(	!utn_getName("\nIngrese nombre: ","ERROR",1,128,2,bufferNombre) &&
            !utn_getName("\nIngrese apellido: ","ERROR",1,128,2,bufferApellido) &&
            !utn_getDNI("\nIngrese DNI: ","ERROR",2,bufferDni))
		{
			if(	!cliente_setNombre(pAux,bufferNombre) &&
				!cliente_setApellido(pAux,bufferApellido) &&
				!cliente_setDni(pAux,bufferDni))
			{
				retorno=0;
			}
		}
	}
    return retorno;
}

/** \brief Baja de cliente
 *
 * \param pArrayClientes LinkedList*
 * \return int
 *
 */
int controller_removeCliente(LinkedList* pArrayClientes,LinkedList* pArrayVentas)
{
    int retorno=-1;
    Cliente* pCliente;
    int indice;
    int id;
    int llSize=ll_len(pArrayClientes);

    if(pArrayClientes!=NULL)
    {
        if(	!utn_getInt("\nIngrese id del cliente:","ERROR",1,llSize,2,&id) &&
            !cliente_getCliById(pArrayClientes,id,&indice) &&
            venta_getCliById(pArrayVentas,id)==-1)
        {
            pCliente=ll_pop(pArrayClientes,indice);
            cliente_delete(pCliente);
            retorno=0;
        }
    }
    return retorno;
}
/** \brief Baja de venta
 *
 * \param pArrayVentas LinkedList*
 * \return int
 *
 */
int controller_removeVenta(LinkedList* pArrayVentas)
{
    int retorno=-1;
    Venta* pVenta;
    int indice;
    int id;
    int len=ll_len(pArrayVentas);

    if(pArrayVentas!=NULL)
    {
        if(	!utn_getInt("\nIngrese id de venta:","ERROR",1,len,2,&id) &&
            !venta_getVenById(pArrayVentas,id,&indice))
        {
            pVenta=ll_pop(pArrayVentas,indice);
            venta_delete(pVenta);
            retorno=0;
        }
    }
    return retorno;
}
/** \brief Listar clientes
 *
 * \param path char*
 * \param pArrayListCliente LinkedList*
 * \return int
 *
 */
int controller_ListCliente(LinkedList* pArrayListCliente)
{
	int bufferId;
    char bufferNombre[128];
    char bufferApellido[128];
    char bufferDni[9];

    int i;
    int len;
    int retorno=-1;
    Cliente* pAux;
    len=ll_len(pArrayListCliente);
    for(i=0;i<len;i++)
    {
        if(pArrayListCliente!=NULL)
		{
			pAux=ll_get(pArrayListCliente,i);
		}
		if(	!cliente_getId(pAux,&bufferId) &&
			!cliente_getNombre(pAux,bufferNombre) &&
			!cliente_getApellido(pAux,bufferApellido) &&
			!cliente_getDni(pAux,bufferDni))
		{
			printf("\n%d %s %s %s", bufferId,
                                    bufferNombre,
                                    bufferApellido,
                                    bufferDni);
			retorno=0;
		}
    }
    printf("\n\nCantidad de clientes: %d",len);
    return retorno;
}
/** \brief Listar ventas
 *
 * \param path char*
 * \param pArrayListCliente LinkedList*
 * \return int
 *
 */
int controller_ListVentas(LinkedList* pArrayVentas,LinkedList* pArrayClientes)
{
	int bufferId;
    int bufferIdCliente;
    char bufferCodProducto[128];
    int bufferCantidad;
    float bufferPrecioUnidad;

    char bufferNombreCli[128];
    char bufferApellidoCli[128];
    char bufferDniCli[9];

    int i;
    int len;
    int indice;
    int retorno=-1;
    Venta* pAux;
    Cliente* pAuxCliente;
    len=ll_len(pArrayVentas);
    for(i=0;i<len;i++)
    {
        if(pArrayVentas!=NULL &&
           pArrayClientes!=NULL)
		{
			pAux=ll_get(pArrayVentas,i);
			venta_getIdCliente(pAux,&bufferIdCliente);
			if(!cliente_getCliById(pArrayClientes,bufferIdCliente,&indice))
			{
			    pAuxCliente=ll_get(pArrayClientes,indice);
			    if( !venta_getId(pAux,&bufferId) &&
                    !cliente_getNombre(pAuxCliente,bufferNombreCli) &&
                    !cliente_getApellido(pAuxCliente,bufferApellidoCli) &&
                    !cliente_getDni(pAuxCliente,bufferDniCli) &&
                    !venta_getCodigoProducto(pAux,bufferCodProducto) &&
                    !venta_getCantidad(pAux,&bufferCantidad) &&
                    !venta_getPrecioUnidad(pAux,&bufferPrecioUnidad))
                {
                    printf("\n%d %s %s %s %s %.2f", bufferId,
                                                    bufferNombreCli,
                                                    bufferApellidoCli,
                                                    bufferDniCli,
                                                    bufferCodProducto,
                                                    bufferCantidad*bufferPrecioUnidad);
                    retorno=0;
                }
			}

		}
    }
    printf("\n\nCantidad de Ventas: %d\n",len);
    return retorno;
}
/** \brief Listar ventas por producto
 *
 * \param path char*
 * \param pArrayListCliente LinkedList*
 * \return int
 *
 */
int controller_ListVentasByProducto(LinkedList* pArrayVentas,LinkedList* pArrayClientes)
{
	int bufferId;
    int bufferIdCliente;
    char bufferCodProducto[128];
    int bufferCantidad;
    float bufferPrecioUnidad;

    char bufferNombreCli[128];
    char bufferApellidoCli[128];
    char bufferDniCli[9];
    char producto[128];

    int i;
    int len;
    int indice;
    int retorno=-1;
    Venta* pAux;
    Cliente* pAuxCliente;
    len=ll_len(pArrayVentas);

    if( pArrayVentas!=NULL &&
        pArrayClientes!=NULL)
    {
        if(!utn_getTexto("\nIngrese codigo de producto: ","\nERROR",4,5,2,producto))
        {
            for(i=0;i<len;i++)
            {
                pAux=ll_get(pArrayVentas,i);
                venta_getCodigoProducto(pAux,bufferCodProducto);
                if(strcmp(producto,bufferCodProducto)==0)
                {
                    venta_getIdCliente(pAux,&bufferIdCliente);
                    if(!cliente_getCliById(pArrayClientes,bufferIdCliente,&indice))
                    {
                        pAuxCliente=ll_get(pArrayClientes,indice);
                        if( !venta_getId(pAux,&bufferId) &&
                            !cliente_getNombre(pAuxCliente,bufferNombreCli) &&
                            !cliente_getApellido(pAuxCliente,bufferApellidoCli) &&
                            !cliente_getDni(pAuxCliente,bufferDniCli) &&
                            !venta_getCodigoProducto(pAux,bufferCodProducto) &&
                            !venta_getCantidad(pAux,&bufferCantidad) &&
                            !venta_getPrecioUnidad(pAux,&bufferPrecioUnidad))
                        {
                            printf("\n%d %s %s %s %s %.2f", bufferId,
                                                            bufferNombreCli,
                                                            bufferApellidoCli,
                                                            bufferDniCli,
                                                            bufferCodProducto,
                                                            bufferCantidad*bufferPrecioUnidad);
                            retorno=0;
                        }
                    }
                }
            }
        }
    }
    printf("\n\nCantidad de Ventas: %d\n",len);
    return retorno;
}
/** \brief Ordenar clientes
 *
 * \param path char*
 * \param pArrayListCliente LinkedList*
 * \return int
 *
 */
/*int controller_sortCliente(LinkedList* pArrayListCliente)
{
    int retorno=-1;
    if(pArrayListCliente!=NULL)
    {
        ll_sort(pArrayListCliente,cliente_compararPorNombre,1);
        retorno=0;
    }
    return retorno;
}
*/
/** \brief Guarda los datos de los clientes en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayClientes LinkedList*
 * \return int
 *
 */
int controller_saveClientesAsText(char* pathClientes, LinkedList* pArrayClientes)
{
    char bufferId[128];
    char bufferNombre[128];
    char bufferApellido[128];
    char bufferDni[9];
    int retorno=-1;
    int i;

	Cliente* pAux=NULL;
	FILE* pFile=NULL;

    if(pathClientes!=NULL && pArrayClientes!=NULL)
    {
		pFile=fopen(pathClientes,"w");
		if(pFile!=NULL)
		{
			for(i=0;i<ll_len(pArrayClientes);i++)
            {
                pAux=ll_get(pArrayClientes,i);
                if(	pAux !=NULL &&
                    !cliente_getIdStr(pAux,bufferId) &&
                    !cliente_getNombre(pAux,bufferNombre) &&
                    !cliente_getApellido(pAux,bufferApellido) &&
                    !cliente_getDni(pAux,bufferDni))
                {
                    fprintf(pFile,"%s,%s,%s,%s\n",  bufferId,
                                                    bufferNombre,
                                                    bufferApellido,
                                                    bufferDni);
                    retorno=0;
                }
            }
		}
    }
    fclose(pFile);
    return retorno;
}
/** \brief Guarda los datos de los clientes en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayClientes LinkedList*
 * \return int
 *
 */
int controller_saveVentasAsText(char* pathVentas, LinkedList* pArrayVentas)
{
    char bufferId[128];
    char bufferIdCliente[128];
    char bufferCodigo[128];
    char bufferCantidad[128];
    char bufferPrecioU[128];
    int retorno=-1;
    int i;

	Venta* pAux=NULL;
	FILE* pFile=NULL;

    if(pathVentas!=NULL && pArrayVentas!=NULL)
    {
		pFile=fopen(pathVentas,"w");
		if(pFile!=NULL)
		{
			for(i=0;i<ll_len(pArrayVentas);i++)
            {
                pAux=ll_get(pArrayVentas,i);
                if(	pAux !=NULL &&
                    !venta_getIdStr(pAux,bufferId) &&
                    !venta_getIdClienteStr(pAux,bufferIdCliente) &&
                    !venta_getCodigoProducto(pAux,bufferCodigo) &&
                    !venta_getCantidadStr(pAux,bufferCantidad) &&
                    !venta_getPrecioUnidadStr(pAux,bufferPrecioU))
                {
                    fprintf(pFile,"%s,%s,%s,%s,%s\n",   bufferId,
                                                        bufferIdCliente,
                                                        bufferCodigo,
                                                        bufferCantidad,
                                                        bufferPrecioU);
                    retorno=0;
                }
            }
		}
    }
    fclose(pFile);
    return retorno;
}
/** \brief Guardar informes ventas
 *
 * \param path char*
 * \param pArrayListCliente LinkedList*
 * \return int
 *
 */
int controller_SaveInformeVentas(char* path,LinkedList* pArrayVentas,LinkedList* pArrayClientes)
{
	char bufferId[128];
    int bufferIdCliente;
    char bufferCodProducto[128];
    int bufferCantidad;
    float bufferPrecioUnidad;
    char monto[128];

    char bufferNombreCli[128];
    char bufferApellidoCli[128];
    char bufferDniCli[9];

    int i;
    int len;
    int indice;
    int retorno=-1;
    Venta* pAux;
    Cliente* pAuxCliente;
    FILE* pFile=fopen(path,"w");
    len=ll_len(pArrayVentas);

    if( pArrayVentas!=NULL &&
        pArrayClientes!=NULL &&
        pFile!=NULL)
    {
        for(i=0;i<len;i++)
        {
            pAux=ll_get(pArrayVentas,i);
            venta_getIdCliente(pAux,&bufferIdCliente);
            if(!cliente_getCliById(pArrayClientes,bufferIdCliente,&indice))
            {
                pAuxCliente=ll_get(pArrayClientes,indice);
                if( !venta_getIdStr(pAux,bufferId) &&
                    !cliente_getNombre(pAuxCliente,bufferNombreCli) &&
                    !cliente_getApellido(pAuxCliente,bufferApellidoCli) &&
                    !cliente_getDni(pAuxCliente,bufferDniCli) &&
                    !venta_getCodigoProducto(pAux,bufferCodProducto) &&
                    !venta_getCantidad(pAux,&bufferCantidad) &&
                    !venta_getPrecioUnidad(pAux,&bufferPrecioUnidad))
                {
                    sprintf(monto,"%.2f",bufferCantidad*bufferPrecioUnidad);
                    fprintf(pFile,"%s,%s,%s,%s,%s,%s\n",bufferId,
                                                        bufferNombreCli,
                                                        bufferApellidoCli,
                                                        bufferDniCli,
                                                        bufferCodProducto,
                                                        monto);
                    retorno=0;
                }
            }
        }
    }
    fclose(pFile);
    return retorno;
}
/** \brief Listar ventas por cliente
 *
 * \param path char*
 * \param pArrayListCliente LinkedList*
 * \return int
 *
 */
int controller_ListVentas(LinkedList* pArrayVentas,LinkedList* pArrayClientes)
{
	int bufferId;
    int bufferIdCliente;
    char bufferCodProducto[128];
    int bufferCantidad;
    float bufferPrecioUnidad;

    char bufferNombreCli[128];
    char bufferApellidoCli[128];
    char bufferDniCli[9];

    int i;
    int len;
    int indice;
    int retorno=-1;
    Venta* pAux;
    Cliente* pAuxCliente;
    len=ll_len(pArrayVentas);
    for(i=0;i<len;i++)
    {
        if(pArrayVentas!=NULL &&
           pArrayClientes!=NULL)
		{
			pAux=ll_get(pArrayVentas,i);
			venta_getIdCliente(pAux,&bufferIdCliente);
			if(!cliente_getCliById(pArrayClientes,bufferIdCliente,&indice))
			{
			    pAuxCliente=ll_get(pArrayClientes,indice);
			    if( !venta_getId(pAux,&bufferId) &&
                    !cliente_getNombre(pAuxCliente,bufferNombreCli) &&
                    !cliente_getApellido(pAuxCliente,bufferApellidoCli) &&
                    !cliente_getDni(pAuxCliente,bufferDniCli) &&
                    !venta_getCodigoProducto(pAux,bufferCodProducto) &&
                    !venta_getCantidad(pAux,&bufferCantidad) &&
                    !venta_getPrecioUnidad(pAux,&bufferPrecioUnidad))
                {
                    printf("\n%d %s %s %s %s %.2f", bufferId,
                                                    bufferNombreCli,
                                                    bufferApellidoCli,
                                                    bufferDniCli,
                                                    bufferCodProducto,
                                                    bufferCantidad*bufferPrecioUnidad);
                    retorno=0;
                }
			}

		}
    }
    printf("\n\nCantidad de Ventas: %d\n",len);
    return retorno;
}

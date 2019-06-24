#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Cliente.h"
#include "parser.h"
#include "utn.h"

int main()
{
    int option = 0;
    LinkedList* listaClientes = ll_newLinkedList();
    LinkedList* listaVentas=ll_newLinkedList();
    controller_loadFromText("clientes.csv",listaClientes);
    controller_ventasLoadFromText("ventas.csv",listaVentas);
    do{
        printf("\n-----------------------------------------------");
        printf("\n1.Alta de Cliente");
        printf("\n2.Modificacion de cliente");
        printf("\n3.Baja de cliente");
        printf("\n4.Listar clientes");
        printf("\n5.Realizar venta");
        printf("\n6.Anular venta");
        printf("\n7.Informar ventas");
        printf("\n8.Informar ventas por producto");
        printf("\n9.Generar informe de ventas");
        printf("\n10.informar cantidad de ventas por cliente");
        printf("\n11.Salir");

        if(!utn_getInt("\nOpcion:","\nOpcion no valida",1,11,2,&option))
        {
			switch(option)
			{
				case 1:
				{
					printf("\nAlta de Cliente");
					if(!controller_addCliente(listaClientes))
                    {
                        printf("\nAgregado con exito");
                        controller_saveClientesAsText("clientes.csv",listaClientes);
                        break;
                    }
                    else
                    {
                        printf("\nError al agregar");
                    }
					break;
				}
				case 2:
				{
					printf("\nModificacion de cliente");
					if(!controller_editCliente(listaClientes))
                    {
                        printf("\nModificado con exito");
                        controller_saveClientesAsText("clientes.csv",listaClientes);
                        break;
                    }
                    else
                    {
                        printf("\nError al modificar");
                    }
					break;
				}
				case 3:
				{
                    printf("\nBaja de cliente");
                    if(!controller_removeCliente(listaClientes,listaVentas))
					{
						printf("\nEmpleado eliminado con exito");
						controller_saveClientesAsText("clientes.csv",listaClientes);
						break;
					}
					else
					{
						printf("\nError al eliminar cliente, tiene una venta o no existe");
					}
					break;
				}
				case 4:
				{
					printf("\nListar clientes");
					if(!controller_ListCliente(listaClientes))
					{
						break;
					}
					else
					{
						printf("\nError al listar");
					}
					break;
				}
				case 5:
				{
                    printf("\nRealizar una venta");
                    if(!controller_addVenta(listaVentas,listaClientes))
                    {
                        printf("\nVenta realizada con exito");
                        controller_saveVentasAsText("ventas.csv",listaVentas);
                        break;
                    }
                    else
                    {
                        printf("\nError al realizar venta");
                    }
					break;
				}
				case 6:
				{
                    printf("\nAnular venta");
                    if(!controller_removeVenta(listaVentas))
                    {
						printf("\nVenta eliminada con exito");
						controller_saveVentasAsText("ventas.csv",listaVentas);
						break;
                    }
					else
					{
						printf("\nError al eliminar venta");
					}
					break;
				}
				case 7:
				{
                    printf("\nInformar ventas");
                    if(!controller_ListVentas(listaVentas,listaClientes))
                    {
						printf("\nListados con exito");
						break;
                    }
					else
					{
						printf("\nError al listar");
					}
					break;
				}
				case 8:
				{
                    printf("\nInformar ventas por productos");
                    if(!controller_ListVentasByProducto(listaVentas,listaClientes))
                    {
						printf("\nListados con exito");
						break;
                    }
					else
					{
						printf("\nError al listar");
					}
					break;
				}
				case 9:
				{
                    printf("\nGenerar informe de ventas");
                    if(!controller_SaveInformeVentas("informe.txt",listaVentas,listaClientes))
                    {
                        printf("\nGenerado con exito");
                        break;
                    }
                    else
                    {
                        printf("\nError al generar informe");
                    }
					break;
				}
			}
        }
    }while(option != 11);
    return 0;
}

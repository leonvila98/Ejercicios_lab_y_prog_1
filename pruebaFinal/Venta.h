#ifndef VENTA_H_INCLUDED
#define VENTA_H_INCLUDED
typedef struct
{
    int id;
    int idCliente;
    char codigoProducto[5];
    int cantidad;
    float precioUnidad;
}Venta;

Venta* venta_new(void);
Venta* venta_newParametros(char* idStr,char* idClienteStr,char* codigoProductoStr,char* cantidadStr,char* precioUnidad);
int venta_newByStruct(LinkedList* lista,Venta emp);
void venta_delete(Venta* this);

int venta_setId(Venta* this,int id);
int venta_getId(Venta* this,int* id);

int venta_setIdStr(Venta* this, char* id);
int venta_getIdStr(Venta* this, char* id);

int venta_setIdCliente(Venta* this,int idCliente);
int venta_getIdCliente(Venta* this,int* idCliente);

int venta_setCodigoProducto(Venta* this,char* codigoProducto);
int venta_getCodigoProducto(Venta* this,char* codigoProducto);

int venta_setCantidad(Venta* this,int cantidad);
int venta_getCantidad(Venta* this,int* cantidad);

int venta_setPrecioUnidad(Venta* this,float precioUnidad);
int venta_getPrecioUnidad(Venta* this,float* precioUnidad);

int venta_setPrecioUnidadStr(Venta* this, char* precioUnidad);
int venta_getPrecioUnidadStr(Venta* this, char* precioUnidad);

int venta_setCodigoProductoStr(Venta* this, char* codigoProducto);
int venta_getCodigoProductoStr(Venta* this, char* codigoProducto);

int venta_setIdClienteStr(Venta* this, char* idCliente);
int venta_getIdClienteStr(Venta* this, char* idCliente);

int venta_setCantidadStr(Venta* this, char* cantidad);
int venta_getCantidadStr(Venta* this, char* cantidad);



int venta_getIdMax(LinkedList* pArray);

int venta_getVenById(LinkedList* pArray,int id,int* indice);
int venta_getCliById(LinkedList* pArray,int idCliente);

int venta_compararPorNombre(void* this1,void* this2);
int venta_calcularNumeroIntDos(Venta* this);


#endif // VENTA_H_INCLUDED



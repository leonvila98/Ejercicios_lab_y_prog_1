#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED
typedef struct
{
    int id;
    char nombre[128];
    char apellido[128];
    char dni[9];
}Cliente;

Cliente* cliente_new(void);
Cliente* cliente_newParametros(char* idStr,char* nombreStr,char* numeroIntStr,char* numeroIntDosStr);
int cliente_newByStruct(LinkedList* lista,Cliente emp);
void cliente_delete(Cliente* this);

int cliente_setId(Cliente* this,int id);
int cliente_getId(Cliente* this,int* id);

int cliente_setIdStr(Cliente* this, char* id);
int cliente_getIdStr(Cliente* this, char* id);

int cliente_setNombre(Cliente* this,char* nombre);
int cliente_getNombre(Cliente* this,char* nombre);

int cliente_setApellido(Cliente* this,char* apellido);
int cliente_getApellido(Cliente* this,char* apellido);

int cliente_setNumeroInt(Cliente* this,int numeroInt);
int cliente_getNumeroInt(Cliente* this,int* numeroInt);

int cliente_setNumeroIntStr(Cliente* this, char* numeroInt);
int cliente_getNumeroIntStr(Cliente* this, char* numeroInt);

int cliente_setNumeroIntDos(Cliente* this,int numeroIntDos);
int cliente_getNumeroIntDos(Cliente* this,int* numeroIntDos);

int cliente_setNumeroIntDosStr(Cliente* this, char* numeroIntDos);
int cliente_getNumeroIntDosStr(Cliente* this, char* numeroIntDos);

int cliente_setEstado(Cliente* this,int estado);
int cliente_getEstado(Cliente* this,int* estado);

int cliente_getIdMax(LinkedList* pArray);

int cliente_getEmpById(LinkedList* pArray,int id,int* indice);

int cliente_compararPorNombre(void* this1,void* this2);
int cliente_calcularNumeroIntDos(Cliente* this);


#endif // CLIENTE_H_INCLUDED

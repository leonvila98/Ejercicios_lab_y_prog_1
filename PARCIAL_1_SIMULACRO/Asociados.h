
typedef struct
{
    int idAsociado;
    int estado;//0-deshabilitado 1-habilitado 2-empty
    char dni[20];
    char nombre[50];
    char apellido[50];
    int edad;
}Asociado;

int aso_printAsociado(Asociado *auxAsociado,int limite);
int aso_estado(Asociado *auxAsociado,int limite,int *indice);
int aso_initAsociado(Asociado *auxAsociado,int limite);
int aso_altaAsociado(Asociado *auxAsociado,int limite,int *indice);
int aso_findById(Asociado *auxAsociado, int limite, int id,int *resultado);
int aso_modificar(Asociado *auxAsociado,int limite);
int aso_modificarEstado(Asociado *auxAsociado,int limite);
int aso_printUnAsociado(Asociado *auxAsociado,int limite,int id);

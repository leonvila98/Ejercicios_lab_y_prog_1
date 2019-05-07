typedef struct
{
    int idLlamada;
    int estado;//0-pendiente 1-cumplida 2-empty
    int motivo;//0-infarto 1-ACV 2-gripe
    int tiempo;
    int idAsociado;
    int idAmbulancia;
}Llamadas;

int lla_printLlamada(Llamadas *auxLlamada,int limite);
int lla_initLlamada(Llamadas *auxLlamada,int limite);
int lla_altaLlamada(Llamadas *auxLlamada,int limite,int *indice);
int lla_findById(Llamadas *auxLlamada,int limite,int id,int *resultado);
int lla_modificarLlamada(Llamadas *auxLlamada,int limite,int *indiceLlamada);
int lla_asoMasLlamados(Llamadas *auxLlamada,Asociado *auxAsociado,int limite,int limiteAso);

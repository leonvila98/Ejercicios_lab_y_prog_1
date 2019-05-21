#ifndef INFORMES_H_INCLUDED
#define INFORMES_H_INCLUDED


int Informes_listarPorCriterio(Tipo arrayA, Tipo arrayB, int sizeI, int sizeJ, char* criterio);
int Informes_listarCriterioContadorAcumulado(Tipo arrayA, Tipo arrayB, int sizeI, int sizeJ);
int Informes_maxContadorAcumulado(Tipo arrayA, Tipo arrayB, int sizeI, int sizeJ);
int Informes_listarSociosPorLibro(Socio *arraySocios,Libro *arrayLibros,Prestamo *arrayPrestamos,int sizeSoc,int sizeLib,int sizePre);



#endif // INFORMES_H_INCLUDED

#ifndef LICENCIASARCHIVO_H_INCLUDED
#define LICENCIASARCHIVO_H_INCLUDED
#include "Licencias.h"

class LicenciasArchivo{
public:
    // FUNCIONES ARCHIVOS
    FILE *abrirArchivoL();
    Licencias leer(int nroRegistro);
    bool leer(Licencias &licencias, int nroRegistro);
    bool leerTodos(Licencias licencias[], int cantidad);
    bool guardar(Licencias licencias);
    bool guardar(Licencias licencias, int nroRegistro);
    int getCantidad();
    int buscar(int);

    void mostrarArchivo();
};

#endif // LICENCIASARCHIVO_H_INCLUDED

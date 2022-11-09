#pragma once
#include <iostream>
using namespace std;
#include "Rotacion.h"

class RotacionArchivo
{
public:
    // FUNCIONES ARCHIVOS
    Rotacion leer(int nroRegistro);
    bool leer(Rotacion &rotacion, int nroRegistro);
    bool leerTodos(Rotacion rotacion[], int cantidad);
    bool guardar(Rotacion rotacion);
    bool guardar(Rotacion rotacion, int nroRegistro);
    int getCantidad();
    FILE *abrirArchivoRB();

};

#pragma once
#include <iostream>
using namespace std;
#include "Rotacion.h"
#include "EnumArchivos.h"

class RotacionArchivo
{
private:
    FILE *pFile;
    int tamanioRegistro;
    void *pRegistro;
    char *nombreArchivo;
    int cantRegistros;
    int estado;
    int cantidadRegistros();
    bool abrirArchivo(Modo modo);
    void cerrarArchivo();

public:
    RotacionArchivo();
    ~RotacionArchivo();
    // FUNCIONES ARCHIVOS
    Rotacion leer(int nroRegistro);
    bool leer(Rotacion &rotacion, int nroRegistro);
    bool leerTodos(Rotacion rotacion[], int cantidad);
    bool guardar(Rotacion rotacion);
    bool guardar(Rotacion rotacion, int nroRegistro);
    int getCantidadRegistros();
    // bool exportar();
};

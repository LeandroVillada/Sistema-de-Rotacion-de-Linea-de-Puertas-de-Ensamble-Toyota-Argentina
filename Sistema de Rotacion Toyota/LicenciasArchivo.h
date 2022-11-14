#pragma once
#include "EnumArchivos.h"
#include "Licencias.h"

class LicenciasArchivo
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
    LicenciasArchivo();
    ~LicenciasArchivo();
    // FUNCIONES ARCHIVOS
    FILE *abrirArchivoL();
    Licencias leer(int nroRegistro);
    bool leer(Licencias &licencias, int nroRegistro);
    bool leerTodos(Licencias licencias[], int cantidad);
    bool guardar(Licencias licencias);
    bool guardar(Licencias licencias, int nroRegistro);
    int getCantidadRegistros();
    int buscarPorLegajo(int);

    void mostrarArchivo();
};
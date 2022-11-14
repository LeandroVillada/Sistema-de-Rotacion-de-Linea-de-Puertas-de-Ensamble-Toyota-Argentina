#pragma once
#include "HorasTrabajadas.h"
#include "EnumArchivos.h"

class HorasTrabajadasArchivo
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
    HorasTrabajadasArchivo();
    ~HorasTrabajadasArchivo();
    // FUNCIONES ARCHIVOS
    HorasTrabajadas leer(int nroRegistro);
    bool leer(HorasTrabajadas &horasTrabajadas, int nroRegistro);
    bool leerTodos(HorasTrabajadas horasTrabajadas[], int cantidad);
    bool guardar(HorasTrabajadas horasTrabajadas);
    bool guardar(HorasTrabajadas horasTrabajadas, int nroRegistro);
    int getCantidadRegistros();
    int buscarPorLegajo(int);
    // void mostrar(HorasTrabajadas);

    void mostrarArchivo();

    // FUNCIONES PUBLICAS
    bool cargar();
    void mostrar();
};
#pragma once
#include <iostream>
#include "Empleados.h"
using namespace std;

///////////////////////////
// TIPOS ENUMERADOS PARA USAR CON LA CLASE ARCHIVO
enum Estado
{ // DEFINE LOS ESTADOS EN LOS QUE PUEDE ESTAR EL ARCHIVO
    NoExiste,
    Cerrado,
    AbiertoR,
    AbiertoW,
    AbiertoA,
    AbiertoRW
};

enum Modo
{ // DEFINE LOS MODOS DE APERTURA DE UN ARCHIVO
    SoloLectura,
    Escritura,
    Agregar,
    LecturaEscritura
};

class EmpleadosArchivo
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
    EmpleadosArchivo();
    ~EmpleadosArchivo();
    // FUNCIONES ARCHIVOS
    Empleados leer(int nroRegistro);
    bool leer(Empleados &empleado, int nroRegistro);
    bool leerTodos(Empleados empleados[], int cantidad);
    bool guardar(Empleados empleado);
    bool guardar(Empleados empleado, int nroRegistro);
    int getCantidadRegistros();
    // FILE *abrirArchivoRB();

    int buscarPosicionEmpleadoPorLegajo(int);
    Empleados buscarEmpleadoPorLegajo(int);
    int BuscarPor(std::string);
    // FUNCIONES INCOMPLETAS
    bool bajaLogica();
    bool modificar();
    //
    void mostrar(Empleados);

    void mostrarArchivo();

    // FUNCIONES PUBLICAS
    bool buscarLegajoExistente(int);
    bool LegajoDisponible(int);
    bool buscarLegajoInactivo(int);
};

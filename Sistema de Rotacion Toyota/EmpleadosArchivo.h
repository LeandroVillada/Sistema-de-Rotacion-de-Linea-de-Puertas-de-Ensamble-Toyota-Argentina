#pragma once
#include <iostream>
#include "Empleados.h"
using namespace std;
class EmpleadosArchivo
{
public:
    // FUNCIONES ARCHIVOS
    Empleados leer(int nroRegistro);
    bool leer(Empleados &empleado, int nroRegistro);
    bool leerTodos(Empleados empleados[], int cantidad);
    bool guardar(Empleados empleado);
    bool guardar(Empleados empleado, int nroRegistro);
    int getCantidad();
    FILE *abrirArchivoRB();

    int buscarPosicionEmpleadoPorLegajo(int);
    Empleados buscarEmpleadoPorLegajo(int);
    int BuscarPor(std::string);
    bool bajaLogica();
    bool modificar();

    void mostrar(Empleados);

    void mostrarArchivo();

    // FUNCIONES PUBLICAS
    bool buscarLegajoExistente(int);
    bool LegajoDisponible(int);
    bool cargar();
    void mostrar();
    bool buscarLegajoInactivo(int);
};

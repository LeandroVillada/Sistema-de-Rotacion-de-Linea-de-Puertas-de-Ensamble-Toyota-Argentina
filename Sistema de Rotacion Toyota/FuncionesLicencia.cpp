#include <iostream>
#include "FuncionesLicencia.h"
#include "Empleados.h"
#include "EmpleadosArchivo.h"

using namespace std;

void agregarRegistrosLicencia()
{
    EmpleadosArchivo archivo;
    LicenciasArchivo archivoL;
    Licencias licencia;

    int _legajo;
    Fecha fechaInicioLicencia;
    Fecha fechaFinLicencia;
    cout << "Legajo: ";
    cin >> _legajo;
    if (archivo.buscarLegajoExistente(_legajo) == true)
    {

        licencia.setLegajo(_legajo);

        cout << "Inicio Licencia: " << endl;
        cin >> fechaInicioLicencia;
        licencia.setFechaInicioLicencia(fechaInicioLicencia);

        cout << "Fin Licencia: " << endl;
        cin >> fechaFinLicencia;
        licencia.setFechaFinLicencia(fechaFinLicencia);

        cout << endl;

        if (!archivoL.guardar(licencia))
        {
            cout << "No se pudo Grabar en Disco" << endl;
            return;
        }
    }
    else
    {
        cout << "El legajo ingresado no existe" << endl;
        system("pause");
    }
}

void mostrarRegistrosLicencia()
{
    LicenciasArchivo archivoL;
    int cant = archivoL.getCantidadRegistros();
    Licencias *licencias = new Licencias[cant];
    if (licencias == NULL)
    {
        return;
    }
    if (!archivoL.leerTodos(licencias, cant))
    {
        return;
    }
    for (int i = 0; i < cant; i++)
    {
        licencias[i].Mostrar();
    }
}

void InicioLicencia(int legajo)
{
    Empleados reg;
    EmpleadosArchivo archivo;

    // Aqui comprobamos si el legajo ingresado no existe.

    if (!archivo.LegajoDisponible(legajo))
    {
        std::cout << "El legajo ya se encuentra en licencia." << std::endl;
        return;
    }

    // La variable "pos" guarda la posicion donde se encuentra el registro del legajo ingresado.
    int pos = archivo.buscarPosicionEmpleadoPorLegajo(legajo);
    // Leemos el registro en la posicion de la variable pos para obtener el registro.
    if (!archivo.leer(reg, pos))
    {
        return;
    }
    // Cambiamos el valor del estado del registro
    reg.setDisponibilidad(false);
    // Grabamos en el registro el cambio que realizamos mandando la posicion correspondiente del registro a editar.
    if (!archivo.guardar(reg, pos))
    {
        cout << "No se pudo Grabar en Disco" << endl;
        return;
    }
    std::cout << "Se regristro la licencia del legajo." << std::endl;
}

void FinLicencia(int legajo)
{
    EmpleadosArchivo archivo;
    Empleados reg;

    // Aqui comprobamos si el legajo ingresado no existe.

    if (archivo.LegajoDisponible(legajo))
    {
        std::cout << "El legajo ya finalizo la licencia." << std::endl;
        return;
    }

    // La variable "pos" guarda la posicion donde se encuentra el registro del legajo ingresado.
    int pos = archivo.buscarPosicionEmpleadoPorLegajo(legajo);
    // Leemos el registro en la posicion de la variable pos para obtener el registro.
    if (!archivo.leer(reg, pos))
    {
        return;
    }
    // Cambiamos el valor del estado del registro
    reg.setDisponibilidad(true);
    // Grabamos en el registro el cambio que realizamos mandando la posicion correspondiente del registro a editar.
    if (!archivo.guardar(reg, pos))
    {
        cout << "No se pudo Grabar en Disco" << endl;
        return;
    }
    std::cout << "Se finalizo la licencia del legajo." << std::endl;
}

void mostrarLicenciasRegistrosPorLegajo(int legajo)
{
    LicenciasArchivo archivoL;
    int cant = archivoL.getCantidadRegistros();
    Licencias *licencias = new Licencias[cant];
    if (licencias == NULL)
    {
        return;
    }
    if (!archivoL.leerTodos(licencias, cant))
    {
        return;
    }
    for (int i = 0; i < cant; i++)
    {
        if (licencias[i].getLegajo() == legajo)
        {
            licencias[i].Mostrar();
        }
    }
}

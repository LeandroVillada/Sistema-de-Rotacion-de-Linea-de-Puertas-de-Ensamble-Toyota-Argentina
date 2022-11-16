#include <iostream>
#include "FuncionesLicencia.h"
#include "Empleados.h"
#include "EmpleadosArchivo.h"
#include "Funciones Globales.h"

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

void comprobarInicioLicencias()
{
    LicenciasArchivo archivoLicencias;
    EmpleadosArchivo archivoEmpleados;
    int CantRegEmpleados = archivoEmpleados.getCantidadRegistros();
    Empleados *empleados = new Empleados[CantRegEmpleados];
    if (empleados == NULL)
    {
        return;
    }
    if (!archivoEmpleados.leerTodos(empleados, CantRegEmpleados))
    {
        return;
    }

    Fecha fechaActual;
    mostrarMensaje("Inicio Licencia:", 15, 5);
    cout<<endl<<endl;
    for (int i = 0; i < CantRegEmpleados; i++)
    {
        int pos = archivoLicencias.BuscarUltimoRegistroLegajo(empleados[i].getLegajo());
        if ((pos > -1) && (empleados[i].getDisponibilidad()))
        {
            if (archivoLicencias.leer(pos).getFechaInicioLicencia() < fechaActual && archivoLicencias.leer(pos).getFechaFinLicencia() > fechaActual)
            {
                empleados[i].setDisponibilidad(false);
                cout<<empleados[i]<<endl;
                if (!archivoEmpleados.guardar(empleados[i], i))
                {
                    cout << "No se pudo grabar en disco." << endl;
                    return;
                }
            }
        }
    }
    cout<<endl;
    mostrarMensaje("Fin comprobacion de inicio de licencias", 15, 5);
}

void comprobarExpiracionLicencias()
{
    LicenciasArchivo archivoLicencias;
    EmpleadosArchivo archivoEmpleados;
    int CantRegEmpleados = archivoEmpleados.getCantidadRegistros();
    Empleados *empleados = new Empleados[CantRegEmpleados];
    if (empleados == NULL)
    {
        return;
    }
    if (!archivoEmpleados.leerTodos(empleados, CantRegEmpleados))
    {
        return;
    }

    Fecha fechaActual;

    mostrarMensaje("Fin Licencia:", 15, 5);
    cout<<endl<<endl;
    for (int i = 0; i < CantRegEmpleados; i++)
    {
        int pos = archivoLicencias.BuscarUltimoRegistroLegajo(empleados[i].getLegajo());
        if ((pos > -1) && (!empleados[i].getDisponibilidad()))
        {
            if (archivoLicencias.leer(pos).getFechaFinLicencia() < fechaActual && archivoLicencias.leer(pos).getFechaInicioLicencia() < fechaActual)
            {
                empleados[i].setDisponibilidad(true);
                cout<<empleados[i]<<endl;
                if (!archivoEmpleados.guardar(empleados[i], i))
                {
                    cout << "No se pudo grabar en disco." << endl;
                    return;
                }
            }
        }
    }
    cout<<endl;
    mostrarMensaje("Fin comprobacion de expiracion de licencias", 15, 5);

}

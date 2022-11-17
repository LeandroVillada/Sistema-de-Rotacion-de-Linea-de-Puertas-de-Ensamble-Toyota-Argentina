#include <iostream>
#include "FuncionesLicencia.h"
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

void encabezadoComprobarLicencias()
{
    Fecha fechaActual;
    // ENCABEZADO
    gotoxy(37, 2);
    mostrarMensaje("OPERARIOS CON LICENCIAS", 15, rlutil::COLOR::BLUE);
    gotoxy(13, 3);
    mostrarMensaje("Activas", 15, rlutil::COLOR::GREEN);
    gotoxy(75, 3);
    mostrarMensaje("Expiradas en " + fechaActual.toStringMes(fechaActual.getMes()), 15, rlutil::COLOR::DARKGREY);
    gotoxy(1, 4);
    cout << "---------------------------------------------------------------------------------------------------" << endl;
    // ACTIVOS
    gotoxy(2, 5);
    cout << "LEGAJO";
    gotoxy(12, 5);
    cout << "APELLIDO";
    gotoxy(30, 5);
    cout << "HASTA";
    // EXPIRADOS
    gotoxy(75, 5);
    cout << "LEGAJO";
    gotoxy(87, 5);
    cout << "APELLIDO";
    gotoxy(1, 6);
    cout << "---------------------------------------------------------------------------------------------------" << endl;
}

void comprobarLicencias()
{
    LicenciasArchivo archivoLicencias;
    Licencias licencia;
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
    encabezadoComprobarLicencias();
    int ContadorActivos = 0, contadorExpirados = 0;

    for (int i = 0; i < CantRegEmpleados; i++)
    {
        int pos = archivoLicencias.BuscarUltimoRegistroLegajo(empleados[i].getLegajo());
        if (pos > -1)
        {
            if (!archivoLicencias.leer(licencia, pos))
            {
                return;
            }
            // if ((licencia.getFechaFinLicencia() < fechaActual) && (!empleados[i].getDisponibilidad()))
            if (licencia.getFechaFinLicencia() < fechaActual)
            {
                // Mestra las licencias expiradas en el mes actual
                if ((empleados[i].getDisponibilidad()) && (licencia.getFechaFinLicencia().getMes() == fechaActual.getMes()))
                {
                    gotoxy(75, 7 + contadorExpirados);
                    cout << empleados[i].getLegajo();
                    gotoxy(87, 7 + contadorExpirados);
                    cout << empleados[i].getApellido();
                }
                else if (!empleados[i].getDisponibilidad())
                {
                    empleados[i].setDisponibilidad(true);
                    if (!archivoEmpleados.guardar(empleados[i], i))
                    {
                        cout << "No se pudo grabar en disco." << endl;
                        return;
                    }

                    gotoxy(75, 7 + contadorExpirados);
                    cout << empleados[i].getLegajo();
                    gotoxy(87, 7 + contadorExpirados);
                    cout << empleados[i].getApellido();
                }
                contadorExpirados++;
            }
            else if ((licencia.getFechaInicioLicencia() <= fechaActual) && (licencia.getFechaFinLicencia() >= fechaActual))
            {
                if (empleados[i].getDisponibilidad())
                {
                    empleados[i].setDisponibilidad(false);
                    if (!archivoEmpleados.guardar(empleados[i], i))
                    {
                        cout << "No se pudo grabar en disco." << endl;
                        return;
                    }
                }

                gotoxy(2, 7 + ContadorActivos);
                cout << empleados[i].getLegajo();
                gotoxy(12, 7 + ContadorActivos);
                cout << empleados[i].getApellido();
                gotoxy(30, 7 + ContadorActivos);
                cout << licencia.getFechaFinLicencia().toString();
                ContadorActivos++;
            }
        }
    }
}

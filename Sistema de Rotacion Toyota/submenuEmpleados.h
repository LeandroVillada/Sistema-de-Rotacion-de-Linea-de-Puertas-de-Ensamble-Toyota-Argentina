#ifndef SUBMENUEMPLEADOS_H_INCLUDED
#define SUBMENUEMPLEADOS_H_INCLUDED

#include "menuEdicionEmpleados.h"

void submenuEmpleados()
{
    int opc;
    while (true)
    {
        system("cls");

        cout << "SUBMENU EMPLEADOS" << endl;
        cout << "\n\t1. Cargar Empleado" << endl;
        cout << "\t2. Editar Datos de Empleado." << endl;
        //Funcion de prueba
        cout << "\t3. Mostrar Empleados Disponibles." << endl;
        cout << "\t4. Mostrar Empleados Inactivos." << endl;

        //Creacion de operario nuevo
        cout << "\t5. Crear Archivo Nuevo de Empleados" << endl;

        //cout << "\t5. Cambiar disponibilidad de Empleado" << endl;
        cout << "\t0. Volver al Menu Principal." << endl;
        cout << "\nSELECCIONE UNA OPCION:  ";
        cin >> opc;
        system("cls");
        switch (opc)
        {
        case 1:
            cargarEmpleado();
            system("pause>nul");
            break;
        case 2:
            menuEmpleadosEdicion();
            break;
        case 3:
            mostrarEmpleados();
            system("pause>nul");
            break;
        case 4:
            mostrarEmpleadosInactivo();
            system("pause>nul");
            break;
        case 5:
            crearArchivoEmpleadoNuevo();
            system("pause>nul");
            break;
        case 0:
            return;
        default:
            cout << "OPCION INGRESADA INCORRECTA.";
            system("pause>nul");
            break;
        }
    }
}

#endif // SUBMENUEMPLEADOS_H_INCLUDED

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
        cout << "\t2. Cargar Habilidades del Empleado." << endl;
        cout << "\t3. Editar Datos de los Empleados." << endl;
        cout << "\t4. Mostrar Empleados." << endl;
        cout << "\t5. Mostrar Empleados Inactivos." << endl;
        cout << "\t6. Crear Archivo Nuevo de Empleados" << endl;
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
            cargarHabilidadesEmpleado();
            system("pause>nul");
            break;
        case 3:
            menuEmpleadosEdicion();
            break;
        case 4:
            mostrarEmpleados();
            system("pause>nul");
            break;
        case 5:
            mostrarEmpleadosInactivo();
            system("pause>nul");
            break;
        case 6:
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

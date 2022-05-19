#ifndef MENUEDICIONEMPLEADOS_H_INCLUDED
#define MENUEDICIONEMPLEADOS_H_INCLUDED

#include "funcionEditarEmpleados.h"

void menuEmpleadosEdicion()
{
    int opc;
    while (true)
    {
        system("cls");
        cout << "MENU EDICCION DE EMPLEADOS" << endl;
        cout << "\n\t1. Dar de Baja un Legajo." << endl;
        cout << "\n\t2. Dar de Alta un Legajo." << endl;
        cout << "\n\t3. Editar Nombre." << endl;
        cout << "\n\t4. Editar Apellido." << endl;
        cout << "\n\t0. Volver al Menu de Principal" << endl;
        cout << "\nSeleccione una opcion :  ";
        cin >> opc;
        system("cls");
        switch (opc)
        {
        case 1:
            darBajaLegajo();
            system("pause>nul");

            break;
        case 2:
            darAltaLegajo();
            system("pause>nul");

            break;
        case 3:
            editarNombreEmpleado();
            system("pause>nul");

            break;
        case 4:
            editarApellidoEmpleado();
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

#endif // MENUEDICIONEMPLEADOS_H_INCLUDED

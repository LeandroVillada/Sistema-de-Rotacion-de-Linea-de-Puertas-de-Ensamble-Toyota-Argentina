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
        cout << "\t2. Dar de Alta un Legajo." << endl;
        cout << "\t3. Editar Legajo." << endl;
        cout << "\t4. Editar Nombre." << endl;
        cout << "\t5. Editar Apellido." << endl;
        cout << "\t0. Volver al Menu de Empleados" << endl;
        cout << "\nSELECCIONE UNA OPCION:  ";
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
            editarLegajoEmpleado();
            system("pause>nul");
            break;
        case 4:
            editarNombreEmpleado();
            system("pause>nul");
        case 5:
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

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
        cout << "\n\t2. Cambiar Operario Trabajando." << endl;
        cout << "\n\t3. Agregar Operaciones Aprendidas." << endl;
        cout << "\n\t4. Eliminar Operaciones Aprendidas." << endl;
        cout << "\n\t5. Editar Nombre y apellido." << endl;
        cout << "\n\t0. Volver al Menu de Principal" << endl;
        cout << "\n\SELECCIONE UNA OPCION:  ";
        cin >> opc;
        system("cls");
        switch (opc)
        {
        case 1:
            darBajaLegajo();
            system("pause>nul");
            break;
        case 2:
            ///funcion modifique operario activo

            system("pause>nul");
            break;
        case 3:
            ///funcion agrege operaciones aprendidas
            system("pause>nul");
            break;
        case 4:
            ///funcion eliminar operaciones aprendidas
            system("pause>nul");
        case 5:
            ///funcion editar nombre y apellido
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

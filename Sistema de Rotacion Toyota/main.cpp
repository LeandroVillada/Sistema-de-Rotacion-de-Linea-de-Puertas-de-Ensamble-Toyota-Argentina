/// Autores: Villada Leandro, Barrios Marcos.

#include <iostream>
#include <cstring>
#include <ctime>
#include <cstdlib>
using namespace std;

#include "clases.h"
#include "funciones.h"
#include "submenuEmpleados.h"
#include "submenuEmpleados.h"
#include "submenuRotacion.h"
int main()
{
    // Variables
    int opc;

    // Desarrollo del Programa
    while (true)
    {
        system("color 6");
        system("cls");
        cout << "MENU PRINCIPAL" << endl;
        cout << "\t1. Cargar Operario nuevo." << endl;
        cout << "\n\t2. Modificar datos de Empleados." << endl;
        cout << "\t3. Modificar Disponibilid para Rotacion." << endl;
        cout << "\t4. Armar Rotacion." << endl;
        cout << "\t5. Guardar Rotacion." << endl;
        cout << "\t0. Salir del Programa" << endl;
        cout << "\nSELECCIONE UNA OPCION:  ";
        cin >> opc;
        system("cls");
        switch (opc)
        {

        case 1:
            submenuEmpleados();
            break;

        case 2:
            submenuRotation();
            break;

        case 0: // Fin del Programa
            return 0;
        default:
            cout << "OPCION INGRESADA INCORRECTA.";
            system("pause>nul");
            break;
        }
    }
}

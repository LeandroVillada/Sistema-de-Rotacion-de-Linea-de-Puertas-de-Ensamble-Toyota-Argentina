/// Autores: Villada Leandro, Barrios Marcos.

#include <iostream>
#include <cstring>
#include <ctime>
#include <cstdlib>
using namespace std;

#include "clases.h"
#include "funciones.h"
#include "submenuEmpleados.h"

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
        cout << "\n\t1. Menu de Empleados." << endl;
        cout << "\t0. Salir del Programa" << endl;
        cout << "\nSELECCIONE UNA OPCION:  ";
        cin >> opc;
        system("cls");
        switch (opc)
        {
        case 1:
            submenuEmpleados();
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

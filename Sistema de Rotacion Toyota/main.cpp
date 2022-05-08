/// Autores: Villada Leandro, Barrios Marcos.

#include <iostream>
#include <cstring>
#include <ctime>
#include <cstdlib>
using namespace std;

#include "Empleados.h"
#include "funciones.h"
#include "menuNuevoOperario.h"
#include "submenuRotacion.h"
#include "menuEdicionEmpleados.h"
#include "menuDisponibilidad.h"

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
        cout << "\n\t1. Cargar Operario nuevo." << endl;
        cout << "\n\t2. Modificar datos de Empleados." << endl;
        cout << "\n\t3. Modificar Disponibilid para Rotacion." << endl;
        cout << "\n\t4. Armar Rotacion." << endl; ///armar archivo con menu
        cout << "\n\t0. Salir del Programa" << endl;
        cout << "\n\tSELECCIONE UNA OPCION:  ";
        cin >> opc;
        system("cls");
        switch (opc)
        {
        case 1:
            ///menu para cargar un nuevo legajo
            cargarNuevo();
            break;

        case 2:
            ///menu con las opciones de edicion de legajos
            menuEmpleadosEdicion();

            break;
        case 3:
            ///menu que arma la lista con los disponibles para armar una rotacion
            modidicarDisponibilidadRotacion();

            break;
        case 4:
            ///menu armar rotacion
            submenuRotation();
            break;

        case 0:
            return 0;
        default:
            cout << "OPCION INGRESADA INCORRECTA.";
            system("pause>nul");
            break;
        }
    }
}

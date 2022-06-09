/// Autores: Villada Leandro, Barrios Marcos.

#include <iostream>
using namespace std;

#include "submenus.h"
#include "Empleados.h"

int main()
{
    Empleados aux;
    int pos = aux.buscarPosicionLegajo(22);
    cout << pos << endl;
    aux.leerDeDisco(pos);
    cout << aux.getApellido() << endl;
    system("pause");

    // Variables
    int opciones;

    // Desarrollo del Programa
    while (true)
    {
        system("color 6");
        system("cls");
        cout << "MENU PRINCIPAL" << endl;
        cout << "\n\t1. Cargar Operario nuevo." << endl;
        cout << "\n\t2. Modificar datos de Empleados." << endl;
        cout << "\n\t3. Modificar Disponibilidad para Rotacion." << endl;
        cout << "\n\t4. Armar Rotacion." << endl; /// armar archivo con menu
        cout << "\n\t0. Salir del Programa" << endl;
        cout << "\n\tSELECCIONE UNA OPCION:  ";
        cin >> opciones;
        system("cls");
        switch (opciones)
        {
        case 1:
            /// menu para cargar un nuevo legajo
            cargarNuevo();
            break;
        case 2:
            /// menu con las opciones de edicion de legajos
            menuEmpleadosEdicion();
            break;
        case 3:
            /// menu que arma la lista con los disponibles para armar una rotacion
            subMenuDisponibilidad();
            break;
        case 4:
            /// menu armar rotacion
            submenuRotation();
            break;
        case 5:
            /// menu armar rotacion
            cargarDatosDeInicio();
            system("pause>nul");
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

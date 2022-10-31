#include <iostream>
using namespace std;

#include "submenus.h"
#include "Empleados.h"
#include "MenuHorasTrabajadas.h"

int main()
{
    // Variables
    int opciones;

    // Desarrollo del Programa
    while (true)
    {
        system("color 3");
        system("cls");
        cout << "\t\t\tMENU PRINCIPAL" << endl;
        cout << "\n\t1. Cargar Operario nuevo" << endl;
        cout << "\n\t2. Modificar datos de Empleados" << endl;
        cout << "\n\t3. Modificar Disponibilidad para Rotacion" << endl;
        cout << "\n\t4. Armar Rotacion" << endl; /// armar archivo con menu
        cout << "\n\t5. Horas Trabajadas" << endl;
        cout << "\n\t0. Salir del Programa" << endl<<endl;
        cout << "\nSELECCIONE UNA OPCION:  ";
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
            /// menu horas trabajadas
            MenuHoraTrabajadas();
            break;
        case 6:
            //cargarDatosDeInicio();
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

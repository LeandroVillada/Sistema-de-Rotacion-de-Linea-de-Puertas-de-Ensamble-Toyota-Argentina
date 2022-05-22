#include "SubmenuRotacion.h"
void submenuRotation()
{
    int opciones;
    while (true)
    {
        system("color 6");
        system("cls");
        cout << "Armado de Rotacion" << endl;
        cout << endl;
        cout << "\n\t1. Agregar TM a Disponibles para rotar: " << endl;
        cout << "\t2. Eliminar TM de Disponibles para Rotar: " << endl;
        cout << "\t3. Mostrar Lista Completa de TM Disponibles para Rotacion: " << endl;
        cout << "\t4. Armar Rotacion Semanal: " << endl;
        cout << "\t0. Volver al Menu Principal." << endl;

        cout << "\nSeleccione una Opcion:  ";
        cin >> opciones;
        system("cls");

        switch (opciones)
        {

        case 1:
            // agregarDispTM ();
            cout << "funcion agregar tm disponibles" << endl;
            agregarEmpleadosDisponiblesParaRotar();
            system("pause>nul");
            break;

        case 2:
            // eliminarDispTM ();
            cout << "funcion eliminar tm faltantes" << endl;
            system("pause>nul");
            break;

        case 3:
            // mostrarTMDdisponibles ();
            cout << "funcion mostrar disponibles para rotacion" << endl;
            system("pause>nul");
            break;

        case 4:

            cout << "funcion armar rotacion" << endl;
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

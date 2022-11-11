#include "Licencias.h"
#include "EmpleadosArchivo.h"
#include "MenuLicencias.h"
#include "FuncionesLicencia.h"
using namespace std;

void MenuLicencias()
{
    Empleados aux;
    EmpleadosArchivo archivo;
    int legajo = 0;

    // Le damos el nombre que quieramos al objeto
    Menu MenuLicencias;
    // Agregamos el Titulo del menu
    MenuLicencias.setTitulo("MENU LICENCIAS");
    // Agregamos la Opcion para salir o volver al menu anterior
    MenuLicencias.setSalida("Volver al Menu de Principal ");

    // AGREGAMOS LAS OPCIONES CON UNA FUNCION
    // OPCION 1
    MenuLicencias.agregarOpcion("Agregar registro");
    // OPCION 2
    MenuLicencias.agregarOpcion("Mostrar registros (todos)");
    // OPCION 3
    MenuLicencias.agregarOpcion("Mostrar registros (por Legajo)");
    // OPCION 4
    MenuLicencias.agregarOpcion("Inicio Licencia (Legajo)");
    // OPCION 5
    MenuLicencias.agregarOpcion("Fin Licencia (Legajo)");


    // Aqui generamos un while en true en caso de que quieramos que dibuje nuevamente el menu
    while (true)
    {
        system("cls");
        // Elegimos el color del texto del menu y el Fondo del texto
        int opciones = MenuLicencias.dibujarMenu(rlutil::COLOR::WHITE, rlutil::COLOR::MAGENTA);
        system("cls");
        switch (opciones)
        {
        case 1:
            agregarRegistrosLicencia();

            break;
        case 2:
            mostrarRegistrosLicencia();

            system("pause>nul");
            break;
        case 3:

            cout << "Que legajo desea ver sus licencias (registros): ";
            cin >> legajo;
            if (archivo.buscarPosicionEmpleadoPorLegajo(legajo) != -1)
            {
                mostrarLicenciasRegistrosPorLegajo(legajo);
            }
            else
            {
                cout << "El legajo no existe!!";
            }

            system("pause>nul");
            break;
        case 4:

            cout << "Que legajo desea registrar el inicio de la licencia: ";
            cin >> legajo;
            if (archivo.buscarPosicionEmpleadoPorLegajo(legajo) != -1)
            {
                InicioLicencia(legajo);
            }
            else
            {
                cout << "El legajo no existe!!";
            }

            system("pause>nul");
            break;
        case 5:

            cout << "Que legajo desea registrar el inicio de la licencia: ";
            cin >> legajo;
            if (archivo.buscarPosicionEmpleadoPorLegajo(legajo) != -1)
            {
                FinLicencia(legajo);
            }
            else
            {
                cout << "El legajo no existe!!";
            }

            system("pause>nul");
            break;

        default:
            // VOLVER AL MENU ANTERIOR O SALIR
            return;
            break;
        }
    }
}

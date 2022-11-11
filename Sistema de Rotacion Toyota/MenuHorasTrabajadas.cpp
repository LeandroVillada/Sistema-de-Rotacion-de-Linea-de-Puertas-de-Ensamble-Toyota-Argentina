#include "HorasTrabajadas.h"
#include "EmpleadosArchivo.h"
#include "MenuHorasTrabajadas.h"
#include "FuncionesHorasTrabajadas.h"
using namespace std;

void MenuHoraTrabajadas()
{
    Empleados aux;
    EmpleadosArchivo archivo;
    int legajo = 0, anio = 0, mes = 0;

    // Le damos el nombre que quieramos al objeto
    Menu MenuHorasTrabajadas;
    // Agregamos el Titulo del menu
    MenuHorasTrabajadas.setTitulo("MENU HORAS TRABAJADAS");
    // Agregamos la Opcion para salir o volver al menu anterior
    MenuHorasTrabajadas.setSalida("Volver al Menu de Principal");

    // AGREGAMOS LAS OPCIONES CON UNA FUNCION
    // OPCION 1
    MenuHorasTrabajadas.agregarOpcion("Agregar registro");
    // OPCION 2
    MenuHorasTrabajadas.agregarOpcion("Mostrar registros (todos)");
    // OPCION 3
    MenuHorasTrabajadas.agregarOpcion("Mostrar registros (por Legajo)");
    // OPCION 4
    MenuHorasTrabajadas.agregarOpcion("Mostrar horas trabajadas (por Legajo)");
    // OPCION 5
    MenuHorasTrabajadas.agregarOpcion("Promedio general");
    // OPCION 6
    MenuHorasTrabajadas.agregarOpcion("Promedio total (por Legajo)");
    // OPCION 7
    MenuHorasTrabajadas.agregarOpcion("Promedio mensual (por Legajo)");
    // OPCION 8
    MenuHorasTrabajadas.agregarOpcion("Promedio anual (por Legajo)");

    // Aqui generamos un while en true en caso de que quieramos que dibuje nuevamente el menu
    while (true)
    {
        system("cls");
        // Elegimos el color del texto del menu y el Fondo del texto
        int opciones = MenuHorasTrabajadas.dibujarMenu(rlutil::COLOR::WHITE, rlutil::COLOR::GREY);
        system("cls");
        switch (opciones)
        {
        case 1:
            agregarRegistros();

            break;
        case 2:
            mostrarRegistros();

            system("pause>nul");
            break;
        case 3:

            cout << "Que legajo desea saber las horas trabajadas: ";
            cin >> legajo;
            if (archivo.buscarPosicionEmpleadoPorLegajo(legajo) != -1)
            {
                mostrarRegistrosPorLegajo(legajo);
            }
            else
            {
                cout << "El legajo no existe!!";
            }

            system("pause>nul");
            break;
        case 4:

            cout << "Que legajo desea saber las horas trabajadas: ";
            cin >> legajo;
            if (archivo.buscarPosicionEmpleadoPorLegajo(legajo) != -1)
            {
                sumaHorasPorLegajo(legajo);
            }
            else
            {
                cout << "El legajo no existe!!";
            }

            system("pause>nul");
            break;
        case 5:
            promedioGeneral();

            system("pause>nul");
            break;
        case 6:

            cout << "Que legajo desea saber las horas trabajadas: ";
            cin >> legajo;
            if (archivo.buscarPosicionEmpleadoPorLegajo(legajo) != -1)
            {
                promedioPorLegajo(legajo);
            }
            else
            {
                cout << "El legajo no existe!!";
            }

            system("pause>nul");
            break;
        case 7:

            cout << "Que legajo desea saber las horas trabajadas: ";
            cin >> legajo;
            if (archivo.buscarPosicionEmpleadoPorLegajo(legajo) != -1)
            {
                cout << "Que mes desea saber las horas trabajadas: ";
                cin >> mes;
                promedioPorLegajoYMes(legajo, mes);
            }
            else
            {
                cout << "El legajo no existe!!";
            }

            system("pause>nul");
            break;
        case 8:

            cout << "Que legajo desea saber las horas trabajadas: ";
            cin >> legajo;
            if (archivo.buscarPosicionEmpleadoPorLegajo(legajo) != -1)
            {
                cout << "Que anio desea saber las horas trabajadas: ";
                cin >> anio;
                promedioPorLegajoYAnio(legajo, anio);
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
    /*
        Empleados aux;
        EmpleadosArchivo archivo;
        int opcion, legajo = 0, anio = 0, mes = 0;
        while (true)
        {
            system("color 4");
            system("cls");
            cout << "MENU HORAS TRABAJADAS" << endl;

            cout << "\n\t1. Agregar registro" << endl;
            cout << "\n\t2. Mostrar registros (todos)" << endl;
            cout << "\n\t3. Mostrar registros (por Legajo)" << endl;
            cout << "\n\t4. Mostrar horas trabajadas (por Legajo)" << endl;
            cout << "\n\t5. Promedio general" << endl;
            cout << "\n\t6. Promedio total (por Legajo)" << endl;
            cout << "\n\t7. Promedio por mes (por Legajo)" << endl;
            cout << "\n\t8. Promedio por anio (por Legajo)" << endl;
            cout << "\n\t0. Volver al Menu Principal" << endl
                 << endl;

            cout << "\nSeleccione una opcion :  ";
            cin >> opcion;
            system("cls");
            switch (opcion)
            {

            case 1:
                agregarRegistros();
                break;

            case 2:
                mostrarRegistros();
                system("pause>nul");
                break;

            case 3:

                cout << "Que legajo desea saber las horas trabajadas: ";
                cin >> legajo;
                if (archivo.buscarPosicionEmpleadoPorLegajo(legajo) != -1)
                {
                    mostrarRegistrosPorLegajo(legajo);
                }
                else
                {
                    cout << "El legajo no existe!!";
                }
                system("pause>nul");

                break;

            case 4:

                cout << "Que legajo desea saber las horas trabajadas: ";
                cin >> legajo;
                if (archivo.buscarPosicionEmpleadoPorLegajo(legajo) != -1)
                {
                    sumaHorasPorLegajo(legajo);
                }
                else
                {
                    cout << "El legajo no existe!!";
                }

                system("pause>nul");
                break;

            case 5:
                promedioGeneral();
                system("pause>nul");
                break;

            case 6:

                cout << "Que legajo desea saber las horas trabajadas: ";
                cin >> legajo;
                if (archivo.buscarPosicionEmpleadoPorLegajo(legajo) != -1)
                {
                    promedioPorLegajo(legajo);
                }
                else
                {
                    cout << "El legajo no existe!!";
                }

                system("pause>nul");
                break;

            case 7:

                cout << "Que legajo desea saber las horas trabajadas: ";
                cin >> legajo;
                if (archivo.buscarPosicionEmpleadoPorLegajo(legajo) != -1)
                {
                    cout << "Que mes desea saber las horas trabajadas: ";
                    cin >> mes;
                    promedioPorLegajoYMes(legajo, mes);
                }
                else
                {
                    cout << "El legajo no existe!!";
                }

                system("pause>nul");
                break;

            case 8:

                cout << "Que legajo desea saber las horas trabajadas: ";
                cin >> legajo;
                if (archivo.buscarPosicionEmpleadoPorLegajo(legajo) != -1)
                {
                    cout << "Que anio desea saber las horas trabajadas: ";
                    cin >> anio;
                    promedioPorLegajoYAnio(legajo, anio);
                }
                else
                {
                    cout << "El legajo no existe!!";
                }

                system("pause>nul");
                break;

            case 0:
                return;
                system("pause>nul");
                break;
            default:
                cout << "OPCION INGRESADA INCORRECTA.";
                system("pause>nul");
                break;
            }
        }
         */
}

#include "SubmenuDisponibilidad.h"
#include "MenuLicencias.h"


/// En este menu modifico a los operarios activos y los agrego a la disponibilidad para rotacion
void subMenuDisponibilidad()
{
    // Le damos el nombre que quieramos al objeto
    Menu MenuDisponibilidad;
    // Agregamos el Titulo del menu
    MenuDisponibilidad.setTitulo("MENU CAMBIO DE DISPONIBILIDAD");
    // Agregamos la Opcion para salir o volver al menu anterior
    MenuDisponibilidad.setSalida(" Volver al Menu de Principal ");

    // AGREGAMOS LAS OPCIONES CON UNA FUNCION
    // OPCION 1
    MenuDisponibilidad.agregarOpcion("Listar Operarios Activos para rotacion");
    // OPCION 2
    MenuDisponibilidad.agregarOpcion("Confirmar disponibilidad");
    // OPCION 3
    MenuDisponibilidad.agregarOpcion("Eliminar disponibilidad");
    // OPCION 4
    MenuDisponibilidad.agregarOpcion("Licencia");

    // Aqui generamos un while en true en caso de que quieramos que dibuje nuevamente el menu
    while (true)
    {
        system("cls");
        // Elegimos el color del texto del menu y el Fondo del texto
        int opciones = MenuDisponibilidad.dibujarMenu(rlutil::COLOR::WHITE, rlutil::COLOR::GREEN);
        system("cls");
        switch (opciones)
        {
        case 1:
            listarOperariosDisponiblesParaRotar();
            system("pause>nul");
            break;

        case 2:
            disponible();
            system("pause>nul");
            break;

        case 3:
            NOdisponible();
            system("pause>nul");
            break;

        case 4:
            MenuLicencias();
            break;
        default:
            // VOLVER AL MENU ANTERIOR O SALIR
            return;
            break;
        }
    }
    /*
        int opcion;
        while (true)
        {
            system("color 2");
            system("cls");
            cout << "MENU CAMBIO DE DISPONIBILIDAD" << endl;

            cout << "\n\t1. Listar Operarios Activos para rotacion" << endl;
            cout << "\n\t2. Confirmar disponibilidad" << endl;
            cout << "\n\t3. Eliminar disponibilidad" << endl;
            cout << "\n\t4. Licencia" << endl;
            cout << "\n\t0. Volver al Menu Principal" << endl
                 << endl;

            cout << "\nSeleccione una opcion :  ";
            cin >> opcion;
            system("cls");
            switch (opcion)
            {

            case 1:
                listarOperariosDisponiblesParaRotar();
                system("pause>nul");
                break;

            case 2:
                disponible();
                system("pause>nul");
                break;

            case 3:
                NOdisponible();
                system("pause>nul");
                break;

            case 4:
                licencia();
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

#include <iostream>
using namespace std;
#include "Menu.h"
#include "submenus.h"

int main()
{
    // ELEGIMOS EL COLOR DE FONDO QUE DESEAMOS
    rlutil::setBackgroundColor(rlutil::COLOR::BLACK);
    // ELEGIMOS EL COLOR DEL TEXTO QUE DESEAMOS
    rlutil::setColor(rlutil::WHITE);
    // GUARDAMOS LOS COLORES PRINCIPALES DE LA CONSOLA
    rlutil::saveDefaultColor();
    // ESTO SOLO LO HARIAMOS EN EL MENU PRINCIPAL

    // Le damos el nombre que quieramos al objeto
    Menu principal;
    // Agregamos el Titulo del menu
    principal.setTitulo("MENU PRINCIPAL");
    // Agregamos la Opcion para salir o volver al menu anterior
    principal.setSalida("Salir del Programa");

    // AGREGAMOS LAS OPCIONES CON UNA FUNCION
    // OPCION 1
    principal.agregarOpcion("Cargar Operario nuevo");
    // OPCION 2
    principal.agregarOpcion("Modificar datos de Empleados");
    // OPCION 3
    principal.agregarOpcion("Modificar Disponibilidad para Rotacion");
    // OPCION 4
    principal.agregarOpcion("Armar Rotacion");
    // OPCION 5
    principal.agregarOpcion("Horas Trabajadas");
    //OPCION 6
    principal.agregarOpcion("Licencias");


    // Aqui generamos un while en true en caso de que quieramos que dibuje nuevamente el menu
    while (true)
    {
        system("cls");
        // Elegimos el color del texto del menu y el Fondo del texto
        int opciones = principal.dibujarMenu(rlutil::COLOR::WHITE, rlutil::COLOR::CYAN);
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
            /// menu licencias
            MenuLicencias();
            break;
        default:
            // VOLVER AL MENU ANTERIOR O SALIR
            return 0;
            break;
        }
    }
    /*
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
            cout << "\n\t0. Salir del Programa" << endl
                 << endl;
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
                // cargarDatosDeInicio();
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
         */
}
